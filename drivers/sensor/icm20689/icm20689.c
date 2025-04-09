/*
 * Copyright (c) 2022 Esco Medical ApS
 * Copyright (c) 2020 TDK Invensense
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT invensense_icm20689

#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/byteorder.h>
#include "icm20689.h"
#include "icm20689_reg.h"
#include "icm20689_spi.h"
#include "icm20689_trigger.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(ICM20689, CONFIG_SENSOR_LOG_LEVEL);

/*
 * Gyro FS to scaling factor mapping.
 * See datasheet section 3.1 for details
 */
static const uint16_t icm20689_gyro_sensitivity_x10[] = {
  1310, /* BIT_GYRO_UI_FS_250 */
  655, /* BIT_GYRO_UI_FS_500 */
  328, /* BIT_GYRO_UI_FS_1000 */
  164, /* BIT_GYRO_UI_FS_2000 */
};

static int icm20689_set_accel_fs(const struct device *dev, uint16_t fs)
{
  const struct icm20689_config *cfg = dev->config;
  struct icm20689_data *data = dev->data;
  uint8_t temp, reg;

  if ((fs > 16) || (fs < 2)) {
    LOG_ERR("Unsupported range");
    return -ENOTSUP;
  }

  if (fs > 8) {
    temp = ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_16G;
    data->accel_sensitivity_shift = MIN_ACCEL_SENS_SHIFT + 0;
  } else if (fs > 4) {
    temp = ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_8G;
    data->accel_sensitivity_shift = MIN_ACCEL_SENS_SHIFT + 1;
  } else if (fs > 2) {
    temp = ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_4G;
    data->accel_sensitivity_shift = MIN_ACCEL_SENS_SHIFT + 2;
  } else {
    LOG_INF("Set ACCEL full scale : 2.\n");
    temp = ICM20689_ACCEL_CONFIG_ACCEL_FS_SEL_2G;
    data->accel_sensitivity_shift = MIN_ACCEL_SENS_SHIFT + 3;
  }

  reg = icm20689_spi_read(&cfg->spi, ICM20689_REG_ACCEL_CONFIG, &reg, 1);
  reg &= ~(ICM20689_ACCEL_CONFIG_MASK_ACCEL_FS_SEL);
  reg |= temp;

  return icm20689_spi_single_write(&cfg->spi, ICM20689_REG_ACCEL_CONFIG, reg);
}

static int icm20689_set_gyro_fs(const struct device *dev, uint16_t fs)
{
  const struct icm20689_config *cfg = dev->config;
  struct icm20689_data *data = dev->data;
  uint8_t temp, reg;

  if ((fs > 2000) || (fs < 250)) {
    LOG_ERR("Unsupported range");
    return -ENOTSUP;
  }

  if (fs > 1000) {
    temp = ICM20689_GYRO_CONFIG_FS_SEL_2000_DPS;
  } else if (fs > 500) {
    temp = ICM20689_GYRO_CONFIG_FS_SEL_1000_DPS;
  } else if (fs > 250) {
    temp = ICM20689_GYRO_CONFIG_FS_SEL_500_DPS;
  } else {
    LOG_INF("Set GYRO full scale: 250.\n");
    temp = ICM20689_GYRO_CONFIG_FS_SEL_250_DPS;
  }

  data->gyro_sensitivity_x10 =
    icm20689_gyro_sensitivity_x10[temp >> ICM20689_GYRO_CONFIG_SHIFT_FS_SEL];

  reg = icm20689_spi_read(&cfg->spi, ICM20689_REG_GYRO_CONFIG, &reg, 1);
  reg &= ~(ICM20689_GYRO_CONFIG_MASK_FS_SEL);
  reg |= temp;

  return icm20689_spi_single_write(&cfg->spi, ICM20689_REG_GYRO_CONFIG, reg);
}

static int icm20689_set_accel_bandwith(const struct device *dev,
                                       uint16_t bandwith)
{
  const struct icm20689_config *cfg = dev->config;
  uint8_t temp;

  if ((bandwith > 1100) || (bandwith < 5)) {
    LOG_ERR("Unsupported frequency");
    return -ENOTSUP;
  }

  switch (bandwith) {
    case 1046:
      LOG_INF("Set ACCEL bandwith: 1046.\n");
      temp = ICM20689_ACCEL_CONFIG2_MASK_ACCEL_FCHOICE_B
             | ICM20689_ACCEL_CONFIG2_SHIFT_A_DLPF_CFG;
      break;
    case 218:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_218_1_0HZ;
      break;
    case 99:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_99HZ;
      break;
    case 44:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_44HZ;
      break;
    case 21:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_21_2HZ;
      break;
    case 10:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_10_2HZ;
      break;
    case 5:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_5_1HZ;
      break;
    case 420:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_420HZ;
      break;
    default:
      temp = ICM20689_ACCEL_CONFIG2_A_DLPF_CFG_99HZ;
      break;
  }
  return icm20689_spi_update_register(&cfg->spi,
                                      ICM20689_REG_ACCEL_CONFIG2,
                                      (uint8_t)(
                                        ICM20689_ACCEL_CONFIG2_MASK_A_DLPF_CFG
                                        |
                                        ICM20689_ACCEL_CONFIG2_MASK_ACCEL_FCHOICE_B),
                                      temp);
}

static int icm20689_set_gyro_bandwith(const struct device *dev,
                                      uint16_t bandwith)
{
  const struct icm20689_config *cfg = dev->config;
  uint8_t f_choice, dlpf_config;
  uint8_t temp;

  if ((bandwith > 8300) || (bandwith < 5)) {
    LOG_ERR("Unsupported frequency");
    return -ENOTSUP;
  }

  switch (bandwith) {
    case 8173:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_8173HZ  <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT;
      break;
    case 3281:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_3281HZ  <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT;
      break;
    case 250:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT
             | _ICM20689_CONFIG_DLPF_CFG_250HZ;
      break;
    case 176:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT
             | _ICM20689_CONFIG_DLPF_CFG_176HZ;
      break;
    case 92:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT | _ICM20689_CONFIG_DLPF_CFG_92HZ;
      break;
    case 41:
      LOG_INF("Set GYRO bandwith: 41.\n");
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT | _ICM20689_CONFIG_DLPF_CFG_41HZ;
      break;
    case 20:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT | _ICM20689_CONFIG_DLPF_CFG_20HZ;
      break;
    case 10:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT | _ICM20689_CONFIG_DLPF_CFG_10HZ;
      break;
    case 5:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT | _ICM20689_CONFIG_DLPF_CFG_5HZ;
      break;
    default:
      temp = _ICM20689_GYRO_CONFIG_FCHOICE_B_LOWPASS <<
             GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT
             | _ICM20689_CONFIG_DLPF_CFG_250HZ;
      break;
  }

  f_choice =
    (temp >>
     GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT) & ICM20689_GYRO_CONFIG_MASK_FCHOICE_B;
  dlpf_config = temp & ICM20689_CONFIG_MASK_DLPF_CFG;
  icm20689_spi_update_register(&cfg->spi,
                               ICM20689_REG_GYRO_CONFIG,
                               (uint8_t)ICM20689_GYRO_CONFIG_MASK_FCHOICE_B,
                               f_choice <<
                               ICM20689_GYRO_CONFIG_SHIFT_FCHOICE_B);

  return icm20689_spi_update_register(&cfg->spi,
                                      ICM20689_REG_CONFIG,
                                      (uint8_t)ICM20689_CONFIG_MASK_DLPF_CFG,
                                      dlpf_config <<
                                      ICM20689_CONFIG_SHIFT_DLPF_CFG);
}

static int icm20689_sensor_init(const struct device *dev)
{
  int res;
  uint8_t value;
  const struct icm20689_config *cfg = dev->config;

  /* start up time for register read/write after POR is 1ms and supply ramp time
   *   is 3ms */
  k_msleep(3);

  /* perform a soft reset to ensure a clean slate, reset bit will auto-clear */
  res = icm20689_spi_single_write(&cfg->spi,
                                  ICM20689_REG_PWR_MGMT_1,
                                  ICM20689_PWR_MGMT_1_BIT_DEVICE_RESET);

  if (res) {
    LOG_ERR("write REG_SIGNAL_PATH_RESET failed");
    return res;
  }
  LOG_INF("Init OK.\n");

  /* wait for soft reset to take effect */
  k_msleep(SOFT_RESET_TIME_MS);

  res = icm20689_spi_read(&cfg->spi, ICM20689_REG_WHO_AM_I, &value, 1);

  if (res) {
    return res;
  }

  if (value != ICM20689_DEVICE_ID) {
    LOG_ERR("invalid WHO_AM_I value, was %i but expected %i",
            value,
            ICM20689_DEVICE_ID);
    k_msleep(10);
    return -EINVAL;
  }

  LOG_INF("Found ICM20689 sensor, DEVICE ID: 0x%02X", value);

  /// disable I2C interface use SPI
  icm20689_spi_single_write(&cfg->spi,
                            ICM20689_REG_USER_CTRL,
                            ICM20689_USER_CTRL_BIT_I2C_IF_DIS
                            | ICM20689_USER_CTRL_BIT_SIG_COND_RST);
  // Set clock
  icm20689_spi_single_write(&cfg->spi,
                            ICM20689_REG_PWR_MGMT_1,
                            _ICM20689_PWR_MGMT_1_CLKSEL_AUTOSEL_0);
  k_msleep(30);

  return 0;
}

static int icm20689_sample_fetch_temp(const struct device *dev)
{
  const struct icm20689_config *cfg = dev->config;
  struct icm20689_data *data = dev->data;
  uint8_t buffer[TEMP_DATA_SIZE];

  int res = icm20689_spi_read(&cfg->spi,
                              ICM20689_REG_TEMP_OUT_H,
                              buffer,
                              TEMP_DATA_SIZE);

  if (res) {
    return res;
  }

  data->temp = (int16_t)sys_get_be16(&buffer[0]);

  return 0;
}

static int icm20689_turn_on_sensor(const struct device *dev)
{
  struct icm20689_data *data = dev->data;
  const struct icm20689_config *cfg = dev->config;
  int res;

  // enable temperature sensor
  icm20689_spi_update_register(&cfg->spi,
                               ICM20689_REG_PWR_MGMT_1,
                               ICM20689_PWR_MGMT_1_MASK_TEMP_DIS,
                               0x00);
  // enable imu sensor
  icm20689_spi_update_register(&cfg->spi,
                               ICM20689_REG_PWR_MGMT_2,
                               ICM20689_PWR_MGMT_2_MASK_STBY_ZG
                               | ICM20689_PWR_MGMT_2_MASK_STBY_YG
                               | ICM20689_PWR_MGMT_2_MASK_STBY_XG
                               | ICM20689_PWR_MGMT_2_MASK_STBY_ZA
                               | ICM20689_PWR_MGMT_2_MASK_STBY_YA
                               | ICM20689_PWR_MGMT_2_MASK_STBY_XA,
                               0x00);

  res = icm20689_set_accel_fs(dev, data->accel_fs);

  if (res) {
    return res;
  }

  res = icm20689_set_accel_bandwith(dev, data->accel_bw);

  if (res) {
    return res;
  }

  res = icm20689_set_gyro_fs(dev, data->gyro_fs);

  if (res) {
    return res;
  }

  res = icm20689_set_gyro_bandwith(dev, data->gyro_bw);

  if (res) {
    return res;
  }

  /*
   * Accelerometer sensor need at least 10ms startup time
   * Gyroscope sensor need at least 30ms startup time
   */
  k_msleep(100);

  return 0;
}

static void icm20689_convert_accel(struct sensor_value *val, int16_t raw_val,
                                   uint16_t sensitivity_shift)
{
  int64_t conv_val = ((int64_t)raw_val * SENSOR_G) >> sensitivity_shift;

  val->val1 = conv_val / 1000000LL;
  val->val2 = conv_val % 1000000LL;
}

static void icm20689_convert_gyro(struct sensor_value *val, int16_t raw_val,
                                  uint16_t sensitivity_x10)
{
  int64_t conv_val = ((int64_t)raw_val * SENSOR_PI * 10)
                     / (sensitivity_x10 * 180LL);

  val->val1 = conv_val / 1000000LL;
  val->val2 = conv_val % 1000000LL;
}

static inline void icm20689_convert_temp(struct sensor_value *val,
                                         int16_t raw_val)
{
  val->val1 = (((int64_t)raw_val * 100) / 32600) + 25;
  val->val2 = ((((int64_t)raw_val * 100) % 32600) * 1000000) / 32600;

  if (val->val2 < 0) {
    val->val1--;
    val->val2 += 1000000;
  } else if (val->val2 >= 1000000) {
    val->val1++;
    val->val2 -= 1000000;
  }
}

static int icm20689_channel_get(const struct device *dev,
                                enum sensor_channel chan,
                                struct sensor_value *val)
{
  int res = 0;
  const struct icm20689_data *data = dev->data;

  icm20689_lock(dev);

  switch (chan) {
    case SENSOR_CHAN_ACCEL_XYZ:
      icm20689_convert_accel(&val[0],
                             data->accel_x,
                             data->accel_sensitivity_shift);
      icm20689_convert_accel(&val[1],
                             data->accel_y,
                             data->accel_sensitivity_shift);
      icm20689_convert_accel(&val[2],
                             data->accel_z,
                             data->accel_sensitivity_shift);
      break;
    case SENSOR_CHAN_ACCEL_X:
      icm20689_convert_accel(val, data->accel_x, data->accel_sensitivity_shift);
      break;
    case SENSOR_CHAN_ACCEL_Y:
      icm20689_convert_accel(val, data->accel_y, data->accel_sensitivity_shift);
      break;
    case SENSOR_CHAN_ACCEL_Z:
      icm20689_convert_accel(val, data->accel_z, data->accel_sensitivity_shift);
      break;
    case SENSOR_CHAN_GYRO_XYZ:
      icm20689_convert_gyro(&val[0], data->gyro_x, data->gyro_sensitivity_x10);
      icm20689_convert_gyro(&val[1], data->gyro_y, data->gyro_sensitivity_x10);
      icm20689_convert_gyro(&val[2], data->gyro_z, data->gyro_sensitivity_x10);
      break;
    case SENSOR_CHAN_GYRO_X:
      icm20689_convert_gyro(val, data->gyro_x, data->gyro_sensitivity_x10);
      break;
    case SENSOR_CHAN_GYRO_Y:
      icm20689_convert_gyro(val, data->gyro_y, data->gyro_sensitivity_x10);
      break;
    case SENSOR_CHAN_GYRO_Z:
      icm20689_convert_gyro(val, data->gyro_z, data->gyro_sensitivity_x10);
      break;
    case SENSOR_CHAN_DIE_TEMP:
      icm20689_convert_temp(val, data->temp);
      break;
    default:
      res = -ENOTSUP;
      break;
  }

  icm20689_unlock(dev);

  return res;
}

static int icm20689_sample_fetch_accel(const struct device *dev)
{
  const struct icm20689_config *cfg = dev->config;
  struct icm20689_data *data = dev->data;
  uint8_t buffer[ACCEL_DATA_SIZE];

  int res = icm20689_spi_read(&cfg->spi,
                              ICM20689_REG_ACCEL_XOUT_H,
                              buffer,
                              ACCEL_DATA_SIZE);

  if (res) {
    return res;
  }

  data->accel_x = (int16_t)sys_get_be16(&buffer[0]);
  data->accel_y = (int16_t)sys_get_be16(&buffer[2]);
  data->accel_z = (int16_t)sys_get_be16(&buffer[4]);

  return 0;
}

static int icm20689_sample_fetch_gyro(const struct device *dev)
{
  const struct icm20689_config *cfg = dev->config;
  struct icm20689_data *data = dev->data;
  uint8_t buffer[GYRO_DATA_SIZE];

  int res = icm20689_spi_read(&cfg->spi,
                              ICM20689_REG_GYRO_XOUT_H,
                              buffer,
                              GYRO_DATA_SIZE);

  if (res) {
    return res;
  }

  data->gyro_x = (int16_t)sys_get_be16(&buffer[0]);
  data->gyro_y = (int16_t)sys_get_be16(&buffer[2]);
  data->gyro_z = (int16_t)sys_get_be16(&buffer[4]);

  return 0;
}

static int icm20689_sample_fetch(const struct device *dev,
                                 enum sensor_channel chan)
{
  int res;
  uint8_t status;
  const struct icm20689_config *cfg = dev->config;

  icm20689_lock(dev);

  res = icm20689_spi_read(&cfg->spi, ICM20689_REG_INT_STATUS, &status, 1);

  if (res) {
    goto cleanup;
  }

  if ((!status) & ICM20689_INT_STATUS_BIT_DATA_RDY_INT) {
    LOG_INF("Data is not ready!\n");
    res = -EBUSY;
    goto cleanup;
  }

  switch (chan) {
    case SENSOR_CHAN_ALL:
      res |= icm20689_sample_fetch_accel(dev);
      res |= icm20689_sample_fetch_gyro(dev);
      break;
    case SENSOR_CHAN_ACCEL_XYZ:
    case SENSOR_CHAN_ACCEL_X:
    case SENSOR_CHAN_ACCEL_Y:
    case SENSOR_CHAN_ACCEL_Z:
      res = icm20689_sample_fetch_accel(dev);
      break;
    case SENSOR_CHAN_GYRO_XYZ:
    case SENSOR_CHAN_GYRO_X:
    case SENSOR_CHAN_GYRO_Y:
    case SENSOR_CHAN_GYRO_Z:
      res = icm20689_sample_fetch_gyro(dev);
      break;
    case SENSOR_CHAN_DIE_TEMP:
      res = icm20689_sample_fetch_temp(dev);
      break;
    default:
      res = -ENOTSUP;
      break;
  }

  cleanup:
  icm20689_unlock(dev);
  return res;
}

static int icm20689_attr_set(const struct device *dev,
                             enum sensor_channel chan,
                             enum sensor_attribute attr,
                             const struct sensor_value *val)
{
  int res = 0;
  struct icm20689_data *data = dev->data;

  __ASSERT_NO_MSG(val != NULL);

  icm20689_lock(dev);

  switch (chan) {
    case SENSOR_CHAN_ACCEL_X:
    case SENSOR_CHAN_ACCEL_Y:
    case SENSOR_CHAN_ACCEL_Z:
    case SENSOR_CHAN_ACCEL_XYZ:
      if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
        res = icm20689_set_accel_bandwith(dev, data->accel_bw);

        if (res) {
          LOG_ERR("Incorrect sampling value");
        } else {
          data->accel_bw = val->val1;
        }
      } else if (attr == SENSOR_ATTR_FULL_SCALE) {
        res = icm20689_set_accel_fs(dev, data->accel_fs);

        if (res) {
          LOG_ERR("Incorrect fullscale value");
        } else {
          data->accel_fs = val->val1;
        }
      } else {
        LOG_ERR("Unsupported attribute");
        res = -ENOTSUP;
      }
      break;

    case SENSOR_CHAN_GYRO_X:
    case SENSOR_CHAN_GYRO_Y:
    case SENSOR_CHAN_GYRO_Z:
    case SENSOR_CHAN_GYRO_XYZ:
      if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
        res = icm20689_set_gyro_bandwith(dev, data->gyro_bw);

        if (res) {
          LOG_ERR("Incorrect sampling value");
        } else {
          data->gyro_bw = val->val1;
        }
      } else if (attr == SENSOR_ATTR_FULL_SCALE) {
        res = icm20689_set_gyro_fs(dev, data->gyro_fs);

        if (res) {
          LOG_ERR("Incorrect fullscale value");
        } else {
          data->gyro_fs = val->val1;
        }
      } else {
        LOG_ERR("Unsupported attribute");
        res = -EINVAL;
      }
      break;

    default:
      LOG_ERR("Unsupported channel");
      res = -EINVAL;
      break;
  }

  icm20689_unlock(dev);

  return res;
}

static int icm20689_attr_get(const struct device *dev,
                             enum sensor_channel chan,
                             enum sensor_attribute attr,
                             struct sensor_value *val)
{
  const struct icm20689_data *data = dev->data;
  int res = 0;

  __ASSERT_NO_MSG(val != NULL);

  icm20689_lock(dev);

  switch (chan) {
    case SENSOR_CHAN_ACCEL_X:
    case SENSOR_CHAN_ACCEL_Y:
    case SENSOR_CHAN_ACCEL_Z:
    case SENSOR_CHAN_ACCEL_XYZ:
      if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
        val->val1 = data->accel_bw;
      } else if (attr == SENSOR_ATTR_FULL_SCALE) {
        val->val1 = data->accel_fs;
      } else {
        LOG_ERR("Unsupported attribute");
        res = -EINVAL;
      }
      break;

    case SENSOR_CHAN_GYRO_X:
    case SENSOR_CHAN_GYRO_Y:
    case SENSOR_CHAN_GYRO_Z:
    case SENSOR_CHAN_GYRO_XYZ:
      if (attr == SENSOR_ATTR_SAMPLING_FREQUENCY) {
        val->val1 = data->gyro_bw;
      } else if (attr == SENSOR_ATTR_FULL_SCALE) {
        val->val1 = data->gyro_fs;
      } else {
        LOG_ERR("Unsupported attribute");
        res = -EINVAL;
      }
      break;

    default:
      LOG_ERR("Unsupported channel");
      res = -EINVAL;
      break;
  }

  icm20689_unlock(dev);

  return res;
}

static int icm20689_init(const struct device *dev)
{
  struct icm20689_data *data = dev->data;
  const struct icm20689_config *cfg = dev->config;

  if (!spi_is_ready_dt(&cfg->spi)) {
    LOG_ERR("SPI bus is not ready");
    return -ENODEV;
  }

  data->accel_x = 0;
  data->accel_y = 0;
  data->accel_z = 0;
  data->gyro_x = 0;
  data->gyro_y = 0;
  data->gyro_z = 0;
  data->temp = 0;

  if (icm20689_sensor_init(dev)) {
    LOG_ERR("could not initialize sensor");
    return -EIO;
  }

#ifdef CONFIG_ICM20689_TRIGGER
  if (icm20689_trigger_init(dev)) {
    LOG_ERR("Failed to initialize interrupts.");
    return -EIO;
  }
#endif
  int res;
  res = icm20689_turn_on_sensor(dev);

#ifdef CONFIG_ICM20689_TRIGGER
  if (icm20689_trigger_enable_interrupt(dev)) {
    LOG_ERR("Failed to enable interrupts");
    return -EIO;
  }
#endif

  return res;
}

#ifndef CONFIG_ICM20689_TRIGGER

void icm20689_lock(const struct device *dev)
{
  ARG_UNUSED(dev);
}

void icm20689_unlock(const struct device *dev)
{
  ARG_UNUSED(dev);
}

#endif

static const struct sensor_driver_api icm20689_driver_api = {
#ifdef CONFIG_ICM20689_TRIGGER
  .trigger_set = icm20689_trigger_set,
#endif
  .sample_fetch = icm20689_sample_fetch,
  .channel_get = icm20689_channel_get,
  .attr_set = icm20689_attr_set,
  .attr_get = icm20689_attr_get,
};

/* device defaults to spi mode 0/3 support */
#define ICM20689_SPI_CFG                                               \
  SPI_OP_MODE_MASTER | SPI_MODE_CPOL | SPI_MODE_CPHA | SPI_WORD_SET(8) \
  | SPI_TRANSFER_MSB

#define ICM20689_INIT(inst)                                       \
  static struct icm20689_data icm20689_driver_ ## inst = {        \
    .accel_bw = DT_INST_PROP(inst, accel_bw),                     \
    .accel_fs = DT_INST_PROP(inst, accel_fs),                     \
    .gyro_bw = DT_INST_PROP(inst, gyro_bw),                       \
    .gyro_fs = DT_INST_PROP(inst, gyro_fs),                       \
  };                                                              \
                                                                  \
  static const struct icm20689_config icm20689_cfg_ ## inst = {   \
    .spi = SPI_DT_SPEC_INST_GET(inst, ICM20689_SPI_CFG, 0U),      \
    .gpio_int = GPIO_DT_SPEC_INST_GET_OR(inst, int_gpios, { 0 }), \
  };                                                              \
                                                                  \
  SENSOR_DEVICE_DT_INST_DEFINE(inst,                              \
                               icm20689_init,                     \
                               NULL,                              \
                               &icm20689_driver_ ## inst,         \
                               &icm20689_cfg_ ## inst,            \
                               POST_KERNEL,                       \
                               CONFIG_SENSOR_INIT_PRIORITY,       \
                               &icm20689_driver_api);

DT_INST_FOREACH_STATUS_OKAY(ICM20689_INIT)
