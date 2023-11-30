% Write a program to assign the following expressions to a variable A and then to print out the value of A :
%	a. (3+4)/(5+6)
%	b. 2*pi^2
%	c. 2^1/2
%	d. (0.0000123 + 5.67*10^-3)*0.4567*10^-4

A = (3+4)/(5+6);
fprintf('A = (3+4)/(5+6) = %g\n',A);

A = 2*pi^2;
fprintf('A = 2*pi^2 = %g\n',A);

A = sqrt(2);
fprintf('A = sqrt(2) = %g\n',A);

A = (0.0000123 + 5.67*10^-3)*0.4567*10^-4;
fprintf('A = (0.0000123 + 5.67*10^-3)*0.4567*10^-4 = %g\n',A);