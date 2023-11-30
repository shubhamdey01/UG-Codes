% 2. Flip any image upside down without the use of any built-in function.

f = imread("lenna.tiff");
subplot(1,2,1);
imshow(f);
title("Original");
[m,n,o] = size(f);
for i = 1:m/2
    for j = 1:n
        for k = 1:o
            temp = f(i,j,k);
            f(i,j,k) = f(m-i+1,j,k);
            f(m-i+1,j,k) = temp;
        end
    end
end
subplot(1,2,2);
imshow(f);
title("Flipped");