// Code generated with AI help
#include "driver/i2c.h"
#include "esp_log.h"

#define I2C_MASTER_SCL_IO           22    // GPIO number for I2C master clock
#define I2C_MASTER_SDA_IO           23    // GPIO number for I2C master data
#define I2C_MASTER_NUM              I2C_NUM_0  // I2C port number for master dev
#define I2C_MASTER_FREQ_HZ          100000     // I2C master clock frequency
#define I2C_MASTER_TX_BUF_DISABLE   0          // I2C master doesn't need buffer
#define I2C_MASTER_RX_BUF_DISABLE   0          // I2C master doesn't need buffer
#define MPU6050_SENSOR_ADDR         0x68       // I2C address of MPU6050
#define MPU6050_WHO_AM_I_REG_ADDR   0x75       // Register address for WHO_AM_I

#define DELAY_PERIOD                500

static const char *TAG = "MPU6050";

// Function to initialize the I2C master interface
static esp_err_t i2c_master_init(void) {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    esp_err_t err = i2c_param_config(I2C_MASTER_NUM, &conf);
    if (err != ESP_OK) {
        return err;
    }
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

// Function to read a register from the MPU6050
static esp_err_t mpu6050_read_register(uint8_t reg_addr, uint8_t *data, size_t len) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MPU6050_SENSOR_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg_addr, true);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MPU6050_SENSOR_ADDR << 1) | I2C_MASTER_READ, true);
    i2c_master_read(cmd, data, len, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t err = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return err;
}

// Function to initialize the MPU6050
static esp_err_t mpu6050_check(void) {
    uint8_t who_am_i = 0;
    esp_err_t err = mpu6050_read_register(MPU6050_WHO_AM_I_REG_ADDR, &who_am_i, 1);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read WHO_AM_I register");
        return err;
    }
    if (who_am_i != 0x68) {
        ESP_LOGE(TAG, "WHO_AM_I register value is incorrect: 0x%02x", who_am_i);
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "MPU6050 works...");
    return ESP_OK;
}

void app_main(void) {
    ESP_ERROR_CHECK(i2c_master_init());

    while (1) {
        ESP_ERROR_CHECK(mpu6050_check());
        vTaskDelay(DELAY_PERIOD / portTICK_PERIOD_MS);
    }
}
