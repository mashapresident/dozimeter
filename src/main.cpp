#include <Arduino.h>
#include "dosimeter_20.h"
dosimeter_20 dos = dosimeter_20(7);

void setup() {
    Serial.begin(9600);
}

void loop() {
    dos.begin();
    Serial.println(dos.calculate_radiation());
}