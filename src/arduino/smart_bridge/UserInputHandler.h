#ifndef _SMART_CM_USER_INPUT_H_
#define _SMART_CM_USER_INPUT_H_

#include "Scheduler.h"
#include "UserInpuntEnableTask.h"
#include "ManualValveControlTask.h"
#include "ButtonImpl.h"

namespace bridge_control {
    namespace user_input {

        class UserInputHandler{
        private:
            bool enabled_ = false;
            Motor* valve_ = nullptr;
            Task* input_enable_task_ = nullptr;
            Task* command_valve_ = nullptr;

        public:
            UserInputHandler();
            ~UserInputHandler();

            bool isEnabled();
            void init(Scheduler* sched, Motor* valve);

            void disable();
            void enable();

        };
    
    }
}

#endif // !_SMART_CM_USER_INPUT_H_
