/*
 * Copyright (c) 2022 Esco Medical ApS
 * Copyright (c) 2020 TDK Invensense
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_ICM20689_H_
#define ZEPHYR_DRIVERS_SENSOR_ICM20689_H_

#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/kernel.h>

#define GYRO_DATA_SIZE                              6
#define ACCEL_DATA_SIZE                             6
#define TEMP_DATA_SIZE                              2
#define SOFT_RESET_TIME_MS                          100

// /// Gyroscope enum bitfield shift.
#define GYRO_BANDWITDH_ENUM_FCHOICE_SHIFT           (0x03U)

#define ICM20689_WHO_AM_I_MASK_WHOAMI_ID            (0x98)

#define ICM20689_DEVICE_ID \
  ICM20689_WHO_AM_I_MASK_WHOAMI_ID

struct icm20689_data {
  int16_t accel_x;
  int16_t accel_y;
  int16_t accel_z;
  uint16_t accel_sensitivity_shift;
  uint16_t accel_bw;
  uint16_t accel_fs;
  int16_t gyro_x;
  int16_t gyro_y;
  int16_t gyro_z;
  uint16_t gyro_sensitivity_x10;
  uint16_t gyro_bw;
  uint16_t gyro_fs;
  int16_t temp;
#ifdef CONFIG_ICM20689_TRIGGER
  const struct device *dev;
  struct gpio_callback gpio_cb;
  sensor_trigger_handler_t data_ready_handler;
  const struct sensor_trigger *data_ready_trigger;
  struct k_mutex mutex;
#endif
#ifdef CONFIG_ICM20689_TRIGGER_OWN_THREAD
  K_KERNEL_STACK_MEMBER(thread_stack, CONFIG_ICM20689_THREAD_STACK_SIZE);
  struct k_thread thread;
  struct k_sem gpio_sem;
#endif
#ifdef CONFIG_ICM20689_TRIGGER_GLOBAL_THREAD
  struct k_work work;
#endif
};

struct icm20689_config {
  struct spi_dt_spec spi;
  struct gpio_dt_spec gpio_int;
};

#endif /* ZEPHYR_DRIVERS_SENSOR_ICM20689_H_ */
