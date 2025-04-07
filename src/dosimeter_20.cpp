#include "dosimeter_20.h"

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
    Serial.begin(9600);
    pinMode(this->_pin, INPUT_PULLUP);
}


float dosimeter_20::get_radiation() {
    return cpm;
}
int dosimeter_20::get_cpm() {
  this->cpm = 0;
  for (int i = 0; i < 200; i++){
    if (digitalRead(this->_pin) == HIGH){
      this->counter();
    }
    delay(5);
   }
   return this->cpm;
}
void dosimeter_20::counter() {
    this->cpm++;
}
