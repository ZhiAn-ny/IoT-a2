# Imports
import threading as th
import time
from tkinter import *
from gui.Plotter import Plotter

class SmartBridgeGui:
    __win = Tk()
    __plot = Plotter()

    def __init__(self):
        self.__win.title('Smart Bridge Control Interface')
        self.__win.geometry("500x500")

        width = str(int(self.__win.winfo_screenwidth()/3*2))
        height = str(int(self.__win.winfo_screenheight()/3*2))

        self.__win.geometry(width + "x" + height)

        self.show_plot();

        # t = th.Thread(target=self.update_plot)
        # t.start()

        self.__win.mainloop()

    def show_plot(self):
        self.__plot.add_plot(self.__win)

    def update_plot(self, data: float):
        self.__plot.add_data(data)

        



    
