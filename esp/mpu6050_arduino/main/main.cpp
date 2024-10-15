
#include "Arduino.h"
#include "basicMPU6050.h"

#define BUTTON_PIN 10
#define LED_PIN 11

basicMPU6050<> imu;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  imu.setup();
}

void loop() {
  int currentState = digitalRead(BUTTON_PIN);
  if (currentState == HIGH)
  {
    Serial.println("HIGH");
    digitalWrite(LED_PIN, LOW);
  }
  else
  {
    Serial.println("LOW");
    digitalWrite(LED_PIN, HIGH);
  }
  delay(1000);
  Serial.println(imu.temp());
}
