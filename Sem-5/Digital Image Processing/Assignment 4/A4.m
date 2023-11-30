% 4. Image Shrinking

clear;
im = imread('cameraman.tif');
f = input('Enter shrinking factor : ');
[m,n] = size(im);

k = 1;
l = 1;
for i = 1:m/f
    for j = 1:n/f
        im2(i,j) = im(k,l);
        l = l+f;
    end
    l = 1;
    k = k+f;
end

imshowpair(im,im2,"montage");
title("Original Image vs Image after Shrinking");