#ifndef DOSIMETER_20_H
#define DOSIMETER_20_H
#include <iostream>

class dosimeter_20{
    public:
      dosimeter_20(int pin);
      timer counter(int *period = &_pin);
      void begin();
      void read_radiation();
      float calculate_radiation();
      void calculate_multitran();
    private:
      float radiation_array[60];
      float SENS;
      int _pin;
      int period = 60;
};

#endif
