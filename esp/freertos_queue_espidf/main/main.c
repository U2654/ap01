#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "sdkconfig.h"

#define QUEUE_LENGTH 10
#define UNIQUE_VALUE 809

#define LED_PIN 11
/*-----------------------------------------------------------*/

/* The task functions. */
void senderTask( void *pvParameters );
void receiverTask( void *pvParameters );

/* The queue */
QueueHandle_t blinkQueue = NULL;

/*-----------------------------------------------------------*/
void app_main( void )
{
	printf("Starting\n");
    gpio_reset_pin((gpio_num_t) LED_PIN);
    gpio_set_direction((gpio_num_t) LED_PIN, GPIO_MODE_INPUT_OUTPUT);
    gpio_set_level((gpio_num_t) LED_PIN, 0);

	blinkQueue = xQueueCreate( QUEUE_LENGTH, sizeof( uint32_t ) );

	xTaskCreate( senderTask, "Sender", 4096, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( receiverTask, "Receiver", 4096, NULL, tskIDLE_PRIORITY, NULL );

	/* you must not need start scheduler (vTaskStartScheduler();) in ESPIDF 
	as it has already started */
}

/*-----------------------------------------------------------*/
void senderTask( void *pvParameters )
{
	const u_int32_t data = UNIQUE_VALUE;

	TickType_t xLastWakeTime;
	const TickType_t xDelay = pdMS_TO_TICKS( 1000 );
	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
	{
		printf("Sending \n");
		/* send data with do not wait, 0 waiting time */
		xQueueSend(blinkQueue, &data, 0);
		/* periodic (it steps now back) and other tasks can use the cpu. */
		vTaskDelayUntil( &xLastWakeTime, xDelay );
	}
}

void receiverTask( void *pvParameters )
{
	u_int32_t recValue = 0;
	for (;;) 
	{
		/* wait max 2s for data */
		xQueueReceive(blinkQueue, &recValue, pdMS_TO_TICKS(2000));
		if (recValue == UNIQUE_VALUE) 
		{
			recValue = 0;
			printf("Receving correct value\n");
			uint32_t led = gpio_get_level((gpio_num_t) LED_PIN);
            gpio_set_level((gpio_num_t) LED_PIN, !led);
		}
	}
}