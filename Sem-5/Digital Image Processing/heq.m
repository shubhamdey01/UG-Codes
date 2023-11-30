% Histogram Equilization
% translation scaling shearing rotation

f = imread("cameraman.tif");
subplot(221);
imshow(f);
subplot(222);
imhist(f);
[r,c] = size(f);
N = r*c;

h = uint8(zeros(r,c));
% bins = max(max(f));
freq = zeros(256,1);
pf = zeros(256,1);
pc = zeros(256,1);
cf = zeros(256,1);
op = zeros(256,1);

for i = 1:r
    for j = 1:c
        v = f(i,j);
        freq(v+1) = freq(v+1)+1;
        pf(v+1) = freq(v+1)/N;
    end
end

sum = 0;
bins = 255;

for i = 1:size(pf)
    sum = sum+freq(i);
    cf(i) = sum;
    pc(i) = cf(i)/N;
    op(i) = round(pc(i)*bins);
end

for i = 1:r
    for j = 1:c
        h(i,j) = op(f(i,j)+1);
    end
end

subplot(223);
imshow(h);
subplot(224);
imhist(h);