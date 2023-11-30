% 1. Flip any image without using any built-in function.

f = imread("cameraman.tif");
subplot(1,2,1);
imshow(f);
title("Original");
[m,n] = size(f);
for i = 1:m
    for j = 1:n/2
        temp = f(i,j);
        f(i,j) = f(i,n-j+1);
        f(i,n-j+1) = temp;
    end
end
subplot(1,2,2);
imshow(f);
title("Flipped");