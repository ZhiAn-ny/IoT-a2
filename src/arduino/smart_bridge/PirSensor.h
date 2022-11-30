#ifndef __PIRSENSOR__ 
#define __PIRSENSOR__

class PirSensor {
public:
 PirSensor(int pin);
  bool detect();   
protected:
  int pin;  
};
#endif
