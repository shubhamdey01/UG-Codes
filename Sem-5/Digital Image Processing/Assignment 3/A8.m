% 8. Water Marking using EX-OR operation.

i1 = imread("cameraman.tif");
subplot(1,3,1);
imshow(i1);
title("Image1");

i2 = imread("message.tif");
subplot(1,3,2);
imshow(i2);
title("Watermark");

i = bitxor(i1,i2);
subplot(1,3,3);
imshow(i);
title("Watermarked Image");