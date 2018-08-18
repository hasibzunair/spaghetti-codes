%parameters for transfer function
J=3.228E-6;
b=3.5077E-6;
K1=0.0314;
K2=0.0274;
K3=0.0356;
R=4;
L=2.75E-6;

%time 
t=0:0.001:2;

%controller values kp = 80, kd = 1
Kp = 80;
Ki = 0;
Kd = 2;


s=tf('s');
%pid transfer function
U_s = Kp + (Ki/s) + s*Kd ;

%initial transfer function
H_m=K1*K2/(s*((L*s+R)*(J*s+b)+K2*K3));

%step responce
figure(1)
step(H_m,t,'b');
grid on

% TF after applying controller
H_mP = (( U_s*H_m)/ (1 + U_s*H_m));

%new TF
figure(2)
step(H_mP,t,'g');
xlabel('Voltage in volts')
ylabel('Angular Distance')
grid on