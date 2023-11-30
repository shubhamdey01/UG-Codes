% The sortrows(x) function will sort a vector or matrix X into increasing row order.
% Use this function to sort a list of names into alphabetical order.

ar = char('matlab', 'is', 'a', 'powerful', 'language', 'for', 'technical', 'computing');
disp("Given names :");
disp(ar);
fprintf("\n");
disp("Sorted names :");
disp(sortrows(ar));