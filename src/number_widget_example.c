/**
 * @file number_widget_example.c
 * @brief Example usage of the number widget
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
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * counter_label = NULL;
static int32_t counter_value = 0;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void increment_button_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Example 1: Create a simple number widget
 */
void number_widget_example_simple(void)
{
    /* Get the active screen */
    lv_obj_t * screen = lv_screen_active();

    /* Create a simple number widget displaying 42 */
    lv_obj_t * label = number_widget_create(screen, 42);

    /* The widget is automatically centered and styled */
}

/**
 * Example 2: Create a styled number widget with custom position
 */
void number_widget_example_styled(void)
{
    lv_obj_t * screen = lv_screen_active();

    /* Create number widget at top-left corner */
    lv_obj_t * label1 = number_widget_create_styled(screen, 123,
                                                     LV_ALIGN_TOP_LEFT, 20, 20);

    /* Create number widget at bottom-right corner */
    lv_obj_t * label2 = number_widget_create_styled(screen, 456,
                                                     LV_ALIGN_BOTTOM_RIGHT, -20, -20);
}

/**
 * Example 3: Create a dynamic counter with update button
 */
void number_widget_example_counter(void)
{
    lv_obj_t * screen = lv_screen_active();

    /* Create a container */
    lv_obj_t * cont = lv_obj_create(screen);
    lv_obj_set_size(cont, 300, 200);
    lv_obj_center(cont);

    /* Create the counter label */
    counter_label = number_widget_create(cont, counter_value);
    lv_obj_align(counter_label, LV_ALIGN_CENTER, 0, -30);

    /* Create an increment button */
    lv_obj_t * btn = lv_button_create(cont);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_event_cb(btn, increment_button_event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t * btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "Increment");
    lv_obj_center(btn_label);
}

/**
 * Example 4: Display floating point numbers
 */
void number_widget_example_float(void)
{
    lv_obj_t * screen = lv_screen_active();

    /* Display temperature with 1 decimal place */
    lv_obj_t * temp_label = number_widget_create_float(screen, 23.5f, 1);
    lv_obj_align(temp_label, LV_ALIGN_CENTER, 0, -50);

    /* Display percentage with 2 decimal places */
    lv_obj_t * percent_label = number_widget_create_float(screen, 99.99f, 2);
    lv_obj_align(percent_label, LV_ALIGN_CENTER, 0, 0);

    /* Display speed with 0 decimal places */
    lv_obj_t * speed_label = number_widget_create_float(screen, 120.7f, 0);
    lv_obj_align(speed_label, LV_ALIGN_CENTER, 0, 50);
}

/**
 * Example 5: Update number dynamically
 */
void number_widget_example_update(void)
{
    static lv_obj_t * my_label = NULL;
    static int32_t my_counter = 0;

    if(my_label == NULL) {
        /* First call - create the widget */
        lv_obj_t * screen = lv_screen_active();
        my_label = number_widget_create(screen, my_counter);
    }
    else {
        /* Subsequent calls - update the number */
        my_counter++;
        number_widget_update(my_label, my_counter);
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Button event callback - increments the counter
 */
static void increment_button_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        /* Increment the counter */
        counter_value++;

        /* Update the label */
        number_widget_update(counter_label, counter_value);
    }
}
