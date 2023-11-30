% Take input from user of four variables: a,b,c and d. Calculate the following expressions:
%	a. a/b + (d-c)/(d+c)-(d-b)^2
%	b. e^((d-c)/(a-2*b)) + ln(|c-d+b/a|)

a = input("a = ");
b = input("b = ");
c = input("c = ");
d = input("d = ");

x = a/b + (d-c)/(d+c)-(d-b)^2;

y = exp((d-c)/(a-2*b)) + log(abs(c-d+b/a));

fprintf("x = %g\ty = %g\n",x,y);