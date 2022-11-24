#ifndef __MOTOR__ 
#define __MOTOR__
#include <Servo.h>
class Motor {
public:
 Motor(int motorPin,int potPin );
  float valve_opened();     
protected:
  int motorPin,potPin;  
};
#endif
