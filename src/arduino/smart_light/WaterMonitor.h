#ifndef SMART_CM_WATER_MONITOR_H_
#define SMART_CM_WATER_MONITOR_H_

#include "Led.h"
#include "WaterSampling.h"
#include "BlinkTask.h"
#include "config.h"
#include "Sonar.h"
#include "Scheduler.h"

using namespace bridge_scheduling::tasks;

namespace bridge_control {
  namespace water_monitor {

    enum class SystemState {
      Undefined,
      Normal,
      PreAlarm,
      Alarm
    };

    class WaterMonitorController {
      private:
        const float water_level_1_ = 150; // 100 cm
        const float water_level_2_ = 70;
        const float water_level_max_ = 50;

        const int pe_normal_ = 5000; // 500 millis
        const int pe_prealarm_ = 2000; // 300 millis
        const int pe_alarm_ = 500; // 100 millis

        float water_surface_dist_ = 150.0;

        Light* green_ = nullptr;
        Light* red_ = nullptr;

        Task*  water_sampling_task_ = nullptr;
        Task* led_blink_task_ = nullptr;

        SystemState state_ = SystemState::Undefined;

        SystemState get_system_state();

        /**
         * @params green - the pin on which the green light is connected
         * @params red - the pin on which the red light is connected
         */
        void init_lights(int green, int red);

        void set_system_state_normal();
        void set_system_state_prealarm();
        void set_system_state_alarm();

      public:
        WaterMonitorController();
        ~WaterMonitorController();

        void init(Scheduler* sched);
        void handle_current_state();
        bool is_in_alarm_state();
    };

  }
}

#endif // !SMART_CM_WATER_MONITOR_H_