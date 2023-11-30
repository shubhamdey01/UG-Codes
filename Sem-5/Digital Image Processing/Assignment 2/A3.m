% 3. Make Negative image (Without the use of built-in function)

f = imread("lenna.tiff");
bits = imfinfo("lenna.tiff").BitsPerSample;
[m,n,o] = size(f);
subplot(1,2,1);
imshow(f);
title("Original");

for i = 1:m
    for j = 1:n
        for k = 1:o
            f(i,j,k) = 2^bits(k) - f(i,j,k);
        end
    end
end

subplot(1,2,2);
imshow(f);
title("Negative");