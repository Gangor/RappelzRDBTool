#include "DataType.h"
#include "ExportDLL.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static FieldDescriptor df[] = {{1, TYPE_INT32, "texture_group_id"},
                               {1, TYPE_INT32, "texture_id"},
                               {256, TYPE_CHAR, "deva_male"},
                               {1, TYPE_INT32, "deva_male_icon_id"},
                               {256, TYPE_CHAR, "deva_female"},
                               {1, TYPE_INT32, "deva_female_icon_id"},
                               {256, TYPE_CHAR, "asura_male"},
                               {1, TYPE_INT32, "asura_male_icon_id"},
                               {256, TYPE_CHAR, "asura_female"},
                               {1, TYPE_INT32, "asura_female_icon_id"},
                               {256, TYPE_CHAR, "gaia_male"},
                               {1, TYPE_INT32, "gaia_male_icon_id"},
                               {256, TYPE_CHAR, "gaia_female"},
                               {1, TYPE_INT32, "gaia_female_icon_id"}};

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:registerDBStructure=_registerDBStructure@8")
#endif
void EDATABASEDLL DLLCALLCONV registerDBStructure(FieldDescriptor** dfmPtr, int* sizePtr) {
	*dfmPtr = df;
	*sizePtr = sizeof(df) / sizeof(FieldDescriptor);
}

#ifndef _WIN64
#pragma comment(linker, "/EXPORT:getDefaultFileName=_getDefaultFileName@0")
#endif
EDATABASEDLL const char* DLLCALLCONV getDefaultFileName() {
	return "db_defaulttextureresource";
}

#ifdef __cplusplus
}
#endif
