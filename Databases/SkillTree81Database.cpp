#include "DataType.h"
#include "ExportDLL.h"
#include "SpecialDatabaseRules.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// Fixme: special behavior for this (double for)

static FieldDescriptor df[] = {{1, TYPE_INT32 | TYPE_FLAG_SORT, "job_id"},
                               {1, TYPE_INT32, "skill_id"},
                               {1, TYPE_INT32, "min_skill_lv"},
                               {1, TYPE_INT32, "max_skill_lv"},
                               {1, TYPE_INT32, "lv"},
                               {1, TYPE_INT32, "job_lv"},
                               {1, TYPE_FLOAT32, "jp_ratio"},
                               {1, TYPE_INT32, "need_skill_id_1"},
                               {1, TYPE_INT32, "need_skill_id_2"},
                               {1, TYPE_INT32, "need_skill_id_3"},
                               {1, TYPE_INT32, "need_skill_lv_1"},
                               {1, TYPE_INT32, "need_skill_lv_2"},
                               {1, TYPE_INT32, "need_skill_lv_3"},
                               {1, TYPE_INT32, "cenhance_min"},
                               {1, TYPE_INT32, "cenhance_max"}};

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:registerDBStructure=_registerDBStructure@8")
#endif
void EDATABASEDLL DLLCALLCONV registerDBStructure(FieldDescriptor** dfmPtr, int* sizePtr) {
	*dfmPtr = df;
	*sizePtr = sizeof(df) / sizeof(FieldDescriptor);
}

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:getSQLColumnOrder=_getSQLColumnOrder@0")
#endif
EDATABASEDLL const char* DLLCALLCONV getSQLColumnOrder() {
	return "job_id\0"
	       "skill_id\0"
	       "min_skill_lv\0"
	       "max_skill_lv\0"
	       "lv\0"
	       "job_lv\0"
	       "jp_ratio\0"
	       "need_skill_id_1\0"
	       "need_skill_lv_1\0"
	       "need_skill_id_2\0"
	       "need_skill_lv_2\0"
	       "need_skill_id_3\0"
	       "need_skill_lv_3\0"
	       "cenhance_min\0"
	       "cenhance_max\0";
}

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:getSpecialCaseID=_getSpecialCaseID@0")
#endif
int EDATABASEDLL DLLCALLCONV getSpecialCaseID() {
	return SPECIALCASE_DOUBLEFORRDB;
}

#ifdef __cplusplus
}
#endif
