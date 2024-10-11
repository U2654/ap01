#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_PIN 10
#define LED_PIN 11

#define DELAY_PERIOD 1000

void app_main(void)
{
    // init pins 
    gpio_reset_pin((gpio_num_t) BUTTON_PIN);
    gpio_set_direction((gpio_num_t) BUTTON_PIN, GPIO_MODE_INPUT);
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        if (gpio_get_level((gpio_num_t) BUTTON_PIN) == 1) {
            gpio_set_level((gpio_num_t) LED_PIN, 0);
            printf("low\n");
        }
        else {
            gpio_set_level((gpio_num_t) LED_PIN, 1);
            printf("high\n");
        }
        vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
    }
}
