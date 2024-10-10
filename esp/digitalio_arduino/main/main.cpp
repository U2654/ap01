#include "Arduino.h"

#define BUTTON_PIN 10
#define LED_PIN 11

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
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
}
