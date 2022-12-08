# Imports
from matplotlib import animation, style
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk

from board.ArduinoBoard import ArduinoBoard

style.use("ggplot")

class SmartBridgeGui:
    __win: tk.Tk = tk.Tk()
    __fig: Figure = None
    __plot = None

    def __animate(self, i):
        pullData = open('src\pc\\board\WaterSampling.data','r').read()
        dataArray = pullData.split('\n')
        yar=[]
        for eachLine in dataArray:
            if len(eachLine)>1:
                yar.append(float(eachLine))
        self.__plot.clear()
        self.__plot.plot(yar)

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

    def __init__(self):
        self.__create_window()
        self.__add_plotter()
        self.__anm = animation.FuncAnimation(self.__fig,
                                             self.__animate,
                                             interval=100)

        self.__win.mainloop()
