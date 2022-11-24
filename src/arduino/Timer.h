#ifndef __TIMER__
#define __TIMER__
#include <Timer.h>
class Timer {
    
public:  
  Timer();
  void setupFreq(int freq);  
  /* period in ms */
  void setupPeriod(int period);  
  void waitForNextTick();

};


#endif
