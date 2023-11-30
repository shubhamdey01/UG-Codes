% Set up a vector called N with five elements having the values: 1, 2, 3, 4, 5.
% Using N, create assignment statements for a vector X which will result in X having these values:
%	 a. 2, 4, 6, 8, 10
%	 b. 1/2, 1, 3/2, 2, 5/2
%	 c. 1, 1/2, 1/3, 1/4, 1/5
%	 d. 1, 1/4, 1/9, 1/16, 1/25

N = 1:5;
fprintf('N =\t');
disp(N);

X = N.*2;
fprintf('X =\t');
disp(X);

X = N./2;
fprintf('X =\t');
disp(X);

X = N.^-1;
fprintf('X =\t');
disp(X);

X = N.^-2;
fprintf('X =\t');
disp(X);
