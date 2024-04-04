#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_

/**
 * @defgroup Touch screen channel Input Event Definitions
 * @ingroup input_interface
 * @{
 */

/**
 * @name Touch screen channel.
 * @anchor INPUT_TS
 * @{
 */
#define INPUT_4WIRE_TS_XM 0x01               /**< Touch screen X- channel */
#define INPUT_4WIRE_TS_XP 0x02               /**< Touch screen X+ channel */
#define INPUT_4WIRE_TS_YM 0x03               /**< Touch screen Y- channel */
#define INPUT_4WIRE_TS_YP 0x04               /**< Touch screen Y+ channel */

#endif \
  /* ZEPHYR_INCLUDE_DT_BINDINGS_INPUT_INPUT_RESISTIVE_TOUCHSCREEN_4WIRE_H_ */
