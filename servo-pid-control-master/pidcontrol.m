clc; clear; clc

m = 200; %Kg
rk = 100; 
wf = 0.4; %cofficient of friction, no units

s = tf('s'); %frequency domain variables
T_F = 1/((m*s^2)+s*wf+rk); %transfer function for the system

subplot(2,1,1)
step(T_F); %graph plot with unit step input
%axis([0 100 0 2]);
grid on;
title('Unit Step');

subplot(2,1,2)
pzmap(T_F); %pole-zero map
title('Poles and Zeros');
