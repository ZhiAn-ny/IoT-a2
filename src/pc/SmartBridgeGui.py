# Imports
import threading as th
import time
from tkinter import *

from plotter.Plotter import Plotter
from board.ArduinoBoard import ArduinoBoard

class SmartBridgeGui:
    __win: Tk = Tk()
    __plot: Plotter = Plotter()
    __uno: ArduinoBoard = ArduinoBoard()

    def __show_plot(self):
        self.__plot.add_plot(self.__win)

    def __create_window(self):
        self.__win.title('Smart Bridge Control Interface')
        self.__win.geometry("500x500")

        width = str(int(self.__win.winfo_screenwidth()/3*2))
        height = str(int(self.__win.winfo_screenheight()/3*2))

        self.__win.geometry(width + "x" + height)

        self.__show_plot();

    def __handle_arduino_data(self, data: str):
        print(data)
        if data.startswith("W:"):
            wlv = data.split(":")
            self.__plot.add_data(wlv[1])

    def __arduino_read(self):
        print("Thread started")
        while True:
            str = self.__uno.read()
            if (str == ""): return
            self.__handle_arduino_data(str)

    def __init__(self):
        self.__create_window()
        print("Win created")

        t = th.Thread(target=self.__arduino_read)
        t.start()

        while (t.is_alive() == False):
            time.sleep(1)

        print("Thread started?")
        print("Starting mainloop...")
        self.__win.mainloop()



        

if __name__ == "__main__":
    view = SmartBridgeGui()
