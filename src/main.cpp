#include <Arduino.h>
#include "ArduinoLowPower.h"
volatile int cpm = 0;

void counter();

void setup() {
    Serial.begin(9600);
    LowPower.attachInterruptWakeup(7, counter, RISING);
}

void loop() {
    for (int i = 0; i< 60;i++) {
        LowPower.deepSleep(1000);
    }
    Serial.println(cpm);
    cpm = 0;
}

void counter() {
    cpm++;
}