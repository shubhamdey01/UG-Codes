% The identity matrix is a square matrix that has ones on the diagonal and zeros elsewhere.
% You can generate one with the eye() function in MATLAB. Use MATLAB to find a matrix B,
% such that when multiplied by matrix A=[ 1 2; -1 0 ] the identity matrix I=[ 1 0; 0 1 ] is generated. That is A*B=I.

A = [2 1; -1 0];
I = eye(2);
B = I/A;
disp("B =");
disp(B);
disp("A*B =");
disp(A*B);