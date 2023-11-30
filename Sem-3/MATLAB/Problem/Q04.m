price = [0.6 1.2 0.5 1.3];
num = [3 2 1 5];

cost = price * num';        % num' = transpose of num

fprintf('Total bill = %g pound\n',cost);