#include <Arduino.h>
#include "dosimeter_20.h"

void setup() {
    dosimeter_20 dos = dosimeter_20(7);
    Serial.begin(9600);
}

void loop() {
    dos.begin();
    Serial.println(dos.calculate_radiation());
}