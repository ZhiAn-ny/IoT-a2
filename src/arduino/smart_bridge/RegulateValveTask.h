#ifndef _SMART_CM_WATER_MONITOR_REGULATE_VALVE_TASK_H_
#define _SMART_CM_WATER_MONITOR_REGULATE_VALVE_TASK_H_

#include "config.h"
#include "Task.h"

namespace bridge_scheduling {
    namespace tasks {

        class RegulateValveTask: public Task {
        private:
            Motor* valve_ = nullptr;
            float* water_distance_ = nullptr;

            int get_degrees();
        
        public:
            RegulateValveTask(Motor* valve, float* water_level);
            void init(int period);
            void tick();
        };

    }
}


#endif// !_SMART_CM_WATER_MONITOR_REGULATE_VALVE_TASK_H_