/* Bosch BMP384 pressure sensor
 *
 * Copyright (c) 2020 Facebook, Inc. and its affiliates
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Datasheet:
 * https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bmp384-ds001.pdf
 */

#ifndef __BMP384_H
#define __BMP384_H

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/util.h>

#define DT_DRV_COMPAT  bosch_bmp384

#define BMP384_BUS_I2C DT_ANY_INST_ON_BUS_STATUS_OKAY(i2c)

union bmp384_bus {
  struct i2c_dt_spec i2c;
};

typedef int (*bmp384_bus_check_fn)(const union bmp384_bus *bus);
typedef int (*bmp384_reg_read_fn)(const union bmp384_bus *bus,
                                  uint8_t start, uint8_t *buf, int size);
typedef int (*bmp384_reg_write_fn)(const union bmp384_bus *bus,
                                   uint8_t reg, uint8_t val);

struct bmp384_bus_io {
  bmp384_bus_check_fn check;
  bmp384_reg_read_fn read;
  bmp384_reg_write_fn write;
};

extern const struct bmp384_bus_io bmp384_bus_io_i2c;

/* registers */
#define BMP384_REG_CHIPID            0x00
#define BMP384_REG_ERR_REG           0x02
#define BMP384_REG_STATUS            0x03
#define BMP384_REG_DATA0             0x04
#define BMP384_REG_DATA1             0x05
#define BMP384_REG_DATA2             0x06
#define BMP384_REG_DATA3             0x07
#define BMP384_REG_DATA4             0x08
#define BMP384_REG_DATA5             0x09
#define BMP384_REG_SENSORTIME0       0x0C
#define BMP384_REG_SENSORTIME1       0x0D
#define BMP384_REG_SENSORTIME2       0x0E
#define BMP384_REG_SENSORTIME3       0x0F
#define BMP384_REG_EVENT             0x10
#define BMP384_REG_INT_STATUS        0x11
#define BMP384_REG_INT_CTRL          0x19
#define BMP384_REG_IF_CONF           0x1A
#define BMP384_REG_PWR_CTRL          0x1B
#define BMP384_REG_CONFIG            0x1F
#define BMP384_REG_CALIB0            0x31
#define BMP384_REG_CMD               0x7E

/* BMP384_REG_CHIPID */
#define BMP384_CHIP_ID               0x50

/* BMP384_REG_STATUS */
#define BMP384_STATUS_FATAL_ERR      BIT(0)
#define BMP384_STATUS_CMD_ERR        BIT(1)
#define BMP384_STATUS_CONF_ERR       BIT(2)
#define BMP384_STATUS_CMD_RDY        BIT(4)
#define BMP384_STATUS_DRDY_PRESS     BIT(5)
#define BMP384_STATUS_DRDY_TEMP      BIT(6)

/* BMP384_REG_INT_CTRL */
#define BMP384_INT_CTRL_DRDY_EN_POS  6
#define BMP384_INT_CTRL_DRDY_EN_MASK BIT(6)

/* BMP384_REG_PWR_CTRL */
#define BMP384_PWR_CTRL_PRESS_EN     BIT(0)
#define BMP384_PWR_CTRL_TEMP_EN      BIT(1)
#define BMP384_PWR_CTRL_MODE_POS     4
#define BMP384_PWR_CTRL_MODE_MASK    (0x03 << BMP384_PWR_CTRL_MODE_POS)
#define BMP384_PWR_CTRL_MODE_SLEEP   (0x00 << BMP384_PWR_CTRL_MODE_POS)
#define BMP384_PWR_CTRL_MODE_FORCED  (0x01 << BMP384_PWR_CTRL_MODE_POS)
#define BMP384_PWR_CTRL_MODE_NORMAL  (0x03 << BMP384_PWR_CTRL_MODE_POS)

/* BMP384_REG_CMD */
#define BMP384_CMD_FIFO_FLUSH        0xB0
#define BMP384_CMD_SOFT_RESET        0xB6

/* default PWR_CTRL settings */
#define BMP384_PWR_CTRL_ON    \
  (BMP384_PWR_CTRL_PRESS_EN | \
   BMP384_PWR_CTRL_TEMP_EN |  \
   BMP384_PWR_CTRL_MODE_NORMAL)
#define BMP384_PWR_CTRL_OFF          0

#define BMP384_SAMPLE_BUFFER_SIZE    (6)

struct bmp384_cal_data {
  uint16_t t1;
  uint16_t t2;
  int8_t t3;
  int16_t p1;
  int16_t p2;
  int8_t p3;
  int8_t p4;
  uint16_t p5;
  uint16_t p6;
  int8_t p7;
  int8_t p8;
  int16_t p9;
  int8_t p10;
  int8_t p11;
} __packed;

struct bmp384_sample {
  uint32_t press;
  uint32_t raw_temp;
  int64_t comp_temp;
};

struct bmp384_config {
  union bmp384_bus bus;
  const struct bmp384_bus_io *bus_io;
};

struct bmp384_data {
  uint8_t pressure;
  uint8_t temp;
  struct bmp384_cal_data cal;
  struct bmp384_sample sample;
};

int bmp384_reg_field_update(const struct device *dev,
                            uint8_t reg,
                            uint8_t mask,
                            uint8_t val);

#endif /* __BMP384_H */
