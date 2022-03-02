% figure
% x = [0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185];
% y=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2094,1950,1809,1700,1734,1800,1972,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
% plot(x,y,'ko','MarkerFaceColor','blue')
% grid on
% title('2 Way Angle of Acceptance (Horizontal)')
% xlabel('Angle')
% ylabel('Ultra-sonic Reading (microseconds)')
% 
% figure
% x = [0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185];
% y=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2000,1888,1844,1800,1803,1760,1890,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
% plot(x,y,'ko','MarkerFaceColor','blue')
% grid on
% title('2 Way Angle of Acceptance (Vertical)')
% xlabel('Angle')
% ylabel('Ultra-sonic Reading (microseconds)')

% s = '2 3';
% A = sscanf(s,'%f')
% A(1)
% sprintf('%0.5g',(1+sqrt(5))/2)
arduino=serialport("COM8",9600,"Timeout",15);
pause(1)
for i = 1:10
    flush(arduino)
    write(arduino,2,'string');
    pause(0.5)
    a=read(arduino,4,'string');
    class(a);
    flush(arduino)
    stringI =  fread(a,get(a,'BytesAvailable'), 'uint8');
end
% s = '5.5,6.7,8.9';
% headers = strsplit(s, ',')
% headers{1}
% % data = textscan(headers, '%f', 'Delimiter', ',')

% str = 'Hello,world';
% for k = 1:length(str)
%   array = strsplit(str,',')
% end
% 
% array(1)
% array(2)







