#ifndef __POTENTIOMETER__ 
#define __POTENTIOMETER__

#include "config.h"

class Potentiometer {
public:
	Potentiometer(int pin);
	int pot_value();
    
private:
	int pin;
    int current;
};

#endif // !__POTENTIOMETER__
