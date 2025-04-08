#ifndef CALCULATOR_H
#define CALCULATOR_H

class calculator {
    public:
      calculator();
      float get_rad_background();
      bool set_rad_value(float value, int position);
      void clear_rad_values();
      ~calculator();
    private:
      float *rad_values_per_hour;
};



#endif
