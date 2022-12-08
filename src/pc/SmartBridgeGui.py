# Imports
from matplotlib import animation, figure, style
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk
import threading as th
import numpy as np
import time

from board.ArduinoBoard import ArduinoBoard

style.use("ggplot")

class SmartBridgeGui:
    __win: tk.Tk = tk.Tk()
    __fig: Figure = None
    __plot = None
    __uno: ArduinoBoard = ArduinoBoard()
    __anm = None

    def __animate(self, i):
        pullData = open('src\pc\plotter\WaterSampling.txt','r').read()
        dataArray = pullData.split('\n')
        xar=[]
        yar=[]
        for eachLine in dataArray:
            if len(eachLine)>1:
                x,y = eachLine.split(',')
                xar.append(int(x))
                yar.append(int(y))
        self.__plot.clear()
        self.__plot.plot(xar,yar)

    def __add_plotter(self):
        self.__fig = Figure(figsize=(5,4), dpi=100)
        self.__plot = self.__fig.add_subplot(111)

        canvas = FigureCanvasTkAgg(self.__fig, master = self.__win)
        canvas.draw()
        canvas.get_tk_widget().pack(side = tk.BOTTOM, 
                                    fill = tk.BOTH, 
                                    expand = True)

    def __create_window(self):
        self.__win.title('Smart Bridge Control Interface')
        self.__win.geometry("500x500")

        width = str(int(self.__win.winfo_screenwidth()/3*2))
        height = str(int(self.__win.winfo_screenheight()/3*2))

        self.__win.geometry(width + "x" + height)

    # def __handle_arduino_data(self, data: str):
    #     print(data)
    #     if data.startswith("W:"):
    #         wlv = data.split(":")[1]
    #         #self.__plot.add_data(float(wlv))

    # def __arduino_read(self):
    #     print("Thread started")
    #     while True:
    #         str = self.__uno.read()
    #         if (str == ""): return
    #         self.__handle_arduino_data(str)

    def __init__(self):
        self.__create_window()
        print("Win created")
        self.__add_plotter()

        self.__anm = animation.FuncAnimation(self.__fig, self.__animate, interval=100)

        # t = th.Thread(target=self.__arduino_read)
        # t.start()

        # while (t.is_alive() == False):
        #     time.sleep(1)

        print("Thread started?")
        print("Starting mainloop...")
        self.__win.mainloop()



        

if __name__ == "__main__":
    view = SmartBridgeGui()
