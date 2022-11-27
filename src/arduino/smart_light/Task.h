#ifndef __TASK__
#define __TASK__

class Task {
  int myPeriod;
  int timeElapsed;
  bool isActive_;
  
public:
  virtual void init(int period){
    myPeriod = period;  
    timeElapsed = 0;
    isActive_ = true;
  }

  virtual void tick() = 0;

  bool updateAndCheckTime(int basePeriod){
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod){
      timeElapsed = 0;
      return true;
    } else {
      return false; 
    }
  }

  bool isActive() 
  { 
    return this->isActive_;
  }

  void setActive() 
  {
    this->isActive_ = true;
  }

  void setInactive()
  {
    this->isActive_ = false;
  }
  
};

#endif

