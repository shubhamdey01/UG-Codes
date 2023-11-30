srate = 22050;
t = 0:1/srate:5;

s = sin(2*pi*500*t);    
c = cos(2*pi*500*t);

audiowrite('abc.wav',s,srate);
audiowrite('def.wav',c,srate);

plot(t(1:100),s(1:100),'-b',t(1:100),c(1:100),'-g');
