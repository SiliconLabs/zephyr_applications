/***************************************************************************//**
 * @file throughput_gattdb.h
 * @brief
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
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
#ifndef THROUGHPUT_GATTDB_H
#define THROUGHPUT_GATTDB_H

#include <zephyr/bluetooth/gatt.h>

enum throughput_gattdb_char {
  throughput_gattdb_char_indication,
  throughput_gattdb_char_notification,
  throughput_gattdb_char_transmission_on,
  throughput_gattdb_char_throughput_result,
  throughput_gattdb_char_connection_phy,
  throughput_gattdb_char_connection_interval,
  throughput_gattdb_char_responder_latency,
  throughput_gattdb_char_supervision_timeout,
  throughput_gattdb_char_pdu_size,
  throughput_gattdb_char_mtu_size
};

/* Throughput Test Service */
extern struct bt_uuid_128 throughput_test_service_uuid;

// /* Throughput Information Service */
extern struct bt_uuid_128 throughput_information_service_uuid;

/* Indications characteristic */
extern const struct bt_uuid_128 indication_char_uuid;

/* Notifications characteristic */
extern const struct bt_uuid_128 notification_char_uuid;

/* Transmission ON characteristic */
extern const struct bt_uuid_128 transmission_on_char_uuid;

/* Throughput result characteristic */
extern const struct bt_uuid_128 throughput_result_char_uuid;

/* Connection PHY characteristic */
extern const struct bt_uuid_128 connection_phy_char_uuid;

/* Connection interval characteristic */
extern const struct bt_uuid_128 connection_interval_char_uuid;

/* Responder latency characteristic */
extern const struct bt_uuid_128 responder_latency_char_uuid;

/* Supervision timeout characteristic */
extern const struct bt_uuid_128 supervision_timeout_char_uuid;

/* PDU size characteristic */
extern const struct bt_uuid_128 pdu_size_char_uuid;

/* MTU size characteristic */
extern const struct bt_uuid_128 mtu_size_char_uuid;

extern const struct bt_gatt_service_static throughput_test_svc;
extern const struct bt_gatt_service_static throughput_information_svc;

void throughput_gattdb_register_char_read_cb(ssize_t (*cb)(
                                               enum throughput_gattdb_char c,
                                               struct bt_conn *conn,
                                               const struct bt_gatt_attr *attr,
                                               void *buf,
                                               uint16_t len,
                                               uint16_t offset));

void throughput_gattdb_register_char_write_cb(ssize_t (*cb)(
                                                enum throughput_gattdb_char c,
                                                struct bt_conn *conn,
                                                const struct bt_gatt_attr *attr,
                                                const void *buf,
                                                uint16_t len,
                                                uint16_t offset,
                                                uint8_t flags));

void throughput_gattdb_register_ccc_changed_cb(void (*cb)(
                                                 enum throughput_gattdb_char c,
                                                 const struct bt_gatt_attr *attr,
                                                 uint16_t value));

#endif // THROUGHPUT_GATTDB_H
