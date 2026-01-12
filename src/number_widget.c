/**
 * @file number_widget.c
 * @brief Simple text widget that displays a number
 */

/*********************
 *      INCLUDES
 *********************/
#include "number_widget.h"
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a simple text widget that displays a number
 * @param parent the parent object to add the widget to
 * @param number the number to display
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create(lv_obj_t * parent, int32_t number)
{
    /* Create a label object */
    lv_obj_t * label = lv_label_create(parent);

    /* Set the text to display the number */
    lv_label_set_text_fmt(label, "%d", number);

    /* Optional: Set text alignment */
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);

    /* Optional: Center align the label */
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    /* Optional: Set text color */
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_BLUE), 0);

    /* Optional: Set font size - using larger font */
    static lv_style_t style_large_text;
    lv_style_init(&style_large_text);
    lv_style_set_text_font(&style_large_text, &lv_font_montserrat_48);
    lv_obj_add_style(label, &style_large_text, 0);

    return label;
}

/**
 * Update the number displayed in the widget
 * @param label pointer to the label object
 * @param number the new number to display
 */
void number_widget_update(lv_obj_t * label, int32_t number)
{
    if(label == NULL) return;

    lv_label_set_text_fmt(label, "%d", number);
}

/**
 * Create a formatted number widget with custom styling
 * @param parent the parent object to add the widget to
 * @param number the number to display
 * @param align alignment position
 * @param x_offset x offset from alignment position
 * @param y_offset y offset from alignment position
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create_styled(lv_obj_t * parent, int32_t number,
                                       lv_align_t align, int32_t x_offset, int32_t y_offset)
{
    lv_obj_t * label = lv_label_create(parent);

    /* Set the number text */
    lv_label_set_text_fmt(label, "%d", number);

    /* Position the label */
    lv_obj_align(label, align, x_offset, y_offset);

    /* Apply custom styling */
    lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_BLUE), 0);

    static lv_style_t style_number;
    lv_style_init(&style_number);
    lv_style_set_text_font(&style_number, &lv_font_montserrat_32);
    lv_style_set_text_align(&style_number, LV_TEXT_ALIGN_CENTER);
    lv_obj_add_style(label, &style_number, 0);

    return label;
}

/**
 * Create a number widget with float precision
 * @param parent the parent object to add the widget to
 * @param number the floating point number to display
 * @param decimals number of decimal places to show
 * @return pointer to the created label object
 */
lv_obj_t * number_widget_create_float(lv_obj_t * parent, float number, uint8_t decimals)
{
    lv_obj_t * label = lv_label_create(parent);

    /* Format based on decimal precision */
    if(decimals == 1) {
        lv_label_set_text_fmt(label, "%.1f", number);
    }
    else if(decimals == 2) {
        lv_label_set_text_fmt(label, "%.2f", number);
    }
    else if(decimals == 3) {
        lv_label_set_text_fmt(label, "%.3f", number);
    }
    else {
        lv_label_set_text_fmt(label, "%.0f", number);
    }

    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    return label;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
