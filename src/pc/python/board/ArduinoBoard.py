# Import libraries
import serial as arv
import threading as th
import time

MAX_WATER_LEVEL = 10

class ArduinoBoard:
    __arduino: arv.Serial = arv.Serial(port='COM3', baudrate=19200, timeout=.1)
    __state: str = "Undefined"
    __mode: str = "AUTO"

    def __read(self):
        data = self.__arduino.readline().decode('utf-8')
        return data.split("\r")[0]

    def __sample_water(self, water_level: float):
        with open('src\pc\python\\board\WaterSampling.data', 'r') as fin:
            data = fin.read().splitlines(True)

        if len(data) > 99:
            with open('src\pc\python\\board\WaterSampling.data', 'w') as fout:
                fout.writelines(data[1:])

        file = open('src\pc\python\\board\WaterSampling.data', 'a')
        file.write(str(water_level) + "\n")
        file.close()

    def __log_sys_info(self):
        file = open('src\pc\python\\board\log.data', 'w')
        json = '{"state" : "' + self.__state + '", "mode" : "' + self.__mode + '"}'
        file.write(json)
        file.close()

    def __arduino_output_handler(self):
        while True:
            cmd = self.__read()

            if cmd.startswith("W:"):
                wlv = cmd.split(":")[1]
                if (wlv == "" or float(wlv) < MAX_WATER_LEVEL): continue
                self.__sample_water(float(wlv))

            elif cmd.startswith("STATE:"):
                state = cmd.split(":")[1]
                if (state != ""): self.__state = state 
            
            elif cmd.startswith("MODE:"):
                mode = cmd.split(":")[1]
                if (mode != ""): self.__mode = mode

            self.__log_sys_info();
            time.sleep(0.1)

    def __init__(self):
        f = open("src\pc\python\\board\WaterSampling.data", 'w')
        f.write("") # Delete file content
        f.close()

        t = th.Thread(target=self.__arduino_output_handler)
        t.start()
