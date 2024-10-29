#ifndef MPU6050_I2C_H
#define MPU6050_I2C_H

#include "esp_err.h"

// for sensor communication 
#define I2C_MASTER_SCL_IO           22    // GPIO number for I2C master clock
#define I2C_MASTER_SDA_IO           23    // GPIO number for I2C master data
#define I2C_MASTER_NUM              I2C_NUM_0  // I2C port number for master dev
#define I2C_MASTER_FREQ_HZ          100000     // I2C master clock frequency
#define I2C_MASTER_TX_BUF_DISABLE   0          // I2C master doesn't need buffer
#define I2C_MASTER_RX_BUF_DISABLE   0          // I2C master doesn't need buffer
#define MPU6050_SENSOR_ADDR         0x68       // I2C address of MPU6050
#define MPU6050_WHO_AM_I_REG_ADDR   0x75       // Register address for WHO_AM_I
#define MPU6050_TEMP_HIGH           0X41       // Register address for TEMP_OUT_H
#define MPU6050_TEMP_LOW            0x42       // Register address for TEMP_OUT_L
#define MPU6050_PWR_MGMT_1          0x6B       // Register addresse for PWR_MGTM_1

esp_err_t i2c_master_init(void);
esp_err_t mpu6050_read_register(uint8_t reg_addr, uint8_t *data, size_t len);
esp_err_t mpu6050_write_register(uint8_t reg_addr, uint8_t data);
esp_err_t mpu6050_check(void);

#endif
