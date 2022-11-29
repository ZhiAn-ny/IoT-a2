#ifndef __MOTOR__ 
#define __MOTOR__

#include <Servo.h>
#include "config.h"

class Motor {
private:
    Servo valve_;    
    int opening_degrees_;      

public:
    void init();
    int get_opening_degrees();
    void open_valve(int degrees);
 
};

#endif
