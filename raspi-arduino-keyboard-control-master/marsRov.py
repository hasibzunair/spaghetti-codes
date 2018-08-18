import RPi.GPIO as gpio
import time
import sys
import Tkinter as tk

def init():  #all trig pins sent to arduino
    
 gpio.setmode(gpio.BOARD)
 gpio.setup(11, gpio.OUT)
 gpio.setup(13, gpio.OUT)
 gpio.setup(29, gpio.OUT)
 gpio.setup(31, gpio.OUT)
 gpio.setup(33, gpio.OUT)
 gpio.setup(35, gpio.OUT)
 gpio.setup(37, gpio.OUT)
 gpio.setup(40, gpio.OUT)
 gpio.setup(38, gpio.OUT)
 gpio.setup(36, gpio.OUT)
 gpio.setup(32, gpio.OUT)
 gpio.setup(18, gpio.OUT)
 gpio.setup(16, gpio.OUT)
 gpio.setup(12, gpio.OUT)
 

def in1(tf):
 gpio.output(11, True)
 time.sleep(tf)
 gpio.cleanup()

def in2(tf):
 gpio.output(13, True)
 time.sleep(tf)
 gpio.cleanup()

def in3(tf):
 gpio.output(29, True)
 time.sleep(tf)
 gpio.cleanup()

def in4(tf):
 gpio.output(31, True)
 time.sleep(tf)
 gpio.cleanup()
 
def in5(tf):
 gpio.output(33, True)
 time.sleep(tf)
 gpio.cleanup()

def in6(tf):
 gpio.output(35, True)
 time.sleep(tf)
 gpio.cleanup()

def in7(tf):
 gpio.output(37, True)
 time.sleep(tf)
 gpio.cleanup()

def in8(tf):
 gpio.output(40, True)
 time.sleep(tf)
 gpio.cleanup()

def in9(tf):
 gpio.output(38, True)
 time.sleep(tf)
 gpio.cleanup()

def in10(tf):
 gpio.output(36, True)
 time.sleep(tf)
 gpio.cleanup()

def in11(tf):
 gpio.output(32, True)
 time.sleep(tf)
 gpio.cleanup()

def in12(tf):
 gpio.output(18, True)
 time.sleep(tf)
 gpio.cleanup()

def in13(tf):
 gpio.output(16, True)
 time.sleep(tf)
 gpio.cleanup()

def in14(tf):
 gpio.output(12, True)
 time.sleep(tf)
 gpio.cleanup()


def noor(tf):
    
    gpio.output(11, False)
    gpio.output(13, False)
    gpio.output(29, False)
    gpio.output(31, False)
    gpio.output(33, False)
    gpio.output(35, False)
    gpio.output(37, False)
    gpio.output(40, False)
    gpio.output(38, False)
    gpio.output(36, False)
    gpio.output(32, False)
    gpio.output(18, False)
    gpio.output(16, False)
    gpio.output(12, False)
    #time.sleep(tf)
   #gpio.cleanup()
    
##end of functions
 

def key_input(event):
 init() 
 print 'Key: ',event.char
 key_press = event.char
 sleep_time = 0.020 #0.020

##give conditions when diff keys are pressed
 
 if key_press.lower() == 'w':
  noor(sleep_time)
  in1(sleep_time)
 
 elif key_press.lower() == 'a':
  noor(sleep_time)
  in2(sleep_time)

 elif key_press.lower() == 's':
  noor(sleep_time)
  in3(sleep_time)

 elif key_press.lower() == 'd':
  noor(sleep_time)
  in4(sleep_time)

 elif key_press.lower() == 't':
  noor(sleep_time)
  in5(sleep_time)

 elif key_press.lower() == 'g':
  noor(sleep_time)
  in6(sleep_time)

 elif key_press.lower() == 'y':
  noor(sleep_time)
  in7(sleep_time)

 elif key_press.lower() == 'h':
  noor(sleep_time)
  in8(sleep_time)

 elif key_press.lower() == 'u':
  noor(sleep_time)
  in9(sleep_time)

 elif key_press.lower() == 'j':
  noor(sleep_time)
  in10(sleep_time)

 elif key_press.lower() == 'n':
  noor(sleep_time)
  in11(sleep_time)

 elif key_press.lower() == 'm':
  noor(sleep_time)
  in12(sleep_time)

 elif key_press.lower() == 'v':
  noor(sleep_time)
  in13(sleep_time)

 elif key_press.lower() == 'b':
  noor(sleep_time)
  in14(sleep_time)

command = tk.Tk()
command.bind('<KeyPress>' , key_input)
command.mainloop()
