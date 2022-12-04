#include "Motor.h"


Motor::Motor() {
    this->valve_.attach(pins::servo::servo);
    this->valve_.write(0);
    this->opening_degrees_ = 0;
}

void Motor::attach()
{
    this->valve_.attach(pins::servo::servo);
}

void Motor::detach()
{
    if (this->valve_.attached()) 
        this->valve_.detach();
}

void Motor::open_valve(int degrees)
{
    int pulse_width = 0;
    pulse_width = map(degrees, 0, 181, 750, 2251);

    if (degrees <= 0) {
        pulse_width = 750;
    }
    if (degrees >= 180) {
        pulse_width = 2250;
    }

#ifdef DEBUG_SERVO
    Serial.print("Degrees: "); Serial.print(degrees);
    Serial.print(" | PW: "); Serial.println(pulse_width);
#endif // !DEBUG_SERVO

    this->valve_.write(pulse_width);
    this->opening_degrees_ = degrees;

}

int Motor::get_opening_degrees()
{
    return this->opening_degrees_;
}


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
