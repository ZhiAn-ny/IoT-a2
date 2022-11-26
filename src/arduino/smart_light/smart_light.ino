#include "Scheduler.h"
#include "Arduino.h"
#include "SmartLightTask.h"
Scheduler sched;
void setup(){

  Serial.begin(9600);
  sched.init(100);
 
  Task* t0 = new SmartLightTask();
  t0->init(100);

  sched.addTask(t0);
   
}

void loop(){
  sched.schedule();
}
