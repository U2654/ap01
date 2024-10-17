#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_sleep.h"
#include "esp_log.h"

#define LED_PIN 11
#define DELAY_PERIOD 250   
#define WAKEUP_TIME 10

bool led_light = false;

void set_sleep_rtc_wakeup(){
}

void blink() {
    led_light = !led_light;
    gpio_set_level((gpio_num_t) LED_PIN, led_light);
    vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
    led_light = !led_light;
    gpio_set_level((gpio_num_t) LED_PIN, led_light);
    vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
}

void app_main(void)
{
    if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_TIMER) {
        printf("wake up from deep sleep\n");
    } 
    else {
        printf("reboot\n");
    }

    // init pins 
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_OUTPUT);

    // set wake up from real time clock
    esp_sleep_enable_timer_wakeup(WAKEUP_TIME * 1000000);

    // blink once
    blink();

    // enter light sleep
    printf("go light sleep\n");
    esp_light_sleep_start();

    printf("wake up from light sleep\n");
    // wait three seconds
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    // blink
    while (1) {
        // blink 10 times
        for (int i = 0; i < 10; i++) {
            blink();
        }
        printf("go deep sleep\n");
        // then enter deep sleep
        esp_deep_sleep_start();
    }
}
