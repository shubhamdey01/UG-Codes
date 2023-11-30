a = primes(500);
x = a(a>10);
k = 1;
twin =[0 0];
for i = x
    if ismember(i+2,x)
        twin(k,:) = [i i+2];
        k = k+1;
    end
end
disp(twin);