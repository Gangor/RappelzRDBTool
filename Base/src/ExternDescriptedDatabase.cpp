#include "ExternDescriptedDatabase.h"
#include "Log.h"
#include "SpecialDatabaseRules.h"
#include <algorithm>
#include <errno.h>
#include <string.h>
#include <time.h>

#ifdef __linux__
#include <dlfcn.h>
#else
#include <windows.h>
#endif

#include <stdio.h>

namespace RappelzRDBBase {

ExternDescriptedDatabase::ExternDescriptedDatabase() {}

int ExternDescriptedDatabase::open(const char* databaseName, int* systemError) {
	int dummy;
	if(!systemError)
		systemError = &dummy;
	*systemError = 0;

#ifdef __unix__
	libHinst = (unsigned long long) dlopen(databaseName, RTLD_NOW);
	if(!libHinst) {
		*systemError = errno;
		getLogger()->log(
		    ILog::LL_Error, "Unable to load Database description DLL %s, last error: %s\n", databaseName, dlerror());
		return ENOENT;
	}
#else
	libHinst = (unsigned long long) LoadLibrary(databaseName);
	if(!libHinst) {
		*systemError = GetLastError();
		getLogger()->log(ILog::LL_Error,
		                 "Unable to load Database description DLL %s, last error: 0x%08x\n",
		                 databaseName,
		                 *systemError);
		return ENOENT;
	}
#endif

	DLLregisterDBStructure = (DLLREGISTERSTRUCTPROC) getProcAddress("registerDBStructure", 8);
	DLLgetSQLColumnOrder = (DLLSQLORDERPROC) getProcAddress("getSQLColumnOrder", 0);
	DLLgetCSVColumnOrder = (DLLCSVORDERPROC) getProcAddress("getCSVColumnOrder", 0);
	DLLconvertData = (DLLCONVERTDATAPROC) getProcAddress("convertData", 16);
	DLLgetSpecialCaseID = (DLLISSPECIALPROC) getProcAddress("getSpecialCaseID", 0);
	DLLgetDefaultFileName = (DLLDEFAULTFILENAMEPROC) getProcAddress("getDefaultFileName", 0);
	DLLgetDefaultTableName = (DLLDEFAULTTABLENAMEPROC) getProcAddress("getDefaultTableName", 0);
	DLLgetRdbDate = (DLLRDBDATEPROC) getProcAddress("getRdbDate", 0);

	if(DLLregisterDBStructure == 0) {
#ifdef __unix__
		dlclose((void*) libHinst);
#else
		FreeLibrary((HINSTANCE) libHinst);
#endif
		getLogger()->log(ILog::LL_Error,
		                 "ExternDescriptedDatabase: %s is not a database description DLL (no function "
		                 "registerDBStructure found in DLL)\n",
		                 databaseName,
		                 strerror(errno));
		return EINVAL;
	}

	filename = databaseName;

	return 0;
}

ExternDescriptedDatabase::~ExternDescriptedDatabase() {
	if(libHinst) {
#ifdef __unix__
		dlclose((void*) libHinst);
#else
		FreeLibrary((HINSTANCE) libHinst);
#endif
	}
}

void ExternDescriptedDatabase::registerDBStructure(FieldDescriptor** dfm, int* size) {
	DLLregisterDBStructure(dfm, size);
}

const char* ExternDescriptedDatabase::getSQLColumnOrder() {
	if(DLLgetSQLColumnOrder)
		return DLLgetSQLColumnOrder();
	else
		return NULL;
}

const char* ExternDescriptedDatabase::getCSVColumnOrder() {
	if(DLLgetCSVColumnOrder)
		return DLLgetCSVColumnOrder();
	else
		return NULL;
}

void ExternDescriptedDatabase::convertData(eDataFormat dst,
                                           eDataConvertionType mode,
                                           IRowManipulator* row,
                                           unsigned int rowNum) {
	if(DLLconvertData) {
		DLLconvertData(dst, mode, row, rowNum);
	}
}

int ExternDescriptedDatabase::getSpecialCaseID() {
	if(DLLgetSpecialCaseID)
		return DLLgetSpecialCaseID();
	else
		return SPECIALCASE_NONE;
}

const char* ExternDescriptedDatabase::getFilename() {
	return filename.c_str();
}

const char* ExternDescriptedDatabase::getDefaultFileName() {
	if(DLLgetDefaultFileName)
		return DLLgetDefaultFileName();

	if(fallbackDefaultFileName.size() > 0)
		return fallbackDefaultFileName.c_str();

	size_t endPos = filename.find("Database.");
	if(endPos == std::string::npos)
		endPos = filename.find_last_of('.');
	if(endPos == std::string::npos)
		endPos = filename.size();

	// Discard version number
	while(endPos > 0 && isdigit(filename.at(endPos - 1)))
		endPos--;

	size_t beginPos = filename.find_last_of("/\\");

	if(beginPos == std::string::npos || beginPos > endPos)
		beginPos = 0;
	else
		beginPos++;

	fallbackDefaultFileName = std::string("db_") + filename.substr(beginPos, endPos - beginPos);

	auto begin = fallbackDefaultFileName.begin() + 3;
	auto end = fallbackDefaultFileName.end();
	std::transform(begin, end, begin, ::tolower);

	return fallbackDefaultFileName.c_str();
}

const char* ExternDescriptedDatabase::getDefaultTableName() {
	if(DLLgetDefaultTableName)
		return DLLgetDefaultTableName();

	if(fallbackDefaultTableName.size() > 0)
		return fallbackDefaultTableName.c_str();

	size_t endPos = filename.find("Database.");
	if(endPos == std::string::npos)
		endPos = filename.find_last_of('.');
	if(endPos == std::string::npos)
		endPos = filename.size();

	// Discard version number
	while(endPos > 0 && isdigit(filename.at(endPos - 1)))
		endPos--;

	size_t beginPos = filename.find_last_of("/\\");

	if(beginPos == std::string::npos || beginPos > endPos)
		beginPos = 0;
	else
		beginPos++;

	fallbackDefaultTableName = filename.substr(beginPos, endPos - beginPos) + "Resource";

	return fallbackDefaultTableName.c_str();
}

uint64_t ExternDescriptedDatabase::getRdbDate(eDataFormat dst, eDataConvertionType mode, uint64_t originalDate) {
	if(DLLgetRdbDate)
		return DLLgetRdbDate(dst, mode, originalDate);
	else
		return originalDate;
}

void* ExternDescriptedDatabase::getProcAddress(const char* name, int argumentsBytes) {
	void* procAddress;

	procAddress = nativeGetProcAddress(libHinst, name);
	if(procAddress)
		return procAddress;

	char* buffer = (char*) alloca(strlen(name) + 10);

	sprintf(buffer, "%s@%d", name, argumentsBytes);
	procAddress = nativeGetProcAddress(libHinst, buffer);
	if(procAddress)
		return procAddress;

	sprintf(buffer, "_%s@%d", name, argumentsBytes);
	procAddress = nativeGetProcAddress(libHinst, buffer);

	return procAddress;
}

void* ExternDescriptedDatabase::nativeGetProcAddress(unsigned long long handle, const char* name) {
#ifdef __unix__
	return dlsym((void*) handle, name);
#else
	return GetProcAddress((HINSTANCE) handle, name);
#endif
}

}  // namespace RappelzRDBBase
