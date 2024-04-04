#ifndef THROUGHPUT_UI_LOG_CONFIG_H
#define THROUGHPUT_UI_LOG_CONFIG_H

/***********************************************************************************************//**
 * @addtogroup throughput_ui
 * @{
 **************************************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>>

// <e THROUGHPUT_UI_LOG_ENABLE> Enable logging
// <i> Enables UI logging.
#define THROUGHPUT_UI_LOG_ENABLE          CONFIG_THROUGHPUT_UI_LOG_ENABLE

// <e THROUGHPUT_UI_LOG_REFRESH_ALL> Print entire display
// <i> Enables printing all rows (entire display) on update method. By disabling
//   this, rows are printed on parameter update.
#define THROUGHPUT_UI_LOG_REFRESH_ALL     CONFIG_THROUGHPUT_UI_LOG_REFRESH_ALL

// <q THROUGHPUT_UI_LOG_BOX_ENABLE> Draw box
// <i> Enables drawing a box around the display area.
#define THROUGHPUT_UI_LOG_BOX_ENABLE      CONFIG_THROUGHPUT_UI_LOG_BOX_ENABLE

// </e>

// </e>

// <<< end of configuration section >>>

/** @} (end addtogroup throughput_ui) */
#endif // THROUGHPUT_UI_LOG_CONFIG_H
