syms x y z          % declaring symbolic variables

% given equations
e1 = -4*x+3*y+z == -18.2;
e2 = 5*x+6*y-2*z == -48.8;
e3 = 2*x-5*y+4.5*z == 92.5;

% conversion from equations to matrix form
[A,B] = equationsToMatrix([e1,e2,e3],[x,y,z]);

% solution
X = linsolve(A,B);

disp("Given equations are :");
disp(e1);
disp(e2);
disp(e3);
disp(' ');
disp('Required solution :')
fprintf('x = %g,    y = %g ,    z = %g\n',X);