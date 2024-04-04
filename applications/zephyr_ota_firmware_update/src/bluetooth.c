/***************************************************************************//**
 * @file bluetooth.c
 * @brief bluetooth source file.
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

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/mgmt/mcumgr/transport/smp_bt.h>

#define LOG_LEVEL LOG_LEVEL_DBG
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(bluetooth);

static struct k_work advertise_work;

static const struct bt_data ad[] = {
  BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
  BT_DATA_BYTES(BT_DATA_UUID128_ALL,
                0x84, 0xaa, 0x60, 0x74, 0x52, 0x8a, 0x8b, 0x86,
                0xd3, 0x4c, 0xb7, 0x1d, 0x1d, 0xdc, 0x53, 0x8d),
};

static void advertise(struct k_work *work)
{
  int rc;

  bt_le_adv_stop();

  rc = bt_le_adv_start(BT_LE_ADV_CONN_NAME, ad, ARRAY_SIZE(ad), NULL, 0);
  if (rc) {
    LOG_ERR("Advertising failed to start (rc %d)", rc);
    return;
  }

  LOG_INF("Advertising successfully started");
}

static void connected(struct bt_conn *conn, uint8_t err)
{
  if (err) {
    LOG_ERR("Connection failed (err 0x%02x)", err);
  } else {
    LOG_INF("Connected");
  }
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
  LOG_INF("Disconnected (reason 0x%02x)", reason);
  k_work_submit(&advertise_work);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
  .connected = connected,
  .disconnected = disconnected,
};

static void bt_ready(int err)
{
  if (err != 0) {
    LOG_ERR("Bluetooth failed to initialise: %d", err);
  } else {
    k_work_submit(&advertise_work);
  }
}

void start_smp_bluetooth_adverts(void)
{
  int rc;

  k_work_init(&advertise_work, advertise);
  rc = bt_enable(bt_ready);

  if (rc != 0) {
    LOG_ERR("Bluetooth enable failed: %d", rc);
  }
}
