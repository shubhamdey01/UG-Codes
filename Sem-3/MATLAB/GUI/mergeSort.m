function s = mergeSort(a)

n = length(a);
if n <= 1
    s = a;
else
    s = merge( mergeSort( a(1 : floor(n/2)) ), mergeSort( a(floor(n/2)+1 : n) ) );
end

function m = merge(a,b)

n = length(a) + length(b);
m = zeros(1,n);
a = [a, inf]; b = [b, inf];
ia = 1; ib = 1;
for i = 1:n
    if a(ia) < b(ib)
        m(i) = a(ia);
        ia = ia + 1;
    else
        m(i) = b(ib);
        ib = ib + 1;
    end
end