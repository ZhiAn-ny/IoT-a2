#ifndef _SMART_CM_ILLUMINATIO_SYSTEM_H_
#define _SMART_CM_ILLUMINATIO_SYSTEM_H_

#include "Scheduler.h"
#include "SmartLightTask.h"
#include "Led.h"

namespace bridge_control {
    namespace illumination {

        class IlluminationSystem {
            private:
                bool active_;
                Light* bridge_lights = nullptr;
                Task* smart_light_task = nullptr;

            public:
                IlluminationSystem();
                ~IlluminationSystem();

                void init(Scheduler* sched);
                void turnOff();
                void turnOn();
        };

    }
}

#endif // !_SMART_CM_ILLUMINATIO_SYSTEM_H_