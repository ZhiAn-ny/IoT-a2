# Import libraries
import serial as arv
import time

MAX_WATER_LEVEL = 200.0

class ArduinoBoard:
    __arduino: arv.Serial = arv.Serial(port='COM3', baudrate=19200, timeout=.1)
    __last_read: float = MAX_WATER_LEVEL

    def get_water_level(self):
        str = self.read()

        if (str.startswith("W:")):
            water = str.split(":", 1)
            self.__last_read = float(water)
        
        print(self.__last_read)
        return self.__last_read

    def read(self):
        data = self.__arduino.readline().decode('utf-8')
        return data.split("\r")[0]
