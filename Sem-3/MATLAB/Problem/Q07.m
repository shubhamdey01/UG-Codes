N = input("Enter N : ");
ar = 1:N;
i = 1:sqrt(N);
disp("Numbers which have indices that are square numbers :");
disp(ar(i.^2));