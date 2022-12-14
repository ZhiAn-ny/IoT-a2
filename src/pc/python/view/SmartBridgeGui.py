# Imports
from matplotlib import animation, style
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter as tk
import threading as th
import time
import json

style.use("ggplot")

class SmartBridgeGui:
    __win: tk.Tk = tk.Tk()
    __fig: Figure = None
    __plot = None
    __state = None
    __mode = None

    def __update_state(self):
        while True:
            pullData = open('src\pc\python\\board\log.data','r').read()
            if pullData == "": continue

            data = json.loads(pullData)     

            self.__state.config(text=data['state'])
            self.__mode.config(text=data['mode'])
            
            time.sleep(0.1)


    def __animate(self, i):
        pullData = open('src\pc\python\\board\WaterSampling.data','r').read()
        dataArray = pullData.split('\n')
        yar=[]
        for eachLine in dataArray[len(dataArray)-101:]:
            if len(eachLine)>1:
                yar.append(float(eachLine))
        self.__plot.clear()
        self.__plot.set_ylim(0, 200)
        self.__plot.set_ylabel("Water Distance:")
        self.__plot.set_xlabel("Time:")
        self.__plot.set_xticks([])
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
        
        f = tk.Frame(self.__win)
        f1 = tk.Frame(f)

        lbl = tk.Label(f1, text="System State: ", font=("Arial", 25))
        lbl.pack(side = tk.LEFT)

        self.__state = tk.Label(f1, text="", font=("Arial", 25))
        self.__state.pack(side = tk.RIGHT)

        f1.pack(side=tk.LEFT)
        f2 = tk.Frame(self.__win)

        lbl = tk.Label(f2, text="System Mode: ", font=("Arial", 18))
        lbl.pack(side = tk.LEFT)

        self.__mode = tk.Label(f2, text="", font=("Arial", 18))
        self.__mode.pack(side = tk.LEFT)

        f2.pack(side = tk.RIGHT)
        f.pack(side=tk.TOP)


    def __init__(self):
        self.__create_window()
        self.__add_plotter()

        t = th.Thread(target=self.__update_state)
        t.start()

        self.__anm = animation.FuncAnimation(self.__fig,
                                             self.__animate,
                                             interval=100)

        self.__win.mainloop()
