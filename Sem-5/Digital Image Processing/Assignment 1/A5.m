% 5. Convert given color image into gray-scale image

f = imread("lenna.tiff");
subplot(1,2,1);
imshow(f);
title("Original (Color)");
f1 = rgb2gray(f);
subplot(1,2,2);
imshow(f1);
title("Gray-scale");
imwrite(f1,"gray.tif");