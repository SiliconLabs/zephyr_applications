/***************************************************************************//**
 * @file bthome_v2.c
 * @brief zephyr bthome v2 source file.
 *******************************************************************************
 * # License
 * <b>Copyright 2024 Silicon Laboratories Inc. www.silabs.com</b>
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/logging/log.h>
#include <mbedtls/ccm.h>
#include <zephyr/logging/log.h>
#include "bthome_v2.h"

LOG_MODULE_REGISTER(bthome_v2);

/*************************** MACROS *********************************/
#define ADV_PARAM                       BT_LE_ADV_PARAM( \
    BT_LE_ADV_OPT_USE_IDENTITY,                          \
    BT_GAP_ADV_FAST_INT_MIN_2,                           \
    BT_GAP_ADV_FAST_INT_MAX_2,                           \
    NULL)

#define MIC_LEN                         4
#define NONCE_LEN                       13
#define SERVICE_DATA_MAX_LENGHT         20
#define DEVICE_NAME_MAX_LENGTH          8

#define SENSOR_DATA_MAX_LENGHT          9
#define ENCRYPTION_KEY_LENGHT           16

/*********************************************************************/

/*************************** STATIC VARIABLES ************************/
static struct bt_data ad[] = {
  BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR),
  BT_DATA(0, NULL, 0),
  BT_DATA(0, NULL, 0)
};

static volatile bool start_adv;
static uint8_t service_data[SERVICE_DATA_MAX_LENGHT] = { 0 };
static uint8_t sensor_data[SENSOR_DATA_MAX_LENGHT] = { 0 };

static uint8_t data_idx;
static uint8_t service_idx;

static mbedtls_ccm_context encrypt_ctx;
static uint32_t encrypt_count;

static uint8_t device_name[8];
static uint8_t device_name_length = 8;

/************************************************************************/

/************************** STATIC FUNCTION *****************************/
static uint16_t bthome_v2_get_factor(uint8_t obj_id);
static uint8_t bthome_v2_get_num_bytes(uint8_t obj_id);

/************************************************************************/

uint8_t bthome_v2_set_key(uint8_t const * const key)
{
  uint8_t bind_key[16];
  char octet[2];

  // Parse key to 128 bit length format
  for (uint8_t i = 0; i < ENCRYPTION_KEY_LENGHT; i++) {
    memcpy(octet, (uint8_t *)&key[2 * i], 2);
    bind_key[i] = (uint8_t)strtol(octet, NULL, ENCRYPTION_KEY_LENGHT);
  }

  encrypt_count = rand() % 0x427;

  mbedtls_ccm_init(&encrypt_ctx);
  return mbedtls_ccm_setkey(&encrypt_ctx,
                            MBEDTLS_CIPHER_ID_AES,
                            bind_key,
                            ENCRYPTION_KEY_LENGHT * 8);
}

void bthome_v2_build_packet(uint8_t obj_id)
{
  size_t count;
  bt_addr_le_t addrs;
  uint8_t nonce[NONCE_LEN];
  uint8_t *p_count = (uint8_t *)(&encrypt_count);
  uint8_t ciphertext[SERVICE_DATA_MAX_LENGHT];
  uint8_t encryption_mic[MIC_LEN];

  // DO NOT CHANGE -- UUID
  service_data[service_idx++] = 0xD2;
  // DO NOT CHANGE -- UUID
  service_data[service_idx++] = 0xFC;

  service_data[service_idx++] = 0x41;

  bt_id_get(&addrs, &count);

  nonce[0] = addrs.a.val[5];
  nonce[1] = addrs.a.val[4];
  nonce[2] = addrs.a.val[3];
  nonce[3] = addrs.a.val[2];
  nonce[4] = addrs.a.val[1];
  nonce[5] = addrs.a.val[0];

  nonce[6] = 0xD2;
  nonce[7] = 0xFC;

  nonce[8] = service_data[service_idx - 1];

  nonce[9] = p_count[0];
  nonce[10] = p_count[1];
  nonce[11] = p_count[2];
  nonce[12] = p_count[3];

  if ((obj_id != ROTATION_OBJ_ID) && (obj_id != ACCELERATION_OBJ_ID)) {
    while (data_idx < 4) {
      sensor_data[data_idx++] = 0xFF;
    }
  }
  mbedtls_ccm_encrypt_and_tag(&encrypt_ctx, data_idx,
                              nonce, NONCE_LEN, 0, 0, sensor_data,
                              ciphertext, encryption_mic,
                              MIC_LEN);

  for (uint8_t i = 0; i < data_idx; i++) {
    service_data[service_idx++] = ciphertext[i];
  }

  // Add Counter
  service_data[service_idx++] = nonce[9];
  service_data[service_idx++] = nonce[10];
  service_data[service_idx++] = nonce[11];
  service_data[service_idx++] = nonce[12];
  encrypt_count++;

  // Add MIC
  service_data[service_idx++] = encryption_mic[0];
  service_data[service_idx++] = encryption_mic[1];
  service_data[service_idx++] = encryption_mic[2];
  service_data[service_idx++] = encryption_mic[3];
}

void bthome_v2_add_measurement_float_value(float value,
                                           uint8_t obj_id,
                                           bool broadcast_enabled)
{
  uint16_t factor = bthome_v2_get_factor(obj_id);
  uint8_t size = bthome_v2_get_num_bytes(obj_id);
  int val = value * factor;
  int ret;

  if (broadcast_enabled) {
    if ((data_idx + size + 1) <= SENSOR_DATA_MAX_LENGHT) {
      sensor_data[data_idx] = obj_id;
      data_idx++;

      for (int i = 0; i < size; i++) {
        sensor_data[data_idx] = (uint8_t)((val >> (8 * i)) & 0xFF);
        data_idx++;
      }
      if ((obj_id != ROTATION_OBJ_ID) && (obj_id != ACCELERATION_OBJ_ID)) {
        bthome_v2_build_packet(obj_id);
        ad[1].type = BT_DATA_NAME_COMPLETE;
        ad[1].data = device_name;
        ad[1].data_len = device_name_length;

        ad[2].type = BT_DATA_SVC_DATA16;
        ad[2].data = service_data;
        ad[2].data_len = service_idx;
        bthome_v2_update_data(obj_id);
      }
      if (data_idx == SENSOR_DATA_MAX_LENGHT) {
        bthome_v2_build_packet(obj_id);
        ad[1].type = BT_DATA_NAME_COMPLETE;
        ad[1].data = device_name;
        ad[1].data_len = 0;

        ad[2].type = BT_DATA_SVC_DATA16;
        ad[2].data = service_data;
        ad[2].data_len = service_idx;
        bthome_v2_update_data(obj_id);
      }
    }
  } else {
    if (start_adv) {
      ret = bt_le_adv_stop();
      if (ret) {
        LOG_ERR("Advertising failed to stop  ERROR: [%d]", ret);
        return;
      }
      start_adv = false;
    }
  }
}

void bthome_v2_update_data(uint8_t obj_id)
{
  int ret;

  if (!start_adv) {
    ret = bt_le_adv_start(ADV_PARAM, ad, ARRAY_SIZE(ad), NULL, 0);
    if (ret) {
      LOG_ERR("Advertising failed to start  ERROR: [%d]", ret);
      return;
    }
    start_adv = true;
    data_idx = 0;
    service_idx = 0;
    memset(sensor_data, 0, SENSOR_DATA_MAX_LENGHT);
    memset(service_data, 0, SERVICE_DATA_MAX_LENGHT);
  } else {
    ret = bt_le_adv_update_data(ad, ARRAY_SIZE(ad), NULL, 0);
    if (ret) {
      LOG_ERR("Failed to update advertising data. ERROR: [%d]", ret);
    }
    data_idx = 0;
    service_idx = 0;
    memset(sensor_data, 0, SENSOR_DATA_MAX_LENGHT);
    memset(service_data, 0, SERVICE_DATA_MAX_LENGHT);
  }
}

void bthome_v2_set_device_name(const char *name, uint8_t len)
{
  memset(device_name, 0, device_name_length);
  if (len > DEVICE_NAME_MAX_LENGTH) {
    device_name_length = DEVICE_NAME_MAX_LENGTH;
  }
  device_name_length = len;
  memcpy(device_name, name, device_name_length);
}

/***************************************************************************//**
 *  Application BTHome get sensor data factor.
 ******************************************************************************/
static uint16_t bthome_v2_get_factor(uint8_t obj_id)
{
  switch (obj_id) {
    case TEMPERTAURE_OBJ_ID:
    case HUMIDITY_OBJ_ID:
    case ILLUM_OBJ_ID:
    case PRESSURE_OBJ_ID:
      return 100;
    case ROTATION_OBJ_ID:
      return 10;
    case ACCELERATION_OBJ_ID:
      return 1000;
    default:
      break;
  }

  return 0;
}

/***************************************************************************//**
 *  Application BTHome get number of bytes.
 ******************************************************************************/
static uint8_t bthome_v2_get_num_bytes(uint8_t obj_id)
{
  switch (obj_id)
  {
    case TEMPERTAURE_OBJ_ID:
    case HUMIDITY_OBJ_ID:
    case ROTATION_OBJ_ID:
    case ACCELERATION_OBJ_ID:
      return 2;
    case ILLUM_OBJ_ID:
    case PRESSURE_OBJ_ID:
      return 3;
    default:
      break;
  }

  return 0;
}
