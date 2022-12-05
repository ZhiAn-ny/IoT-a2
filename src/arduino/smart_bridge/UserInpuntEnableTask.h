#ifndef _SMART_BRIDGE_USER_INPUT_ENABLE_TASK_H_
#define _SMART_BRIDGE_USER_INPUT_ENABLE_TASK_H_

#include <Arduino.h>
#include "Task.h"
#include "config.h"
#include "ButtonImpl.h"

namespace bridge_scheduling {
    namespace tasks {

        class InputEnableTask : public Task {
            private:
                bool* enabled_ = nullptr;
                bool prev_btn_val_ = false;
                Button* button_ = nullptr;

            public:
                InputEnableTask(bool* enable);
                ~InputEnableTask();

                void init(int period);
                void tick();
        };

    }
}

#endif // !_SMART_BRIDGE_USER_INPUT_ENABLE_TASK_H_