#ifndef __SONAR__ 
#define __SONAR__

class Sonar {
public:
  Sonar( int trigPin,int echoPin);
  float getDistance();   
  protected:
  int trigPin,echoPin;  
};
#endif
