#ifndef GGREG20_V3_DEBOUNCE_TIME
#define GGREG20_V3_DEBOUNCE_TIME 5 // milliseconds
#endif
#ifndef GGREG20_V3_MEASURE_TIME
#define GGREG20_V3_MEASURE_TIME 60000 // milliseconds
#endif
#ifndef GGREG20_V3_CONVFACTOR
#define GGREG20_V3_CONVFACTOR 0.0054
#endif

#ifndef DOSIMETER_20_H
#define DOSIMETER_20_H
#include <iostream>
#include <Arduino.h>
#include <unistd.h>
#include "ArduinoLowPower.h"

class dosimeter_20{
public:
    dosimeter_20(int pin);
    void begin();
    int get_cpm();
    void calculate_multitran();
private:
    float radiation_array[60];
    float SENS;
    void counter();
    int _pin;
    int period = 60;
    int cpm;
};

#endif