/* You can read the partition from the microcontroller after running the application by: */
/* parttool.py --port /dev/tty.usbmodem1101 read_partition --partition-type=data --partition-subtype=fat --output flash.img */
/* NOTE: /dev/tty... must match with your used port. */
/* And then transfer the flash.img into files by running: */
/* $IDF_PATH/components/fatfs/fatfsparse.py flash.img */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_system.h"

#include "mpu6050_i2c.h"

#define BUTTON_PIN 10
#define LED_PIN 11

#define DELAY_PERIOD_MEASURE 1000
#define QUEUE_LENGTH 5
#define NO_MEASUREMENTS 10

const char *base_path = "/fat";
const char *filename = "/fat/data.csv";

static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;

bool led_light = false;

/*-----------------------------------------------------------*/

/* declare tasks */
void measureTask(void *pvParameters);
void storeTask(void *pvParameters);

/* Semaphore for interrupt */
SemaphoreHandle_t isrSemaphore = NULL;

/* Queue for data exchange */
QueueHandle_t dataQueue = NULL;

/*-----------------------------------------------------------*/
/* ISR */
void IRAM_ATTR isrHandler() 
{
	xSemaphoreGiveFromISR(isrSemaphore, NULL);
}

/*-----------------------------------------------------------*/
bool mountFat() 
{
    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 4,
            .format_if_mount_failed = false,
            .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount_rw_wl(base_path, "storage", &mount_config, &s_wl_handle);

    if (err != ESP_OK) {
        printf("problem mounting\n");
        return false;
    }
    return true;
}

void unmountFat() 
{
    /* Unmount FATFS */
    ESP_ERROR_CHECK(esp_vfs_fat_spiflash_unmount_rw_wl(base_path, s_wl_handle));
}

/*-----------------------------------------------------------*/
/* Here is the main! */
void app_main(void)
{
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

    dataQueue = xQueueCreate( QUEUE_LENGTH, NO_MEASUREMENTS*sizeof( float ) );

	xTaskCreate( measureTask, "Measure Task", 4096, NULL, 1, NULL );
	xTaskCreate( storeTask, "Store Task", 4096, NULL, 2, NULL );
}

/*-----------------------------------------------------------*/
float mpuReadTemperatur() {
    uint8_t data[2];
    mpu6050_read_register(MPU6050_TEMP_HIGH, data, 2);

    int16_t temperature = data[0] << 8 | data[1];
    // use equation from page 30 of datasheet
    float conversion = ((float)temperature)/340 + 36.53f;

    printf("Temperature is %f\n", conversion);
    return conversion;
}

void measureTask(void *pvParameters)
{
    ESP_ERROR_CHECK(i2c_master_init());
    ESP_ERROR_CHECK(mpu6050_check());

    // enable sensor
    ESP_ERROR_CHECK(mpu6050_write_register(MPU6050_PWR_MGMT_1, 0x0));

    float measurements[NO_MEASUREMENTS];
    uint8_t measNb = 0;
    while (1) {
/* TODO: begin */
        // read 10 measurements and send to queue
        // after that, clear and fill array again
        // discard measurements if queue is full
        // start with uncommenting this line
        //measurements[measNb++] = mpuReadTemperatur();
/* TODO: end */
        vTaskDelay(DELAY_PERIOD_MEASURE / portTICK_PERIOD_MS);
    }
}

/*-----------------------------------------------------------*/
void storeTask(void *pvParameters)
{
    if (!mountFat()) {
        vTaskDelete(NULL);
        return;
    }

    while (1) {
		/* wait to take semaphore that will be given by isr */
		xSemaphoreTake(isrSemaphore, portMAX_DELAY);

		printf("Interrupt\n");
		/* change led status */
		uint32_t led = gpio_get_level((gpio_num_t) LED_PIN);
		gpio_set_level((gpio_num_t) LED_PIN, !led);

        /* now get data from queue*/
        float data[NO_MEASUREMENTS];
/* TODO: begin */
        // check queue and retrieve as long as something in it
        // open file and write data values as text (csv) to file
        // close file afterwards
/* TODO: end */
    }
}