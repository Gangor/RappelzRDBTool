#include "IRowManipulator.h"
#include "DataType.h"
#include "ExportDLL.h"
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static FieldDescriptor df[] =
	{{1, TYPE_INT32, "motion_id"},
	 {1, TYPE_INT32, "race_id"},
	 {1, TYPE_INT32, "sex"},
	 {256, TYPE_CHAR, "file_name"},
	 {1, TYPE_INT32, "frame_length"},
	 {1, TYPE_INT32, "play_speed"},
	 {1, TYPE_INT32, "graphic_effect_file_ID"},
	 {1, TYPE_INT32, "graphic_effect_speed_type"},
	 {1, TYPE_INT32, "graphic_effect_position"},
	 {1, TYPE_INT8, "graphic_effect_follow"},
	 {1, TYPE_INT8, "graphic_effect_disappear"},
	 {1, TYPE_INT16 | TYPE_SQLIGNORE | TYPE_CSVIGNORE, "padding0"},
	 {1, TYPE_INT32, "sound_file_ID"},
	 {1, TYPE_INT32, "sound_volumn"},
	 {1, TYPE_INT32, "sound_play_probability"},
	 {1, TYPE_INT32, "sound_timing"},
	 {1, TYPE_INT8, "sound_reverb_apply"},
	 {1, TYPE_INT8, "sound_filter_apply"},
	 {1, TYPE_INT8, "sound_stereo_apply"},
	 {1, TYPE_INT8 | TYPE_SQLIGNORE | TYPE_CSVIGNORE, "padding1"},
	 {1, TYPE_INT32, "fx_id"},
	 {1, TYPE_INT32, "fx_timing"},
	 {1, TYPE_INT32, "fx_position"},
	 {1, TYPE_INT32, "fx_play_speed"},
	 {1, TYPE_INT32, "event01_id"},
	 {1, TYPE_INT32, "event01_timing"},
	 {1, TYPE_INT32, "event02_id"},
	 {1, TYPE_INT32, "event02_timing"},
	 {1, TYPE_INT32, "event03_id"},
	 {1, TYPE_INT32, "event03_timing"},
	 {1, TYPE_INT32, "event04_id"},
	 {1, TYPE_INT32, "event04_timing"},
	 {1, TYPE_INT32, "event05_id"},
	 {1, TYPE_INT32, "event05_timing"},
	 {1, TYPE_INT32, "event06_id"},
	 {1, TYPE_INT32, "event06_timing"},
	 {1, TYPE_INT32, "event07_id"},
	 {1, TYPE_INT32, "event07_timing"},
	 {1, TYPE_INT32, "event08_id"},
	 {1, TYPE_INT32, "event08_timing"},
	 {1, TYPE_INT32, "event09_id"},
	 {1, TYPE_INT32, "event09_timing"},
	 {1, TYPE_INT32, "event10_id"},
	 {1, TYPE_INT32, "event10_timing"}};

#pragma comment(linker, "/EXPORT:registerDBStructure=_registerDBStructure@8")
void EDATABASEDLL DLLCALLCONV registerDBStructure(FieldDescriptor **dfmPtr, int *sizePtr) {
	*dfmPtr = df;
	*sizePtr = sizeof(df) / sizeof(FieldDescriptor);
}

#pragma comment(linker, "/EXPORT:convertData=_convertData@16")
void EDATABASEDLL DLLCALLCONV convertData(eDataFormat dst, eDataConvertionType mode, IRowManipulator *row, unsigned int rowNum) {
	if(mode == DCT_Read && (dst == DF_CSV || dst == DF_SQL)) {
		*static_cast<short*>(row->getValuePtr("padding0")) = 103;
		*static_cast<char*>(row->getValuePtr("padding1")) = 0;
	}
}

#pragma comment(linker, "/EXPORT:getDefaultTableName=_getDefaultTableName@0")
EDATABASEDLL const char*  DLLCALLCONV getDefaultTableName() {
	return "CharacterMotion";
}

#ifdef __cplusplus
}
#endif

