#ifndef _SMART_BRIDGE_BLINK_TASK_H_
#define _SMART_BRIDGE_BLINK_TASK_H_

#include "../Task.h"
#include "../Led.h"

namespace bridge_scheduling {
    namespace tasks {

        class BlinkTask : public Task {
        private:
            int pin_;
            Light* led_;
            enum { ON, OFF } state_;

        public:
            BlinkTask(int pin);
            void init(int period);
            void tick();
        };

    }
}


#endif // !_SMART_BRIDGE_BLINK_TASK_H_