#ifndef _SMART_CM_LIQUID_CRYSTAL_H_
#define _SMART_CM_LIQUID_CRYSTAL_H_

#include <LiquidCrystal.h>
#include "config.h"

using namespace pins::lcd;

class LCD {
    private:
        LiquidCrystal* lcd = new LiquidCrystal(RS, E, D4, D5, D6, D7);

    public:
        void init();
        void print_pre_alarm();
        void print_alarm();
        void print_normal();
        void print_water_distance(float n);
        void clear();

};


#endif // !_SMART_CM_LIQUID_CRYSTAL_H_