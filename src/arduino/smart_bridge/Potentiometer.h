#ifndef __POTENTIOMETER__ 
#define __POTENTIOMETER__

class Potentiomter {
public:
	Potentiometer(int pin);
	int pot_value();
private:
	int pin;
};
#endif
