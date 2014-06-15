#include "IRowManipulator.h"
#include "DataType.h"
#include "ExportDLL.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static FieldDescriptor df[] =
	{{1, TYPE_INT32, "id"},
	 {1, TYPE_INT32, "name_id"},
	 {1, TYPE_INT32, "local_flag"},
	 {1, TYPE_INT32, "hunting_period"},
	 {1, TYPE_INT32, "objective_point"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "max_point"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "lobby_channel_id"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "lobby_x"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "lobby_y"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "dungeon_channel_id"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "dungeon_x"},
	 {1, TYPE_INT32 | TYPE_RDBIGNORE, "dungeon_y"}};

#pragma comment(linker, "/EXPORT:registerDBStructure=_registerDBStructure@8")
void EDATABASEDLL DLLCALLCONV registerDBStructure(FieldDescriptor **dfmPtr, int *sizePtr) {
	*dfmPtr = df;
	*sizePtr = sizeof(df) / sizeof(FieldDescriptor);
}

#pragma comment(linker, "/EXPORT:convertData=_convertData@16")
void EDATABASEDLL DLLCALLCONV convertData(eDataFormat dst, eDataConvertionType mode, IRowManipulator *row, unsigned int rowNum) {
	if(mode == DCT_Read && dst == DF_RDB) {
		*static_cast<int*>(row->getValuePtr("max_point")) = 6000;
		*static_cast<int*>(row->getValuePtr("lobby_channel_id")) = 300011;
		*static_cast<int*>(row->getValuePtr("lobby_x")) = 83719;
		*static_cast<int*>(row->getValuePtr("lobby_y")) = 2544;
		*static_cast<int*>(row->getValuePtr("dungeon_channel_id")) = 300000;
		*static_cast<int*>(row->getValuePtr("dungeon_x")) = 88935;
		*static_cast<int*>(row->getValuePtr("dungeon_y")) = 8622;
	}
}

#pragma comment(linker, "/EXPORT:getDefaultFileName=_getDefaultFileName@0")
EDATABASEDLL const char*  DLLCALLCONV getDefaultFileName() {
	return "db_huntaholicresource";
}

#ifdef __cplusplus
}
#endif

