#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_PIN 10
#define LED_PIN 11

#define DELAY_PERIOD 1000

bool led_light = false;

// isr requires IRAM_ATTR, no debouncing
void IRAM_ATTR gpio_irq() {
    gpio_intr_disable(BUTTON_PIN);
    gpio_set_level((gpio_num_t) LED_PIN, led_light);
    led_light = !led_light;
    gpio_intr_enable(BUTTON_PIN);
}

void app_main(void)
{
    // init pins 
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_OUTPUT);

    gpio_reset_pin((gpio_num_t) BUTTON_PIN);
    gpio_set_direction((gpio_num_t) BUTTON_PIN, GPIO_MODE_INPUT);
    // interrupt setup
    gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_POSEDGE);
    gpio_install_isr_service(0); // default irq management
    gpio_isr_handler_add(BUTTON_PIN, gpio_irq, 0x0); // attach handler
    gpio_intr_enable(BUTTON_PIN);

    while (1) {
        vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
    }
}
