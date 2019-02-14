/*
 * Copyright (c) 2017 Nordic Semiconductor ASA
 * Copyright (c) 2015 Runtime Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <flash_map.h>
#include <pm_config.h>

#define IMAGE_SIZE ((PM_CFG_APP_SIZE - PM_CFG_MCUBOOT_SCRATCH_SIZE - PM_CFG_MCUBOOT_STORAGE_SIZE)/2)

const struct flash_area default_flash_map[] = {
	{
		.fa_id = 0,
		.fa_off = PM_CFG_MCUBOOT_ADDRESS,
		.fa_dev_name = DT_FLASH_AREA_0_DEV,
		.fa_size = PM_CFG_MCUBOOT_SIZE,
	},{
		.fa_id = 1,
		.fa_off = PM_CFG_APP_ADDRESS,
		.fa_dev_name = DT_FLASH_AREA_0_DEV,
		.fa_size = IMAGE_SIZE,
	},{
		.fa_id = 2,
		.fa_off = PM_CFG_APP_ADDRESS + IMAGE_SIZE,
		.fa_dev_name = DT_FLASH_AREA_0_DEV,
		.fa_size = IMAGE_SIZE,
	},{
		.fa_id = 3,
		.fa_off = PM_CFG_MCUBOOT_SCRATCH_ADDRESS,
		.fa_dev_name = DT_FLASH_AREA_0_DEV,
		.fa_size = PM_CFG_MCUBOOT_SCRATCH_SIZE,
	},{
		.fa_id = 4,
		.fa_off = PM_CFG_MCUBOOT_STORAGE_ADDRESS,
		.fa_dev_name = DT_FLASH_AREA_0_DEV,
		.fa_size = PM_CFG_MCUBOOT_STORAGE_SIZE,
	},
};

const int flash_map_entries = ARRAY_SIZE(default_flash_map);
const struct flash_area *flash_map = default_flash_map;
