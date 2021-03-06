import RPi.GPIO as gpio
import time
import sys
import Tkinter as tk

def init():
 gpio.setmode(gpio.BOARD)
 gpio.setup(7, gpio.OUTPUT)
 gpio.setup(11,gpio.OUTPUT)
 gpio.setup(13, gpio.OUTPUT)
 gpio.setup(15, gpio.OUTPUT)


def forward(tf):

init()

gpio.output(7 , False)
gpio.output(11, True)
gpio.output(13, True)
gpio.output(15, False)
time.sleep(tf)
gpio.cleanup()

def reverse(tf):

init()
gpio.output(7, False)
gpio.output( 11, True)
gpio.output( 13, True)
gpio.output(15, False)
time.sleep(tf)
gpio.cleanup()

def pivot_left:
init()
gpio.output(7, True)
gpio.ouput(11,False)
gpio.output(13, True)
gpio.output(15, False)
time.sleep(tf)
gpio.cleanup()

def pivot_right:

init()
gpio.output(7,False)
gpio.output(11, True)
gpio.output(13, False)
gpio.output(15, True)
time.sleep(tf)
gpio.cleanup()

def stop:
init()
gpio.output(7, False)
gpio.output(11, False)
gpio.output(13, False)
gpio.output(15, False)
time.sleep(tf)
gpio.cleanup()

def key_input(event):
init()

print 'Key:' ,event.char
key_press = event.char
sleep_time = 0.030

if key_press.lower() == 'w':
forward(sleep_time)
elif key_press.lower == 's':
reverse(sleep_time)
elif key_press.lower == 'a':
pivot_left(sleep_time)
elif key_press.lower == 'd'
pivot_right(sleep_time)
elif key_press.lower == 'h'
stop(sleep_time)

command = tk.Tk()
command.bind('<KeyPress>' , key_input)
command.mainloop()
