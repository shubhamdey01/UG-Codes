% 1. Addition of two images.

i1 = imread("stick1.tif");
subplot(1,3,1);
imshow(i1);
title("Image1");

i2 = imread("stick2.tif");
subplot(1,3,2);
imshow(i2);
title("Image2");

i = imadd(i1,i2);
subplot(1,3,3);
imshow(i);
title("Image1 + Image2");