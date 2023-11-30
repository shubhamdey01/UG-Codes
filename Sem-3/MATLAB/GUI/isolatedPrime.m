function mat = isolatedPrime(lb,ub)
% isolatedPrimes(lb,ub)-
% finds isolated prime numbers between the given range
% lb - lower bound
% ub - upper bound

k=1;
res(k) = 0;
for i = lb:ub
    flag = 1;
    j = 2;
    while j*j <= i
        if rem(i,j) == 0
            flag = 0;
            break;
        end
        j = j+1;
    end
    if flag == 1
        res(k) = i;
        k = k+1;
    end
end

k=1;
mat(k) = 0;
for i = res
    if ~(ismember(i-2,res) | ismember(i+2,res))
        mat(k) = i;
        k = k+1;
    end
end
