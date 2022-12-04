#ifndef __MOTOR__ 
#define __MOTOR__

// #include <Servo.h>
#include <ServoTimer2.h>
#include "config.h"

class Motor {
private:
    ServoTimer2 valve_;    
    int opening_degrees_;

public:
    Motor();
    void attach();
    void detach();
    int get_opening_degrees();
    void open_valve(int degrees);
};

#endif
