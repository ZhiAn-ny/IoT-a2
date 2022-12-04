#ifndef SMART_CM_WATER_MONITOR_H_
#define SMART_CM_WATER_MONITOR_H_

#include "Led.h"
#include "WaterSampling.h"
#include "BlinkTask.h"
#include "config.h"
#include "Sonar.h"
#include "Scheduler.h"
#include "Lcd.h"
#include "Button.h"
#include "BridgeValve.h"

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
        float water_surface_dist_ = 150.0;

        Light* green_ = nullptr;
        Light* red_ = nullptr;
        //Button button_;
        LCD display_;

        BridgeValve valve_controller_;

        Task*  water_sampling_task_ = nullptr;
        Task* led_blink_task_ = nullptr;

        SystemState state_ = SystemState::Undefined;

        /**
         * Checks the distance from the water surface
         * @return the system state
         */
        SystemState get_system_state();

        /**
         * @param green - the pin on which the green light is connected
         * @param red - the pin on which the red light is connected
         */
        void init_lights(int green, int red);
        void set_tasks(Scheduler* sched);

        void set_system_state_normal();
        void set_system_state_prealarm();
        void set_system_state_alarm();

        void update_state();

      public:
        WaterMonitorController();
        ~WaterMonitorController();

        void init(Scheduler* sched);
        void loop();
        void handle_current_state();
        bool is_in_alarm_state();
    };

  }
}

#endif // !SMART_CM_WATER_MONITOR_H_