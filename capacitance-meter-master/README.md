# capacitance-meter
A simple capacitance meter is to be made using the 555 timer in monostable mode. The output pulse of the timer is fed to a microcontroller for further calculations.

The mono-stable configuration uses a trigger method to obtain the output pulse. This output pulse is fed to a microcontroller the calculate time period of the output pulse. 
We know, the time period is dependent on the value of C.
Different C means different time period.
The mathematical equation for the mono-stable configuration is ,
                    
                                     T = 1.1 RC
After the processing of the MCU, we get the time. We know the value of the resistor and now we can find C!

This value is displayed using an LCD Display. Below is the schematic.

# Video demo :
https://www.youtube.com/watch?v=0GNrHAVGRHs

# Schematic : 

![alt text](https://github.com/hasibzunair/capacitance-meter/blob/master/schematic.PNG)

# Results : 

![alt text](https://github.com/hasibzunair/capacitance-meter/blob/master/output.PNG)

