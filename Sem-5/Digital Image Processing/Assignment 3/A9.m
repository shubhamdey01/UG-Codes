% 9. Histogram Equilization without built-in function.

f = "pout.tif";
im = imread(f);
subplot(221);
imshow(im);
title("Original Image");
subplot(222);
imhist(im);
title("Original Histogram");

[m,n] = size(im);
N = m * n;
max = imfinfo(f).MaxSampleValue;

freq = zeros(1,max+1);
pfreq = zeros(1,max+1);
for i = 1:m
    for j = 1:n
        freq(im(i,j)+1) = freq(im(i,j)+1)+1;
        pfreq(im(i,j)+1) = freq(im(i,j)+1)/N;
    end
end

cum = zeros(1,max+1);
s = zeros(1,max+1);
sum = 0;
for i = 1:max+1
    sum = sum + pfreq(i);
    cum(i) = sum;
    s(i) = round(cum(i)*max);
end
h = zeros(m,n,'uint8');
for i = 1:m
    for j = 1:n
        h(i,j) = s(im(i,j)+1);
    end
end

subplot(223);
imshow(h);
title("Equilized Image");
subplot(224);
imhist(h);
title("Equilized Histogram");