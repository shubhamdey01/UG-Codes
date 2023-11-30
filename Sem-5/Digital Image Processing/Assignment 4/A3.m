% 3. Image Rotation

im = imread("cameraman.tif");
d = double(input("Enter angle : "));

im2 = imrotate(im,d);
subplot(121);
imshow(im);
title("Original Image");
subplot(122);
imshow(im2);
title("Rotated Image");
