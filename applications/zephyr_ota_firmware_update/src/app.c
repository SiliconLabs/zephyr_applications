/***************************************************************************//**
 * @file app.c
 * @brief app source file.
 *******************************************************************************
 * # License
 * <b>Copyright 2023 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided \'as-is\', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *******************************************************************************
 * # EXPERIMENTAL QUALITY
 * This code has not been formally tested and is provided as-is. It is not
 * suitable for production environments. In addition, this code will not be
 * maintained and there may be no bug maintenance planned for these resources.
 * Silicon Labs may update projects from time to time.
 ******************************************************************************/

#include <zephyr/kernel.h>
#include <zephyr/stats/stats.h>

#ifdef CONFIG_MCUMGR_GRP_FS
#include <zephyr/device.h>
#include <zephyr/fs/fs.h>
#include <zephyr/fs/littlefs.h>
#endif
#ifdef CONFIG_MCUMGR_GRP_STAT
#include <zephyr/mgmt/mcumgr/grp/stat_mgmt/stat_mgmt.h>
#endif

#define LOG_LEVEL               LOG_LEVEL_DBG
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

#include "app.h"

#define STORAGE_PARTITION_LABEL storage_partition
#define STORAGE_PARTITION_ID    FIXED_PARTITION_ID(STORAGE_PARTITION_LABEL)

/* Define an example stats group; approximates seconds since boot. */
STATS_SECT_START(smp_svr_stats)
STATS_SECT_ENTRY(ticks)
STATS_SECT_END;

/* Assign a name to the `ticks` stat. */
STATS_NAME_START(smp_svr_stats)
STATS_NAME(smp_svr_stats, ticks)
STATS_NAME_END(smp_svr_stats);

/* Define an instance of the stats group. */
STATS_SECT_DECL(smp_svr_stats) smp_svr_stats;

#ifdef CONFIG_MCUMGR_GRP_FS
FS_LITTLEFS_DECLARE_DEFAULT_CONFIG(cstorage);
static struct fs_mount_t littlefs_mnt = {
  .type = FS_LITTLEFS,
  .fs_data = &cstorage,
  .storage_dev = (void *)STORAGE_PARTITION_ID,
  .mnt_point = "/lfs1"
};
#endif

void app_init(void)
{
  int rc;
  rc = STATS_INIT_AND_REG(smp_svr_stats, STATS_SIZE_32,
                          "smp_svr_stats");

  if (rc < 0) {
    LOG_ERR("[Error]: initializing stats system [%d]", rc);
  }
#ifdef CONFIG_MCUMGR_GRP_FS
  rc = fs_mount(&littlefs_mnt);
  if (rc < 0) {
    LOG_ERR("[Error]: mounting littlefs [%d]", rc);
  }
#endif

#ifdef CONFIG_MCUMGR_TRANSPORT_BT
  start_smp_bluetooth_adverts();
#endif
  LOG_INF("Build Time: " __DATE__ " " __TIME__);
}

void app_process_action(void)
{
  k_sleep(K_MSEC(1000));
  STATS_INC(smp_svr_stats, ticks);
}
