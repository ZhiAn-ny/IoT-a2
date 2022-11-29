#ifndef __CONFIG__ 
#define __CONFIG__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h> 

#include "Led.h"
#include "Sonar.h"
#include "Motor.h"
#include "ButtonImpl.h"
#include "LightSensorImpl.h"
#include "PirSensor.h"


// THE PIN THAT MUST BE USED

namespace pins {
    namespace lcd {
        const unsigned int RS = 12;
        const unsigned int E = 11;
        const unsigned int D4 = 5;
        const unsigned int D5 = 4;
        const unsigned int D6 = 3;
        const unsigned int D7 = 2;

        const unsigned int n_cols = 16;
        const unsigned int n_rows = 2;
    }

    namespace led {
        const unsigned int green = 10;
        const unsigned int red = 13;
        const unsigned int bridge = 9;
    }

    namespace sonar {
        const unsigned int trigger = 6;
        const unsigned int echo = 5;
        const unsigned int max_distance = 200;
    }

    namespace pir {
        const unsigned int pir = 8;
    }

    namespace user_btn {
        const unsigned int btn = 1;
    }

    namespace ls {
        const unsigned int ls = A1;
        // Minimum light level under which the light can be turned on
        const unsigned int THl = 50;
    }

    namespace pot {
        const unsigned int pot = A0;
    }
}

// // Pin connected to the light over the bridge
// #define LED_PIN_A 5
// // Pin connected to the green ligh
// #define LED_PIN_B 12
// // Pin connected to the red ligh
// #define LED_PIN_C 13
// #define Pir_PIN 2
// #define LS_PIN A1
// #define S_ECHO_PIN 7
// #define S_TRIG_PIN 8
// #define BUTTON_PIN 11
// #define POT_PIN A0
// // Minimum light level under which the light can be turned on
// #define THl 50

#endif // !__CONFIG__
