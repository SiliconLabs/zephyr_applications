/*
 * Copyright 2023 Google LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_
#define ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_

#include <stdint.h>
#include <zephyr/device.h>

/**
 * @brief Analog axis API
 * @defgroup input_resistive_touchscreen_4wire Analog axis API
 * @ingroup io_interfaces
 * @{
 */

/**
 * @brief Analog axis calibration data structure.
 *
 * Holds the calibration data for a single analog axis. Initial values are set
 * from the devicetree and can be changed by the applicatoin in runtime using
 * @ref resistive_touchscreen_4wire_calibration_set and @ref
 *   resistive_touchscreen_4wire_calibration_get.
 */
struct resistive_touchscreen_4wire_calibration {
  /** Input value that corresponds to the minimum x-axis value. */
  uint16_t x_min;

  /** Input value that corresponds to the maximum x-axis value. */
  uint16_t x_max;

  /** Input value that corresponds to the minimum y-axis value. */
  uint16_t y_min;

  /** Input value that corresponds to the maximum y-axis value. */
  uint16_t y_max;

  /** X plate resistance. */
  uint16_t r_xplate;

  /** Input value that corresponds to the resistance threshold of xy plate.*/
  float r_touch_thres;
};

/**
 * @brief Analog axis raw data callback.
 *
 * @param dev Analog axis device.
 * @param channel Channel number.
 * @param raw_val Raw value for the channel.
 */
typedef void (*resistive_touchscreen_4wire_raw_data_t)(const struct device *dev,
                                                       int32_t point_x,
                                                       int32_t point_y,
                                                       float r_touch);

/**
 * @brief Set a raw data callback.
 *
 * Set a callback to receive raw data for the specified analog axis device.
 * This is meant to be use in the application to acquire the data to use for
 * calibration. Set cb to NULL to disable the callback.
 *
 * @param dev Analog axis device.
 * @param cb An resistive_touchscreen_4wire_raw_data_t callback to use, NULL
 *   disable.
 */
void resistive_touchscreen_4wire_set_raw_data_cb(const struct device *dev,
                                                 resistive_touchscreen_4wire_raw_data_t cb);

/**
 * @brief Get the number of defined axes.
 *
 * @retval n The number of defined axes for dev.
 */
int resistive_touchscreen_4wire_num_axes(const struct device *dev);

/**
 * @brief Get the axis calibration data.
 *
 * @param dev Analog axis device.
 * @param cal Pointer to an resistive_touchscreen_4wire_calibration structure
 *   that is going to
 * get set with the current calibration data.
 *
 * @retval 0 If successful.
 * @retval -EINVAL If the specified channel is not valid.
 */
int resistive_touchscreen_4wire_calibration_get(const struct device *dev,
                                                struct resistive_touchscreen_4wire_calibration *cal);

/**
 * @brief Set the axis calibration data.
 *
 * @param dev Analog axis device.
 * @param channel Channel number.
 * @param cal Pointer to an resistive_touchscreen_4wire_calibration structure
 *   with the new
 * calibration data
 *
 * @retval 0 If successful.
 * @retval -EINVAL If the specified channel is not valid.
 */
int resistive_touchscreen_4wire_calibration_set(const struct device *dev,
                                                struct resistive_touchscreen_4wire_calibration *cal);

/** @} */

#endif /* ZEPHYR_INCLUDE_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_ */
