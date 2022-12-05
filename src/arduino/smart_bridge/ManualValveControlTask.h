#ifndef _SMART_BRIDGE_MANUAL_VALVE_CONTROL_TASK_H_
#define _SMART_BRIDGE_MANUAL_VALVE_CONTROL_TASK_H_

#include "Task.h"
#include "Potentiometer.h"
#include "Motor.h"

namespace bridge_scheduling {
    namespace tasks {

        class ManualValveControlTask : public Task {
        private:
            Potentiometer* pot_ = nullptr;
            Motor* valve_ = nullptr;

        public:
            ManualValveControlTask(Motor* valve);

            void init(int period);
            void tick();
        };

    }
}

#endif // !_SMART_BRIDGE_MANUAL_VALVE_CONTROL_TASK_H_