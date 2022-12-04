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

#define DEBUG_SONAR
#define DEBUG_SERVO
//  #define USE_NEW_PING

#define USE_BRIDGE_VALVE



// THE PIN THAT MUST BE USED IN THE CIRCUIT
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
        const unsigned int green = A4;
        const unsigned int red = 13;
        const unsigned int bridge = 10;
    }

    namespace sonar {
        const unsigned int trigger = 6;
        const unsigned int echo = 7;
        const unsigned int max_distance = 200;
    }

    namespace pir {
        const unsigned int pir = 8;
    }

    namespace user_btn {
        const unsigned int btn = 0;
    }

    namespace ls {
        const unsigned int ls = A1;
        // Minimum light level under which the light can be turned on
        const unsigned int THl = 50;
    }

    namespace pot {
        const unsigned int pot = A0;
    }

    namespace servo {
        const unsigned int servo = 9;
    }
}

namespace bridge_control {

    namespace water_level {
        const float water_level_1 = 150; // 150 cm
        const float water_level_2 = 70;
        const float water_level_max = 10;
    }

    namespace sampling_periods {
        const int pe_normal = 1000;
        const int pe_prealarm = 500;
        const int pe_alarm = 200;
    }
}

#endif // !__CONFIG__
