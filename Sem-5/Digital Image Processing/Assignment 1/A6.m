% 6. Convert given color/gray-scale image into black & white image

f = imread("gray.tif");
subplot(1,2,1);
imshow(f);
title("Original (Grayscale)");
f1 = imbinarize(f);
subplot(1,2,2);
imshow(f1);
title("Black & White");