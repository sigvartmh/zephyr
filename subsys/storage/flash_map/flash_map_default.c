/*
 * Copyright (c) 2017 Nordic Semiconductor ASA
 * Copyright (c) 2015 Runtime Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <flash_map.h>

#define FLASH_AREA_FOO(i, _)				\
	{.fa_id = i,					\
	 .fa_off = DT_FLASH_AREA_##i##_OFFSET,		\
	 .fa_dev_name = DT_FLASH_AREA_##i##_DEV,	\
	 .fa_size = DT_FLASH_AREA_##i##_SIZE,},

#include <pm_config.h>
#define SLOT_SIZE (PM_CFG_APP_SIZE / 2)
#define FLASH_AREA_IMAGE_0_OFFSET (PM_CFG_APP_ADDRESS)
#define FLASH_AREA_IMAGE_0_SIZE SLOT_SIZE
#define FLASH_AREA_IMAGE_1_OFFSET FLASH_AREA_IMAGE_0_OFFSET + FLASH_AREA_IMAGE_0_SIZE
#define FLASH_AREA_IMAGE_1_SIZE FLASH_AREA_IMAGE_0_SIZE
#define FLASH_AREA_IMAGE_SCRATCH_OFFSET PM_CFG_MCUBOOT_SCRATCH_ADDRESS
#define FLASH_AREA_IMAGE_SCRATCH_SIZE PM_CFG_MCUBOOT_SCRATCH_SIZE
#define FLASH_AREA_IMAGE_STORAGE_OFFSET PM_CFG_MCUBOOT_STORAGE_ADDRESS
#define FLASH_AREA_IMAGE_STORAGE_SIZE PM_CFG_MCUBOOT_STORAGE_SIZE
#define FLASH_AREA_MCUBOOT_OFFSET PM_CFG_MCUBOOT_ADDRESS
#define FLASH_AREA_MCUBOOT_SIZE PM_CFG_MCUBOOT_SIZE

const struct flash_area default_flash_map[] = {
	UTIL_LISTIFY(DT_FLASH_AREA_NUM, FLASH_AREA_FOO, ~)
};

const int flash_map_entries = ARRAY_SIZE(default_flash_map);
const struct flash_area *flash_map = default_flash_map;
