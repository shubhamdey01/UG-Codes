n = 1:1000;
r = sqrt(n);
t = 137.51 * pi *n /180;
x = r.*cos(t);
y = r.*sin(t);
plot(x,y,'o');