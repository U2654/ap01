#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/gptimer.h"
#include "sdkconfig.h"

/*-----------------------------------------------------------*/

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );
void vTask3( void *pvParameters );

const char *pcTextForTask1 = "Task 1\n";
const char *pcTextForTask2 = "Task 2\n";
const char *pcTextForTask3 = "Task 3\n";

u_int64_t counterTask2 = 0;
u_int64_t counterTask3 = 0;

/*-----------------------------------------------------------*/
void app_main( void )
{
	/* three tasks with different priorities */
	/* generate task for vTask1, name: "Task 1", stack size: 4096
	parameter: 1, priority: 2 and no taskhandle (NULL) */
	xTaskCreate( vTask1, "Task 1", 4096, (void*) 1, 2, NULL );
	/* no parameters for the next two and lowest priority */
	/* there is a idle task doing housekeeping that must not starve. 
	   Therefore do not have another task that does not yield 
	   (not release the cpu) have a higher priority than the idle. */
	xTaskCreate( vTask2, "Task 2", 4096, NULL, tskIDLE_PRIORITY, NULL );
	xTaskCreate( vTask3, "Task 3", 4096, NULL, tskIDLE_PRIORITY, NULL );

	/* you must not need start scheduler (vTaskStartScheduler();) in ESPIDF 
	as it has already started */
}

/*-----------------------------------------------------------*/
void vTask1( void *pvParameters )
{
	int param = (int) pvParameters; // cast to integer
	TickType_t xLastWakeTime;
	const TickType_t xDelay = pdMS_TO_TICKS( 1000 );
	xLastWakeTime = xTaskGetTickCount();
	for( ;; )
	{
		printf("Task %d\n", param);
		printf("Counter T2: %llu\n", counterTask2);
		printf("Counter T3: %llu\n", counterTask3);
		/* periodic (it steps now back) and other tasks 
		   can use the cpu. */
		vTaskDelayUntil( &xLastWakeTime, xDelay );
	}
}

/*-----------------------------------------------------------*/
void vTask2( void *pvParameters )
{
	/* task does not release the cpu by itself*/
	for( ;; )
	{
		counterTask2++;
	}
}

/*-----------------------------------------------------------*/
void vTask3( void *pvParameters )
{
	/* task does not release the cpu by itself*/
	for( ;; )
	{
		counterTask3++;
	}
}
