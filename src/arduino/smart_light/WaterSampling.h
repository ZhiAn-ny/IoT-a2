#ifndef _SMART_CM_SCHEDULER_WATER_SAMPLING_TASK_H_
#define _SMART_CM_SCHEDULER_WATER_SAMPLING_TASK_H_

#include "config.h"
#include "Task.h"
#include "Sonar.h"

namespace bridge_scheduling
{
    namespace tasks 
    {

        class WaterSamplingTask : public Task {
            private:
                Sonar* sonar_ = nullptr;
                float* water_surface_dist_ = nullptr;

            public:
                WaterSamplingTask(float* water_level);
                void init(int period);
                void tick();
        };

    }
} // namespace bridge_scheduling

#endif // !_SMART_CM_SCHEDULER_WATER_SAMPLING_TASK_H_
