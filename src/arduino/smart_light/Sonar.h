#ifndef __SONAR__ 
#define __SONAR__

class Sonar {
public:
  float getDistance();   
protected:
  int trigPin,echoPin;  
};
#endif
