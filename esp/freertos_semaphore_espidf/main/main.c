#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "sdkconfig.h"

#define BUTTON_PIN 10
#define LED_PIN 11
/*-----------------------------------------------------------*/

/* The task functions. */
void interruptTask( void *pvParameters );
void runningTask( void *pvParameters );

/* Semaphore for interrupt */
SemaphoreHandle_t isrSemaphore = NULL;

/*-----------------------------------------------------------*/
/* ISR */
void IRAM_ATTR isrHandler() 
{
	xSemaphoreGiveFromISR(isrSemaphore, NULL);
}
/*-----------------------------------------------------------*/
void app_main( void )
{
	printf("Starting\n");
	/* init led as input and output */
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_level((gpio_num_t) LED_PIN, 0);
	/* init button as input */
    gpio_reset_pin((gpio_num_t) BUTTON_PIN);
    gpio_set_direction((gpio_num_t) BUTTON_PIN, GPIO_MODE_INPUT);

	/* create semaphore, initially is taken */
	isrSemaphore = xSemaphoreCreateBinary();

	if (isrSemaphore == NULL) {
		return; /* problem */
	}

	/*  interrupt setup */
    gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_POSEDGE);
    gpio_install_isr_service(0); 
    gpio_isr_handler_add(BUTTON_PIN, isrHandler, 0x0); 
    gpio_intr_enable(BUTTON_PIN);

	/* create two task */
	xTaskCreate( runningTask, "running", 4096, NULL, tskIDLE_PRIORITY, NULL );
	/* isr task with higher priority */
	xTaskCreate( interruptTask, "interrupt", 4096, NULL, tskIDLE_PRIORITY + 5, NULL );

	/* you must not need start scheduler (vTaskStartScheduler();) in ESPIDF 
	as it has already started */
}

/*-----------------------------------------------------------*/
void runningTask( void *pvParameters )
{
	TickType_t xLastWakeTime;
	const TickType_t xDelay = pdMS_TO_TICKS( 1000 );
	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
	{
		printf("running \n");
		/* periodic (it steps now back) and other tasks can use the cpu. */
		vTaskDelayUntil( &xLastWakeTime, xDelay );
	}
}

/*-----------------------------------------------------------*/
void interruptTask( void *pvParameters )
{
	for (;;) 
	{
		/* wait to take semaphore that will be given by isr */
		xSemaphoreTake(isrSemaphore, portMAX_DELAY);

		printf("Interrupt\n");
		/* change led status */
		uint32_t led = gpio_get_level((gpio_num_t) LED_PIN);
		gpio_set_level((gpio_num_t) LED_PIN, !led);
		/* wait to debounce */
		vTaskDelay(50);
	}
}