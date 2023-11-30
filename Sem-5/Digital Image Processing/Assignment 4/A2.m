% 2. Image Scaling

im = imread("cameraman.tif");
f = double(input("Enter scaling factor : "));

im2 = imresize(im,f);
imshowpair(im,im2,"montage");
title("Original Image vs Image after Scaling");
