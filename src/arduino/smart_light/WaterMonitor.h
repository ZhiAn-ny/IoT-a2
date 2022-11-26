#ifndef SMART_CM_WATER_MONITOR_H_
#define SMART_CM_WATER_MONITOR_H_

#include "Led.h"
#include "Task.h"
#include "config.h"
#include "Sonar.h"
#include "Scheduler.h"

namespace bridge_control {
  namespace water_monitor {

    enum class SystemState {
      Normal,
      PreAlarm,
      Alarm
    };

    class WaterMonitorController {
      private:
        const float water_level_1_ = 100; // 100 cm
        const float water_level_2_ = 50;
        const float water_level_max_ = 30;

        const int pe_normal_ = 500; // 500 millis
        const int pe_prealarm_ = 500; // 500 millis
        const int pe_alarm_ = 500; // 500 millis

        Led* green_ = nullptr;
        Led* red_ = nullptr;

        Sonar* sonar_ = nullptr;

        SystemState state_ = SystemState::Normal;

        SystemState get_system_state();

        /**
         * @params green - the pin on which the green light is connected
         * @params red - the pin on which the red light is connected
         */
        void init_lights(int green, int red);

        void normal_state_handler();
        void prealarm_state_handler();
        void alarm_state_handler();

      public:
        WaterMonitorController();
        ~WaterMonitorController();

       void init();
    };

  }
}

#endif // !SMART_CM_WATER_MONITOR_H_