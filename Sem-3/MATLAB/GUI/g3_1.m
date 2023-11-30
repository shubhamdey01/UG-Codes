srate = 22050;      % sampling rate
t = 0:1/srate:5;      % time

% wave generation at 500Hz
s = sin(2*pi*500*t);    
c = cos(2*pi*500*t);

% saving audio to file
audiowrite('abc.wav',s,srate);
audiowrite('def.wav',c,srate);

% plotting the first 100 samples
plot(t(1:100),s(1:100),'-b',t(1:100),c(1:100),'-g');