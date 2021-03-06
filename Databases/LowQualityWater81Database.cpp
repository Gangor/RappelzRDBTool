#include "DataType.h"
#include "ExportDLL.h"
#include "IRowManipulator.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static FieldDescriptor df[] = {{1, TYPE_INT32, "id"},
                               {1, TYPE_INT32, "texture_change_time"},
                               {1, TYPE_INT32, "a"},
                               {1, TYPE_INT32, "r"},
                               {1, TYPE_INT32, "g"},
                               {1, TYPE_INT32, "b"},
                               {256, TYPE_CHAR, "texture_name_1"},
                               {256, TYPE_CHAR, "texture_name_2"},
                               {256, TYPE_CHAR, "texture_name_3"},
                               {256, TYPE_CHAR, "texture_name_4"},
                               {256, TYPE_CHAR, "texture_name_5"},
                               {256, TYPE_CHAR, "texture_name_6"},
                               {256, TYPE_CHAR, "texture_name_7"},
                               {256, TYPE_CHAR, "texture_name_8"},
                               {256, TYPE_CHAR, "texture_name_9"},
                               {256, TYPE_CHAR, "texture_name_10"},
                               {256, TYPE_CHAR, "texture_name_11"},
                               {256, TYPE_CHAR, "texture_name_12"},
                               {256, TYPE_CHAR, "texture_name_13"},
                               {256, TYPE_CHAR, "texture_name_14"},
                               {256, TYPE_CHAR, "texture_name_15"},
                               {256, TYPE_CHAR, "texture_name_16"},
                               {256, TYPE_CHAR, "texture_name_17"},
                               {256, TYPE_CHAR, "texture_name_18"},
                               {256, TYPE_CHAR, "texture_name_19"},
                               {256, TYPE_CHAR, "texture_name_20"},
                               {256, TYPE_CHAR, "texture_name_21"},
                               {256, TYPE_CHAR, "texture_name_22"},
                               {256, TYPE_CHAR, "texture_name_23"},
                               {256, TYPE_CHAR, "texture_name_24"},
                               {256, TYPE_CHAR, "texture_name_25"},
                               {256, TYPE_CHAR, "texture_name_26"},
                               {256, TYPE_CHAR, "texture_name_27"},
                               {256, TYPE_CHAR, "texture_name_28"},
                               {256, TYPE_CHAR, "texture_name_29"},
                               {256, TYPE_CHAR, "texture_name_30"},
                               {4 * 30, TYPE_CHAR | TYPE_SQLIGNORE | TYPE_CSVIGNORE | TYPE_GUIIGNORE, "nulValues"}};

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:registerDBStructure=_registerDBStructure@8")
#endif
void EDATABASEDLL DLLCALLCONV registerDBStructure(FieldDescriptor** dfmPtr, int* sizePtr) {
	*dfmPtr = df;
	*sizePtr = sizeof(df) / sizeof(FieldDescriptor);
}

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:getDefaultTableName=_getDefaultTableName@0")
#endif
EDATABASEDLL const char* DLLCALLCONV getDefaultTableName() {
	return "LowQualityWater";
}

#ifdef __cplusplus
}
#endif
