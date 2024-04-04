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
