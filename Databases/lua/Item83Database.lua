rdb.fields = {
	{"id", TYPE_INT32},
	{"name_id", TYPE_INT32},
	{"type", TYPE_INT32},
	{"group", TYPE_INT32},
	{"class", TYPE_INT32},
	{"set_id", TYPE_INT32},
	{"set_part_flag", TYPE_INT32},
	{"grade", TYPE_INT8},
	{"rank", TYPE_INT32},
	{"level", TYPE_INT32},
	{"enhance", TYPE_INT32},
	{"socket", TYPE_INT32},
	{"status_flag", TYPE_INT32},
	{"job_depth", TYPE_INT8},
	{"use_min_level", TYPE_INT32},
	{"use_max_level", TYPE_INT32},
	{"target_min_level", TYPE_INT32},
	{"target_max_level", TYPE_INT32},
	{"range", TYPE_DECIMAL, MAKEINDEXEDVAR(2, 1)},
	{"weight", TYPE_FLOAT32},
	{"price", TYPE_INT32},
	{"huntaholic_point", TYPE_INT32},
	{"arena_point", TYPE_INT32 | TYPE_RDBIGNORE},
	{"ethereal_durability", TYPE_INT32},
	{"endurance", TYPE_INT32},
	{"wear_type", TYPE_INT32},
	{"nv0", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv1", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"limit_deva", TYPE_BIT},
	{"limit_asura", TYPE_BIT},
	{"limit_gaia", TYPE_BIT},
	{"nv2", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv3", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv4", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv5", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv6", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"limit_fighter", TYPE_BIT},
	{"limit_hunter", TYPE_BIT},
	{"limit_magician", TYPE_BIT},
	{"limit_summoner", TYPE_BIT},
	{"nv7", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv8", TYPE_BIT | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"nv9", TYPE_INT16 | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"item_use_flag", TYPE_INT32},
	{"item_use_flag2", TYPE_INT32 | TYPE_SQLIGNORE | TYPE_CSVIGNORE | TYPE_GUIIGNORE},
	{"material", TYPE_INT32},
	{"summon_id", TYPE_INT32},
	{"throw_range", TYPE_INT32},
	{"base_type_0", TYPE_INT16},
	{"base_type_1", TYPE_INT16},
	{"base_type_2", TYPE_INT16},
	{"base_type_3", TYPE_INT16},
	{"base_var1_0", TYPE_FLOAT64},
	{"base_var1_1", TYPE_FLOAT64},
	{"base_var1_2", TYPE_FLOAT64},
	{"base_var1_3", TYPE_FLOAT64},
	{"base_var2_0", TYPE_FLOAT64},
	{"base_var2_1", TYPE_FLOAT64},
	{"base_var2_2", TYPE_FLOAT64},
	{"base_var2_3", TYPE_FLOAT64},
	{"opt_type_0", TYPE_INT16},
	{"opt_type_1", TYPE_INT16},
	{"opt_type_2", TYPE_INT16},
	{"opt_type_3", TYPE_INT16},
	{"opt_var1_0", TYPE_FLOAT64},
	{"opt_var1_1", TYPE_FLOAT64},
	{"opt_var1_2", TYPE_FLOAT64},
	{"opt_var1_3", TYPE_FLOAT64},
	{"opt_var2_0", TYPE_FLOAT64},
	{"opt_var2_1", TYPE_FLOAT64},
	{"opt_var2_2", TYPE_FLOAT64},
	{"opt_var2_3", TYPE_FLOAT64},
	{"effect_id", TYPE_INT32},
	{"enhance_0_id", TYPE_INT16},
	{"enhance_1_id", TYPE_INT16},
	{"enhance_0_01", TYPE_FLOAT32},
	{"enhance_0_02", TYPE_FLOAT32},
	{"enhance_0_03", TYPE_FLOAT32},
	{"enhance_0_04", TYPE_FLOAT32},
	{"enhance_1_01", TYPE_FLOAT32},
	{"enhance_1_02", TYPE_FLOAT32},
	{"enhance_1_03", TYPE_FLOAT32},
	{"enhance_1_04", TYPE_FLOAT32},
	{"skill_id", TYPE_INT32},
	{"state_id", TYPE_INT32},
	{"state_level", TYPE_INT32},
	{"state_time", TYPE_INT32},
	{"cool_time", TYPE_INT32},
	{"cool_time_group", TYPE_INT16},
	{"available_period", TYPE_INT32},
	{"decrease_type", TYPE_INT16},
	{"unknownValue1", TYPE_INT16 | TYPE_SQLIGNORE | TYPE_CSVIGNORE},
	{"model_type_dem", TYPE_INT32},
	{"model_type_def", TYPE_INT32},
	{"model_type_asm", TYPE_INT32},
	{"model_type_asf", TYPE_INT32},
	{"model_type_gam", TYPE_INT32},
	{"model_type_gaf", TYPE_INT32},
	{"deco_model_change", TYPE_INT8},
	{"model_00", TYPE_CHAR, 256},
	{"model_01", TYPE_CHAR, 256},
	{"model_02", TYPE_CHAR, 256},
	{"model_03", TYPE_CHAR, 256},
	{"model_04", TYPE_CHAR, 256},
	{"model_05", TYPE_CHAR, 256},
	{"model_06", TYPE_CHAR, 256},
	{"model_07", TYPE_CHAR, 256},
	{"model_08", TYPE_CHAR, 256},
	{"model_09", TYPE_CHAR, 256},
	{"model_10", TYPE_CHAR, 256},
	{"model_11", TYPE_CHAR, 256},
	{"model_12", TYPE_CHAR, 256},
	{"model_13", TYPE_CHAR, 256},
	{"model_14", TYPE_CHAR, 256},
	{"model_15", TYPE_CHAR, 256},
	{"model_16", TYPE_CHAR, 256},
	{"model_17", TYPE_CHAR, 256},
	{"texture_filename", TYPE_CHAR, 256},
	{"drop_type", TYPE_CHAR, 256},
	{"unkCatValue", TYPE_CHAR | TYPE_SQLIGNORE | TYPE_CSVIGNORE | TYPE_GUIIGNORE, 3},
	{"icon_id", TYPE_INT32},
	{"icon_file_name", TYPE_CHAR, 256},
	{"script_text", TYPE_CHAR, 512},
	{"tooltip_id", TYPE_INT32},
	{"group_bit_set", TYPE_INT32},
}

rdb.sqlColumnOrder = table.concat({
	"id\0",
	"name_id\0",
	"tooltip_id\0",
	"type\0",
	"group\0",
	"class\0",
	"wear_type\0",
	"set_id\0",
	"set_part_flag\0",
	"grade\0",
	"rank\0",
	"level\0",
	"enhance\0",
	"socket\0",
	"status_flag\0",
	"limit_deva\0",
	"limit_asura\0",
	"limit_gaia\0",
	"job_depth\0",
	"limit_fighter\0",
	"limit_hunter\0",
	"limit_magician\0",
	"limit_summoner\0",
	"use_min_level\0",
	"use_max_level\0",
	"target_min_level\0",
	"target_max_level\0",
	"range\0",
	"weight\0",
	"price\0",
	"huntaholic_point\0",
	"arena_point\0",
	"ethereal_durability\0",
	"endurance\0",
	"material\0",
	"summon_id\0",
	"item_use_flag\0",
	"available_period\0",
	"decrease_type\0",
	"throw_range\0",
	"base_type_0\0",
	"base_var1_0\0",
	"base_var2_0\0",
	"base_type_1\0",
	"base_var1_1\0",
	"base_var2_1\0",
	"base_type_2\0",
	"base_var1_2\0",
	"base_var2_2\0",
	"base_type_3\0",
	"base_var1_3\0",
	"base_var2_3\0",
	"opt_type_0\0",
	"opt_var1_0\0",
	"opt_var2_0\0",
	"opt_type_1\0",
	"opt_var1_1\0",
	"opt_var2_1\0",
	"opt_type_2\0",
	"opt_var1_2\0",
	"opt_var2_2\0",
	"opt_type_3\0",
	"opt_var1_3\0",
	"opt_var2_3\0",
	"effect_id\0",
	"enhance_0_id\0",
	"enhance_0_01\0",
	"enhance_0_02\0",
	"enhance_0_03\0",
	"enhance_0_04\0",
	"enhance_1_id\0",
	"enhance_1_01\0",
	"enhance_1_02\0",
	"enhance_1_03\0",
	"enhance_1_04\0",
	"skill_id\0",
	"state_id\0",
	"state_level\0",
	"state_time\0",
	"cool_time\0",
	"cool_time_group\0",
	"model_type_dem\0",
	"model_type_def\0",
	"model_type_asm\0",
	"model_type_asf\0",
	"model_type_gam\0",
	"model_type_gaf\0",
	"deco_model_change\0",
	"model_00\0",
	"model_01\0",
	"model_02\0",
	"model_03\0",
	"model_04\0",
	"model_05\0",
	"model_06\0",
	"model_07\0",
	"model_08\0",
	"model_09\0",
	"model_10\0",
	"model_11\0",
	"model_12\0",
	"model_13\0",
	"model_14\0",
	"model_15\0",
	"model_16\0",
	"model_17\0",
	"texture_filename\0",
	"drop_type\0",
	"icon_id\0",
	"icon_file_name\0",
	"script_text\0",
	"unknownValue2\0",
})

-- Data values by Ne0@NCarbon
local arena_point_table = {
	[1100103] = 20,
	[3800209] = 80,
	[3800210] = 80,
	[3800211] = 80,
	[3800201] = 90,
	[3800202] = 90,
	[3800203] = 110,
	[3800204] = 110,
	[3800205] = 110,
	[3800206] = 110,
	[3800207] = 110,
	[3800208] = 110,
	[3800229] = 6250,
	[3800241] = 6250,
	[3800253] = 6250,
	[693030]  = 6817,
	[693031]  = 6817,
	[693032]  = 6817,
	[693033]  = 6817,
	[693034]  = 6817,
	[3800242] = 8520,
	[3800230] = 8520,
	[3800254] = 8520,
	[3800240] = 11360,
	[3800252] = 11360,
	[3800228] = 11360,
	[3800257] = 18750,
	[3800245] = 18750,
	[3800233] = 18750,
	[3800255] = 19310,
	[3800243] = 19310,
	[3800231] = 19310,
	[3800234] = 25560,
	[3800258] = 25560,
	[3800246] = 25560,
	[3800256] = 34080,
	[3800244] = 34080,
	[3800232] = 34080,
	[3800264] = 56810,
	[3800259] = 57940,
	[3800247] = 57940,
	[3800235] = 57940,
	[3800265] = 78400,
	[3800261] = 93730,
	[3800237] = 93730,
	[3800249] = 93730,
	[3800250] = 127820,
	[3800238] = 127820,
	[3800262] = 127820,
	[3800248] = 170420,
	[3800260] = 170420,
	[3800236] = 170420,
	[3800001] = 227230,
	[3800002] = 227230,
	[3800003] = 227230,
	[3800004] = 227230,
	[3800005] = 227230,
	[3800239] = 289720,
	[3800251] = 289720,
	[3800263] = 289720,
	[3800101] = 1136160
}

rdb.convertData = function (dst, mode, row, rowNum)
	if mode == DCT_Read and dst ~= DF_RDB then
		row.unkCatValue = "Cat"
		row.item_use_flag2 = row.item_use_flag
		row.unknownValue1 = 49

		for i = 0,9 do
			row[string.format("nv%d", i)] = 0
		end
	elseif mode == DCT_Read and dst == DF_RDB then
		if arena_point_table[row.id] then
			row.arena_point = arena_point_table[row.id]
		else
			row.arena_point = 0
		end
	end
end
