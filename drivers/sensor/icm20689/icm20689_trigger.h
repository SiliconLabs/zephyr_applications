/*
 * Copyright (c) 2022 Esco Medical ApS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_SENSOR_ICM20689_TRIGGER_H_
#define ZEPHYR_DRIVERS_SENSOR_ICM20689_TRIGGER_H_

#include <zephyr/device.h>

/** implement the trigger_set sensor api function */
int icm20689_trigger_set(const struct device *dev,
                         const struct sensor_trigger *trig,
                         sensor_trigger_handler_t handler);

/**
 * @brief initialize the icm20689 trigger system
 *
 * @param dev icm20689 device pointer
 * @return int 0 on success, negative error code otherwise
 */
int icm20689_trigger_init(const struct device *dev);

/**
 * @brief enable the trigger gpio interrupt
 *
 * @param dev icm20689 device pointer
 * @return int 0 on success, negative error code otherwise
 */
int icm20689_trigger_enable_interrupt(const struct device *dev);

/**
 * @brief lock access to the icm20689 device driver
 *
 * @param dev icm20689 device pointer
 */
void icm20689_lock(const struct device *dev);

/**
 * @brief lock access to the icm20689 device driver
 *
 * @param dev icm20689 device pointer
 */
void icm20689_unlock(const struct device *dev);

#endif /* ZEPHYR_DRIVERS_SENSOR_ICM20689_TRIGGER_H_ */
