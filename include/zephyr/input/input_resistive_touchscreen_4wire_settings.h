/*
 * Copyright 2023 Google LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_SETTINGS_H_
#define ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_SETTINGS_H_

#include <stdint.h>
#include <zephyr/device.h>

/**
 * @addtogroup input_resistive_touchscreen_4wire
 * @{
 */

/**
 * @brief Save the calibration data.
 *
 * Save the calibration data permanently on the specifided device, requires the
 * the @ref settings subsystem to be configured and initialized.
 *
 * @param dev Analog axis device.
 *
 * @retval 0 If successful.
 * @retval -errno In case of any other error.
 */
int resistive_touchscreen_4wire_calibration_save(const struct device *dev);

/** @} */

#endif /* ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_SETTINGS_H_ */
