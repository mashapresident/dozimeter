#include "dosimeter_20.h"
#include <Arduino.h>
#include <unistd.h>

static volatile int __pin;
dosimeter_20::dosimeter_20(int pin)
{
    _pin = pin;
    __pin = _pin;

}
void dosimeter_20::begin(){
    pinMode(this._pin, INPUT_PULLUP);
    read_radiation();
    Serial.begin(115200);
    pinMode(this._pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(pin), counter, LOW);

void dosimeter_20::read_radiation(){
  for(int i = 0; i < this.period; i++){
    this.radiation[i] = analogRead(this._pin);
    sleep(1);
  }
float dosimeter_20::calculate_radiation(){
  float sum = 0;
  for(int i = 0; i < this.period; i++){
    sum += this.radiation[i];
  }
  float zpm = sum * 0.0057;
  return zpm;
};