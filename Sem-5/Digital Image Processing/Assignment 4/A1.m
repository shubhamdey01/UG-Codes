% 1. Image Translation

im = imread("cameraman.tif");
tx = double(input("Enter Tx : "));
ty = double(input("Enter Ty : "));

im2 = imtranslate(im,[tx,ty]);
imshowpair(im,im2,"montage");
title("Original Image vs Image after Translation");