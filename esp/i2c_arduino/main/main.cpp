// AI generated code
// Register map of sensor mpu6050: 
// https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf
#include <Arduino.h>
#include <Wire.h>

const int MPU6050_ADDR = 0x68; // I2C address of the MPU6050
const int ACCEL_XOUT_H = 0x3B; // Register address for accelerometer data

void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  // Wake up the MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // Power management register
  Wire.write(0);    // Wake up MPU6050
  Wire.endTransmission(true);
}

void loop() {
  int16_t accelX, accelY, accelZ;
  int16_t gyroX, gyroY, gyroZ;

  // Read accelerometer data
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 14, true);

  accelX = Wire.read() << 8 | Wire.read();
  accelY = Wire.read() << 8 | Wire.read();
  accelZ = Wire.read() << 8 | Wire.read();
  gyroX = Wire.read() << 8 | Wire.read();
  gyroY = Wire.read() << 8 | Wire.read();
  gyroZ = Wire.read() << 8 | Wire.read();

  // Print data to Serial Monitor
  Serial.print("Accel X: "); Serial.print(accelX);
  Serial.print(" | Accel Y: "); Serial.print(accelY);
  Serial.print(" | Accel Z: "); Serial.println(accelZ);
  Serial.print("Gyro X: "); Serial.print(gyroX);
  Serial.print(" | Gyro Y: "); Serial.print(gyroY);
  Serial.print(" | Gyro Z: "); Serial.println(gyroZ);

  delay(500);
}