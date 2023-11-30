% Solve the linear equations :
%       4x-2y+6z=8;     2x+8y+2z=4;     6x+10y+3z=0

A = [4 -2 6; 2 8 2; 6 10 3];
B = [8; 4; 0];

X = A\B;
fprintf("x = %g\ty = %g\tz = %g\n",X);