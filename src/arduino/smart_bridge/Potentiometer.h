#ifndef __POTENTIOMETER_H__
#define __POTENTIOMETER_H__

#include "config.h"

class Potentiometer {
private:
    int pin_;

public:
    Potentiometer(int pin);
    ~Potentiometer();

    int read();
};

#endif // !__POTENTIOMETER_H__