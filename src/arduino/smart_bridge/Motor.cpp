#include "Motor.h"

// #define DEBUG

void Motor::attach()
{
    this->valve_.attach(pins::servo::servo);
    this->valve_.write(0);
    this->opening_degrees_ = 0;
}

void Motor::detach()
{
    if (this->valve_.attached()) 
        this->valve_.detach();
}

void Motor::open_valve(int degrees)
{
#ifdef DEBUG
    Serial.print("Opening: "); Serial.println(degrees);
#endif // !DEBUG

    if (degrees <= 0) {
        this->valve_.write(750);
        this->opening_degrees_ = 0;
        return;
    }
    if (degrees >= 180) {
        this->valve_.write(2250);
        this->opening_degrees_ = 180;
        return;
    }

    int x = degrees * 2250 / 180;
    this->valve_.write(x);
    this->opening_degrees_ = degrees;

}

int Motor::get_opening_degrees()
{
    return this->opening_degrees_;
}


// Motor::Motor(int potPin,int motorPin){
//   this->potPin = potPin; 
//   this->motorPin = motorPin; 
 
// }


// float valve_opened(){
//   int potPin,motorPin;
//    int val;    // variable to read the value from the analog pin
//    val = analogRead(potPin);            // reads the value of the potentiometer (value between 0 and 1023)
//    val = map(val, 0, 1023, 0, 180);  
//     Servo myservo;  // create servo object to control a servo
//   myservo.attach(motorPin);  // attaches the servo on pin 9 to the servo object// scale it to use it with the servo (value between 0 and 180)
//    myservo.write(val);                  // sets the servo position according to the scaled value
//    delay(15);                           // waits for the servo to get there
//    if(val==0)
//     Serial.println("valve opened");
//    else if(val==180)
//      Serial.println("valve closed");
// }
