#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "esp_log.h"

#define LED_PIN 11
#define DELAY_PERIOD 9000   

bool led_light = false;

// isr requires IRAM_ATTR
void IRAM_ATTR timer_irq() {
    gpio_set_level((gpio_num_t) LED_PIN, led_light);
    led_light = !led_light;
}

void app_main(void)
{
    // init pins 
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_OUTPUT);

    // create timer
    gptimer_handle_t gptimer = NULL;
    gptimer_config_t timer_config = {
        .clk_src = GPTIMER_CLK_SRC_DEFAULT,
        .direction = GPTIMER_COUNT_UP,
        .resolution_hz = 1000000, // 1MHz, 1 tick=1us
    };
    ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer)); 

    // create alarm
    gptimer_alarm_config_t alarm_config = {
        .reload_count = 0, // counter will reload with 0 on alarm event
        .alarm_count = 1000000, // period = 1s @resolution 1MHz
        .flags.auto_reload_on_alarm = true, // enable auto-reload
    };
    ESP_ERROR_CHECK(gptimer_set_alarm_action(gptimer, &alarm_config));

    // register isr
    gptimer_event_callbacks_t cbs = {
        .on_alarm = timer_irq,
    };
    ESP_ERROR_CHECK(gptimer_register_event_callbacks(gptimer, &cbs, 0x0));

    // enable and start timer
    ESP_ERROR_CHECK(gptimer_enable(gptimer));
    ESP_ERROR_CHECK(gptimer_start(gptimer));

    ESP_LOGI("UNTAG", "Timer started");
    // wait 
    vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);

    // disable timer
    ESP_ERROR_CHECK(gptimer_stop(gptimer));
    ESP_LOGI("UNTAG", "Timer stopped");

    // idle 
    while (1) {
        vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
    }
}
