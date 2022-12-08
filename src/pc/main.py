# Imports
from board.ArduinoBoard import ArduinoBoard

print("Program Start")
uno = ArduinoBoard()

while True:
    print(uno.read())
