#ifndef _SMART_CM_LIQUID_CRYSTAL_H_
#define _SMART_CM_LIQUID_CRYSTAL_H_

#include <LiquidCrystal.h>

#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2

#define N_COLS 16
#define N_ROWS 2

class LCD {
    private:
        LiquidCrystal* lcd = new LiquidCrystal(RS, E, D4, D5, D6, D7);

    public:
        void init();
        void print(int n);

};


#endif // !_SMART_CM_LIQUID_CRYSTAL_H_