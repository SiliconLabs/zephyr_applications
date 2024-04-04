/* Bosch BMP384 pressure sensor
 *
 * Copyright (c) 2020 Facebook, Inc. and its affiliates
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Datasheet:
 * https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp384-ds001.pdf
 */

#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/pm/device.h>

#include "bmp384.h"

LOG_MODULE_REGISTER(BMP384, CONFIG_SENSOR_LOG_LEVEL);

static inline int bmp384_bus_check(const struct device *dev)
{
  const struct bmp384_config *cfg = dev->config;

  return cfg->bus_io->check(&cfg->bus);
}

static inline int bmp384_reg_read(const struct device *dev,
                                  uint8_t start, uint8_t *buf, int size)
{
  const struct bmp384_config *cfg = dev->config;

  return cfg->bus_io->read(&cfg->bus, start, buf, size);
}

static inline int bmp384_reg_write(const struct device *dev, uint8_t reg,
                                   uint8_t val)
{
  const struct bmp384_config *cfg = dev->config;

  return cfg->bus_io->write(&cfg->bus, reg, val);
}

int bmp384_reg_field_update(const struct device *dev,
                            uint8_t reg,
                            uint8_t mask,
                            uint8_t val)
{
  int rc = 0;
  uint8_t old_value, new_value;
  const struct bmp384_config *cfg = dev->config;

  rc = cfg->bus_io->read(&cfg->bus, reg, &old_value, 1);
  if (rc != 0) {
    return rc;
  }

  new_value = (old_value & ~mask) | (val & mask);
  if (new_value == old_value) {
    return 0;
  }

  return cfg->bus_io->write(&cfg->bus, reg, new_value);
}

static int bmp384_sample_fetch(const struct device *dev,
                               enum sensor_channel chan)
{
  struct bmp384_data *bmp384 = dev->data;
  uint8_t raw[BMP384_SAMPLE_BUFFER_SIZE];
  int ret = 0;

  __ASSERT_NO_MSG(chan == SENSOR_CHAN_ALL);

#ifdef CONFIG_PM_DEVICE
  enum pm_device_state state;

  (void)pm_device_state_get(dev, &state);
  if (state != PM_DEVICE_STATE_ACTIVE) {
    return -EBUSY;
  }
#endif

  pm_device_busy_set(dev);

  /* Wait for status to indicate that data is ready. */
  raw[0] = 0U;
  while ((raw[0] & BMP384_STATUS_DRDY_PRESS) == 0U) {
    ret = bmp384_reg_read(dev, BMP384_REG_STATUS, raw, 1);
    if (ret < 0) {
      goto error;
    }
  }

  ret = bmp384_reg_read(dev,
                        BMP384_REG_DATA0,
                        raw,
                        BMP384_SAMPLE_BUFFER_SIZE);
  if (ret < 0) {
    goto error;
  }

  /* convert samples to 32bit values */
  bmp384->sample.press = (uint32_t)raw[0]
                         | ((uint32_t)raw[1] << 8)
                         | ((uint32_t)raw[2] << 16);
  bmp384->sample.raw_temp = (uint32_t)raw[3]
                            | ((uint32_t)raw[4] << 8)
                            | ((uint32_t)raw[5] << 16);
  bmp384->sample.comp_temp = 0;

  error:
  pm_device_busy_clear(dev);
  return ret;
}

static void bmp384_compensate_temp(struct bmp384_data *data)
{
  /* Adapted from:
   * https://github.com/BoschSensortec/BMP3-Sensor-API/blob/master/bmp3.c
   */

  int64_t partial_data1;
  int64_t partial_data2;
  int64_t partial_data3;
  int64_t partial_data4;
  int64_t partial_data5;

  struct bmp384_cal_data *cal = &data->cal;

  partial_data1 = ((int64_t)data->sample.raw_temp - (256 * cal->t1));
  partial_data2 = cal->t2 * partial_data1;
  partial_data3 = (partial_data1 * partial_data1);
  partial_data4 = (int64_t)partial_data3 * cal->t3;
  partial_data5 = ((int64_t)(partial_data2 * 262144) + partial_data4);

  /* Store for pressure calculation */
  data->sample.comp_temp = partial_data5 / 4294967296;
}

static int bmp384_temp_channel_get(const struct device *dev,
                                   struct sensor_value *val)
{
  struct bmp384_data *data = dev->data;

  if (data->sample.comp_temp == 0) {
    bmp384_compensate_temp(data);
  }

  int64_t tmp = (data->sample.comp_temp * 250000) / 16384;

  val->val1 = tmp / 1000000;
  val->val2 = tmp % 1000000;

  return 0;
}

static uint64_t bmp384_compensate_press(struct bmp384_data *data)
{
  /* Adapted from:
   * https://github.com/BoschSensortec/BMP3-Sensor-API/blob/master/bmp3.c
   */

  int64_t partial_data1;
  int64_t partial_data2;
  int64_t partial_data3;
  int64_t partial_data4;
  int64_t partial_data5;
  int64_t partial_data6;
  int64_t offset;
  int64_t sensitivity;
  uint64_t comp_press;

  struct bmp384_cal_data *cal = &data->cal;

  int64_t t_lin = data->sample.comp_temp;
  uint32_t raw_pressure = data->sample.press;

  partial_data1 = t_lin * t_lin;
  partial_data2 = partial_data1 / 64;
  partial_data3 = (partial_data2 * t_lin) / 256;
  partial_data4 = (cal->p8 * partial_data3) / 32;
  partial_data5 = (cal->p7 * partial_data1) * 16;
  partial_data6 = (cal->p6 * t_lin) * 4194304;
  offset = (cal->p5 * 140737488355328) + partial_data4 + partial_data5
           + partial_data6;
  partial_data2 = (cal->p4 * partial_data3) / 32;
  partial_data4 = (cal->p3 * partial_data1) * 4;
  partial_data5 = (cal->p2 - 16384) * t_lin * 2097152;
  sensitivity = ((cal->p1 - 16384) * 70368744177664) + partial_data2
                + partial_data4 + partial_data5;
  partial_data1 = (sensitivity / 16777216) * raw_pressure;
  partial_data2 = cal->p10 * t_lin;
  partial_data3 = partial_data2 + (65536 * cal->p9);
  partial_data4 = (partial_data3 * raw_pressure) / 8192;

  /* Dividing by 10 followed by multiplying by 10 to avoid overflow caused
   * (raw_pressure * partial_data4)
   */
  partial_data5 = (raw_pressure * (partial_data4 / 10)) / 512;
  partial_data5 = partial_data5 * 10;
  partial_data6 = ((int64_t)raw_pressure * (int64_t)raw_pressure);
  partial_data2 = (cal->p11 * partial_data6) / 65536;
  partial_data3 = (partial_data2 * raw_pressure) / 128;
  partial_data4 = (offset / 4) + partial_data1 + partial_data5
                  + partial_data3;

  comp_press = (((uint64_t)partial_data4 * 25) / (uint64_t)1099511627776);

  /* returned value is in hundredths of Pa. */
  return comp_press;
}

static int bmp384_press_channel_get(const struct device *dev,
                                    struct sensor_value *val)
{
  struct bmp384_data *data = dev->data;

  if (data->sample.comp_temp == 0) {
    bmp384_compensate_temp(data);
  }

  uint64_t tmp = bmp384_compensate_press(data);

  /* tmp is in hundredths of Pa. Convert to kPa as specified in sensor
   * interface.
   */
  val->val1 = tmp / 100000;
  val->val2 = (tmp % 100000) * 10;

  return 0;
}

static int bmp384_channel_get(const struct device *dev,
                              enum sensor_channel chan,
                              struct sensor_value *val)
{
  switch (chan) {
    case SENSOR_CHAN_PRESS:
      bmp384_press_channel_get(dev, val);
      break;

    case SENSOR_CHAN_DIE_TEMP:
    case SENSOR_CHAN_AMBIENT_TEMP:
      bmp384_temp_channel_get(dev, val);
      break;

    default:
      LOG_DBG("Channel not supported.");
      return -ENOTSUP;
  }

  return 0;
}

static int bmp384_get_calibration_data(const struct device *dev)
{
  struct bmp384_data *data = dev->data;
  struct bmp384_cal_data *cal = &data->cal;

  if (bmp384_reg_read(dev, BMP384_REG_CALIB0, (uint8_t *)cal,
                      sizeof(*cal)) < 0) {
    return -EIO;
  }

  cal->t1 = sys_le16_to_cpu(cal->t1);
  cal->t2 = sys_le16_to_cpu(cal->t2);
  cal->p1 = sys_le16_to_cpu(cal->p1);
  cal->p2 = sys_le16_to_cpu(cal->p2);
  cal->p5 = sys_le16_to_cpu(cal->p5);
  cal->p6 = sys_le16_to_cpu(cal->p6);
  cal->p9 = sys_le16_to_cpu(cal->p9);

  return 0;
}

static int bmp384_init(const struct device *dev)
{
  uint8_t val = 0U;

  if (bmp384_bus_check(dev) < 0) {
    LOG_DBG("bus check failed");
    return -ENODEV;
  }

  /* reboot the chip */
  if (bmp384_reg_write(dev, BMP384_REG_CMD, BMP384_CMD_SOFT_RESET) < 0) {
    LOG_ERR("Cannot reboot chip.");
    return -EIO;
  }

  k_busy_wait(2000);

  if (bmp384_reg_read(dev, BMP384_REG_CHIPID, &val, 1) < 0) {
    LOG_ERR("Failed to read chip id.");
    return -EIO;
  }

  if (val != BMP384_CHIP_ID) {
    LOG_ERR("Unsupported chip detected (0x%x)!", val);
    return -ENODEV;
  }

  /* Read calibration data */
  if (bmp384_get_calibration_data(dev) < 0) {
    LOG_ERR("Failed to read calibration data.");
    return -EIO;
  }

  /* Enable sensors and normal mode*/
  if (bmp384_reg_write(dev,
                       BMP384_REG_PWR_CTRL,
                       BMP384_PWR_CTRL_ON) < 0) {
    LOG_ERR("Failed to enable sensors.");
    return -EIO;
  }

  return 0;
}

static const struct sensor_driver_api bmp384_api = {
  .sample_fetch = bmp384_sample_fetch,
  .channel_get = bmp384_channel_get,
};

/* Initializes a struct bmp384_config for an instance on an I2C bus. */
#define BMP384_CONFIG_I2C(inst)          \
  .bus.i2c = I2C_DT_SPEC_INST_GET(inst), \
  .bus_io = &bmp384_bus_io_i2c,

#define BMP384_INST(inst)                                      \
  static struct bmp384_data bmp384_data_ ## inst;              \
  static const struct bmp384_config bmp384_config_ ## inst = { \
    BMP384_CONFIG_I2C(inst)                                    \
  };                                                           \
  PM_DEVICE_DT_INST_DEFINE(inst, bmp384_pm_action);            \
  SENSOR_DEVICE_DT_INST_DEFINE(                                \
    inst,                                                      \
    bmp384_init,                                               \
    NULL,                                                      \
    &bmp384_data_ ## inst,                                     \
    &bmp384_config_ ## inst,                                   \
    POST_KERNEL,                                               \
    CONFIG_SENSOR_INIT_PRIORITY,                               \
    &bmp384_api);

DT_INST_FOREACH_STATUS_OKAY(BMP384_INST)
