#ifndef _SMART_CM_WATER_CONTROL_VALVE_H_
#define _SMART_CM_WATER_CONTROL_VALVE_H_

#include "RegulateValveTask.h"
#include "UserInputHandler.h"
#include "Motor.h"
//#include "Potentiometer.h"
#include "Scheduler.h"

using namespace pins::servo;
using namespace pins::user_input;
using namespace bridge_control::user_input;

namespace bridge_control {
    namespace water_monitor {

        class BridgeValve {
        private:
           // Potentiometer* pot(pins::pot::pot);
            Motor* valve_;
            Task* regulate_on_water_level = nullptr;
            
            UserInputHandler* user_input_;            

            bool is_auto_ = true;
            bool is_active_ = false;

        public:
            void init(Scheduler* sched, float* water_level);
            bool is_auto();
            void activate();
            void deactivate();
            int get_opening_degrees();
           // int get_opening_degrees_from_pot();
           // void open_valve(int degrees);

        };

    }
}

#endif // !_SMART_CM_WATER_CONTROL_VALVE_H_