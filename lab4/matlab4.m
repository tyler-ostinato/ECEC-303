close all;clear all;clc
% Set up communications
arduino=serialport("COM8",9600,"Timeout",15);
pause(1)
x = 0:100;
y = zeros(1,101);
for K=0:100
flush(arduino)
write(arduino,2,'string')
pause(0.5)
a=read(arduino,4,'string');
flush(arduino)
y(K+1)=str2double(a);
disp([K,y(K+1)])
end
delete(arduino);
clear arduino;

figure
plot(x/100,y*5/1023,'ko','MarkerFaceColor','blue')
grid on
title('Photocell Voltage vs Duty Cycle (Blue LED)')
xlabel('Duty Cycle (%)')
ylabel('Output Voltage (V)')

figure
voltage = y*5/1023;
resistance = ((10000*5)./voltage) - 10000;
plot(x/100,resistance,'ko','MarkerFaceColor','blue')
grid on
title('Photocell Resistance vs Duty Cycle (Blue LED)')
xlabel('Duty Cycle (%)')
ylabel('Resistance (Ohms)')

figure
voltage = y*5/1023;
resistance = ((10000*5)./voltage) - 10000;
current = 5./(10000 + resistance);
plot(x/100,current,'ko','MarkerFaceColor','blue')
grid on
title('Photocell Current vs Duty Cycle (Blue LED)')
xlabel('Duty Cycle (%)')
ylabel('Current (mA)')