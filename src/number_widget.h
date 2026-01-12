/**
 * @file number_widget.h
 * @brief Header file for simple number display widget
 */

#ifndef NUMBER_WIDGET_H
#define NUMBER_WIDGET_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a simple text widget that displays a number
 * @param parent the parent object to add the widget to
 * @param number the number to display
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create(lv_obj_t * parent, int32_t number);

/**
 * Update the number displayed in the widget
 * @param label pointer to the label object
 * @param number the new number to display
 */
void number_widget_update(lv_obj_t * label, int32_t number);

/**
 * Create a formatted number widget with custom styling
 * @param parent the parent object to add the widget to
 * @param number the number to display
 * @param align alignment position (e.g., LV_ALIGN_CENTER, LV_ALIGN_TOP_LEFT)
 * @param x_offset x offset from alignment position
 * @param y_offset y offset from alignment position
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create_styled(lv_obj_t * parent, int32_t number,
                                       lv_align_t align, int32_t x_offset, int32_t y_offset);

/**
 * Create a number widget with float precision
 * @param parent the parent object to add the widget to
 * @param number the floating point number to display
 * @param decimals number of decimal places to show (0-3)
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create_float(lv_obj_t * parent, float number, uint8_t decimals);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* NUMBER_WIDGET_H */
