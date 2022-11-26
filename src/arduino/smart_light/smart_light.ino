#include <Arduino.h>
#include "Scheduler.h"
#include "SmartLightTask.h"

Scheduler sched;


void setup(){

  Serial.begin(9600);
  Serial.println("Welcome to Smart Bridge Project");


  sched.init(100);
 
  Task* t0 = new SmartLightTask();
  t0->init(100);

  sched.addTask(t0);
   
}

void loop(){
  sched.schedule();
}
