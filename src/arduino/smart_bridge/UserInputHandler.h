#ifndef _SMART_CM_USER_INPUT_H_
#define _SMART_CM_USER_INPUT_H_

#include "Scheduler.h"
#include "UserInpuntEnableTask.h"
#include "ButtonImpl.h"

namespace bridge_control {
    namespace user_input {

        class UserInputHandler{
        private:
            bool enabled_;
            Task* button_pressed_task_ = nullptr;

        public:
            UserInputHandler();
            ~UserInputHandler();

            bool isEnabled();
            void init(Scheduler* sched);



        };
    
    }
}

#endif // !_SMART_CM_USER_INPUT_H_
