# Import libraries
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import numpy as np
from board.ArduinoBoard import MAX_WATER_LEVEL as MAX_LVL

class Plotter:
    __yy = np.array([MAX_LVL])
    __fig = None
    __water_plot = None

    def __init__(self):
        self.__fig = Figure(dpi=100)
        self.__water_plot = self.__fig.add_subplot()
        self.__water_plot.plot(self.__yy)

    def add_plot(self, parent):
        canvas = FigureCanvasTkAgg(self.__fig, master = parent)
        canvas.draw()

        canvas.get_tk_widget().pack()

    def add_data(self, data: float):
        self.__water_plot.plot(np.append(self.__yy, data))




