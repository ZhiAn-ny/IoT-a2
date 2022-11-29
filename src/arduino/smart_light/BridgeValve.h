#ifndef _SMART_CM_WATER_CONTROL_VALVE_H_
#define _SMART_CM_WATER_CONTROL_VALVE_H_

#include "RegulateValveTask.h"
#include "Motor.h"

using namespace pins::servo;

namespace bridge_control {
    namespace bridge_valve {

        class BridgeValve {
        private:
            Motor valve_;
            Task* regulate_on_water_level = nullptr;
            bool is_auto_ = true;;

        public:
            void init(float* water_level);
            bool is_auto();
            void activate();
            void deactivate();
            int get_opening_degrees();
            void open_valve(int degrees);


        };

    }
}

#endif // !_SMART_CM_WATER_CONTROL_VALVE_H_