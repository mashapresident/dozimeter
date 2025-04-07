#include "dosimeter_20.h"
#include "ArduinoLowPower.h"
static volatile int __pin;             // GPIO for an external interrupt
static int cpm = 0;                    // Counts per Minute variable
static unsigned long now = millis();   // Debounce comparison variable
static unsigned long meas_start = now;

dosimeter_20::dosimeter_20(int pin)
{
    _pin = pin;
    __pin = _pin;
}

void dosimeter_20::begin() {
    pinMode(this->_pin, INPUT_PULLUP);
    LowPower.attachInterruptWakeup(_pin, counter, RISING);
}

int dosimeter_20::get_cpm() {

}
void dosimeter_20::counter() {
    this->cpm++;
}
