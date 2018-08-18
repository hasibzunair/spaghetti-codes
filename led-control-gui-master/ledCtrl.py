import sys
import time
from Tkinter import *
import RPi.GPIO as gpio

gpio.setmode(gpio.BOARD)
gpio.setup(11,gpio.OUT)
gpio.setup(13,gpio.OUT)
gpio.setup(15,gpio.OUT)
gpio.setup(29,gpio.OUT)

gpio.output(11,False)
gpio.output(13,False)
gpio.output(15,False)
gpio.output(29,False)
gpio.setwarnings(False)

def ledUp():
    if gpio.input(11):
        gpio.output(11,False)
    else:
        gpio.output(11,True)

def ledLeft():
    if gpio.input(13):
        gpio.output(13,False)
    else:
        gpio.output(13,True)
def ledDown():
    if gpio.input(15):
        gpio.output(15,False)
    else:
        gpio.output(15,True)
        
def ledRight():
    if gpio.input(29):
        gpio.output(29,False)
    else:
        gpio.output(29,True)

def exitProgram():
    gpio.cleanup()
    mGui.quit()

mGui = Tk()

mGui.geometry('450x450+0+0')
mGui.title('MY FIRST GUI :D')

mlabel = Label(text = 'LED CONTROLLER ^_^', fg = 'black',bg = 'orange',height = 2, width = 24).pack()
mButton1 = Button(text = 'LED 1', fg = 'black' ,command = ledUp, bg = 'yellow',height = 6, width = 12).place( x = 180, y = 50)
mButton2= Button(text = 'LED 2', fg = 'black',command = ledLeft,bg = 'yellow',height = 6, width = 12)
mButton2.pack(side = BOTTOM)
mButton3= Button(text = 'LED 3', fg = 'black',command = ledDown,bg = 'green',height = 6, width = 12)
mButton3.pack(side = LEFT)
mButton4= Button(text = 'LED 4', fg = 'black',command = ledRight,bg = 'green',height = 6, width = 12)
mButton4.pack(side = RIGHT)
mButton5= Button(text = 'Exit', fg = 'black',command = exitProgram,bg = 'red',height = 2, width = 12).place(x = 180, y =200)
mGui.mainloop()

