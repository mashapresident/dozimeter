#include <Arduino.h>
#include "ArduinoLowPower.h"
#include "calculator.h"
volatile int cpm = 0;
volatile float rad_value;
const float koef = 0.0054;
calculator calculator;
static void counter();

void setup() {
    Serial.begin(9600);
    LowPower.attachInterruptWakeup(7, counter, RISING);
}

void loop() {
    for (int i = 0; i < 60; i++) {
        LowPower.deepSleep(60000);
        rad_value = static_cast<float>(cpm) * koef;
        if (calculator.set_rad_value(rad_value, i)) {
            Serial.println(cpm);
            Serial.println(rad_value);
        }
        else {
            Serial.println("error");
        }
        cpm = 0;
    }
}

static void counter() {
    cpm++;
}