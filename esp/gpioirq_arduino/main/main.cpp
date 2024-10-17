#include "Arduino.h"

#define BUTTON_PIN 10
#define LED_PIN 11

bool LED_STATE = false;
int presses = 0;

// IRAM_ATTR moves the code into the ram.
// ESP32 requires this. It is faster, too.
void IRAM_ATTR buttonIrq() {
  presses++; // count presses
  // and invert the led every press
 if (LED_STATE) {
    digitalWrite(LED_PIN, LOW);
    LED_STATE = false;
  }
  else {
    digitalWrite(LED_PIN, HIGH);
    LED_STATE = true;
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  // set interrupt for button
  attachInterrupt(BUTTON_PIN, buttonIrq, FALLING);
  Serial.begin(115200);
}

void loop() {
  // invert the led every 4 seconds
  delay(4000);
  if (LED_STATE) {
    digitalWrite(LED_PIN, LOW);
    LED_STATE = false;
  }
  else {
    digitalWrite(LED_PIN, HIGH);
    LED_STATE = true;
  }
  Serial.println(presses);
}
