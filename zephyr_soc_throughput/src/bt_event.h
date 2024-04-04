#ifndef BT_EVENT_H_
#define BT_EVENT_H_

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/gap.h>

#define ADV_DATA_MAX_LENGTH 255
typedef struct {
  bt_addr_le_t addr;
  int8_t rssi;
  uint8_t type;
  struct {
    uint16_t len;
    uint8_t data[ADV_DATA_MAX_LENGTH];
  } buf;
} bt_evt_le_scan_report_t;

#define ATTR_DATA_MAX_LENGTH 255
enum bt_evt_event_id {
  bt_evt_connection_opened_id,
  bt_evt_connection_closed_id,
  bt_evt_le_param_updated_id,
  bt_evt_le_phy_updated_id,
  bt_evt_le_data_len_updated_id,
  bt_evt_le_scan_report_id,
  bt_evt_tx_power_report_id,
  bt_evt_exchange_mtu_id,
  bt_evt_gatt_discover_attrs_id,
  bt_evt_gatt_characteristic_subscribe_status_id,
  bt_evt_gatt_characteristic_notification_id,
  bt_evt_gatt_characteristic_indication_id,
  bt_evt_system_external_signal_id
};

struct bt_evt {
  enum bt_evt_event_id id;
  union {
    struct {
      struct bt_conn *conn;
      uint8_t err;
    } connection_opened;

    struct {
      struct bt_conn *conn;
      uint8_t reason;
    } connection_closed;

    struct {
      struct bt_conn *conn;
      uint16_t interval;
      uint16_t latency;
      uint16_t timeout;
    } le_param_updated;

    struct {
      struct bt_conn *conn;
      uint16_t tx_max_len;
      uint16_t tx_max_time;
      uint16_t rx_max_len;
      uint16_t rx_max_time;
    } le_data_len_updated;

    bt_evt_le_scan_report_t le_scan_report;

    struct {
      struct bt_conn *conn;
      uint8_t reason;
      enum bt_conn_le_tx_power_phy phy;
      int8_t tx_power_level;
      uint8_t tx_power_level_flag;
      int8_t delta;
    } tx_power_report;

    struct {
      struct bt_conn *conn;
      uint8_t err;
    } exchange_mtu;

    struct {
      struct bt_conn *conn;
      uint8_t tx_phy;
      uint8_t rx_phy;
    } le_phy_updated;

    struct {
      struct bt_conn *conn;
      uint16_t handle;
      uint16_t perm;
      uint16_t value_handle;
      union {
        struct bt_uuid uuid;
        struct bt_uuid_16 uuid16;
        struct bt_uuid_32 uuid32;
        struct bt_uuid_128 uuid128;
      };
    } gatt_discover_attrs;

    struct {
      struct bt_conn *conn;
      uint8_t err;
      struct bt_gatt_subscribe_params *params;
    } gatt_characteristic_subscribe_status;

    struct {
      struct bt_conn *conn;
      uint16_t value_handle;
      struct {
        uint8_t len;
        uint8_t data[ATTR_DATA_MAX_LENGTH];
      } value;
    } gatt_characteristic_notification;

    struct {
      struct bt_conn *conn;
      uint16_t value_handle;
      struct {
        uint8_t len;
        uint8_t data[ATTR_DATA_MAX_LENGTH];
      } value;
    } gatt_characteristic_indication;

    struct {
      uint32_t extsignals;
    } system_external_signal;
  } data;
};

int bt_evt_le_scan_start(const struct bt_le_scan_param *param);

int bt_evt_exchange_mtu(struct bt_conn *conn,
                        struct bt_gatt_exchange_params *params);

int bt_evt_discover_attr(struct bt_conn *conn,
                         uint8_t type,
                         const struct bt_uuid *uuid,
                         uint16_t start_handle,
                         uint16_t end_handle);

#if defined(CONFIG_BT_GATT_AUTO_DISCOVER_CCC)
int bt_evt_gatt_subscribe_for_notification(struct bt_conn *conn,
                                           struct bt_gatt_subscribe_params *params,
                                           struct bt_gatt_discover_params *disc_params);

#else
int bt_evt_gatt_subscribe_for_notification(struct bt_conn *conn,
                                           struct bt_gatt_subscribe_params *params);

#endif

#if defined(CONFIG_BT_GATT_AUTO_DISCOVER_CCC)
int bt_evt_gatt_subscribe_for_indication(struct bt_conn *conn,
                                         struct bt_gatt_subscribe_params *params,
                                         struct bt_gatt_discover_params *disc_params);

#else
int bt_evt_gatt_subscribe_for_indication(struct bt_conn *conn,
                                         struct bt_gatt_subscribe_params *params);

#endif

int bt_evt_wait_event(struct bt_evt *evt, k_timeout_t timeout);

int bt_evt_external_signal(uint32_t signals);

void bt_evt_init(void);

#endif // BT_EVENT_H_
