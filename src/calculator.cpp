#include "calculator.h"

calculator::calculator() {
    rad_values_per_hour = new float[60];
    for (int i = 0; i < 60; i++) {
        rad_values_per_hour[i] = 0.0;
    }
}
void calculator::clear_rad_values() {
    for (int i = 0; i < 60; i++) {
        rad_values_per_hour[i] = 0.0;
    }
}

float calculator::get_rad_background(){
    return 0.0;
}

bool calculator::set_rad_value(float value, int position){
    if (position >= 0 && position < 60) {
        rad_values_per_hour[position] = value;
        return true;
    }
    else{return false;}
}
calculator::~calculator() {
    delete[] rad_values_per_hour;
}
