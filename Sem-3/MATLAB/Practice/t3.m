sr = 11025;
t = 0:1/sr:1;
s = sin(2*pi*500*t);
sound(s,sr);
audiowrite('ex35.wav',s,sr);
plot(s);