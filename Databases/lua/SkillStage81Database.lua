rdb.fields = {
	{"id", TYPE_INT32},
	{"elemental", TYPE_INT8},
	{"type", TYPE_INT8},
	{"deal_damage", TYPE_INT8},
	{"has_target", TYPE_INT8},
	{"corpse_target", TYPE_INT8},
	{"is_toggle", TYPE_INT8},
	{"unknown0", TYPE_INT16 | TYPE_SQLIGNORE},
	{"casting_time", TYPE_FLOAT32},
	{"is_creature_skill", TYPE_INT16},
	{"unknown1", TYPE_INT16 | TYPE_SQLIGNORE},
	{"stage_type_id", TYPE_INT32},
	{"casting_type_id", TYPE_INT32},
	{"casting_start_motion_id", TYPE_INT32},
	{"casting_middle_motion_id", TYPE_INT32},
	{"casting_fx_set_id", TYPE_INT32},
	{"fire_motion_id", TYPE_INT32},
	{"fire_fx_set_id", TYPE_INT32},
	{"stage_data_01", TYPE_FLOAT32},
	{"stage_data_02", TYPE_FLOAT32},
	{"stage_data_03", TYPE_FLOAT32},
	{"stage_data_04", TYPE_FLOAT32},
	{"stage_data_05", TYPE_FLOAT32},
	{"stage_data_06", TYPE_FLOAT32},
	{"stage_data_07", TYPE_FLOAT32},
	{"stage_data_08", TYPE_FLOAT32},
	{"stage_data_09", TYPE_FLOAT32},
	{"stage_data_10", TYPE_FLOAT32},
	{"stage_data_11", TYPE_FLOAT32},
	{"stage_data_12", TYPE_FLOAT32},
	{"stage_data_13", TYPE_FLOAT32},
	{"stage_data_14", TYPE_FLOAT32},
	{"stage_data_15", TYPE_FLOAT32},
	{"stage_data_16", TYPE_FLOAT32},
	{"stage_data_17", TYPE_FLOAT32},
	{"stage_data_18", TYPE_FLOAT32},
	{"stage_data_19", TYPE_FLOAT32},
	{"stage_data_20", TYPE_FLOAT32},
	{"sub_stage_on_hit_id", TYPE_INT32},
	{"sub_stage_on_hit_continuous", TYPE_INT32},
	{"hit_fx_output_delay", TYPE_INT32},
	{"hit_fx_set_id", TYPE_INT32},
	{"hit_fx_set_position_id", TYPE_INT32},
	{"fire_fx_output_delay", TYPE_INT32},
	{"sub_fire_fx_set_id", TYPE_INT32},
	{"sub_fire_fx_position", TYPE_INT32},
}

rdb.defaultTableName = "SkillStage"

rdb.convertData = function (dst, mode, row, rowNum)
	if mode == DCT_Read and dst == DF_SQL then
		row.unknown0 = 163
		row.unknown1 = 0
	end
end
