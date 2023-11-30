% 5. Image Zooming

clear;
im = imread('cameraman.tif');
f = input('Enter zooming factor : ');
[m,n] = size(im);

k = 1;
l = 1;
for i = 1:f:m*f
    for j = 1:f:n*f
        im2(i,j) = im(k,l);
        l = l+1;
    end
    l = 1;
    k = k+1;
end
for i = 1:f:m*f
    for j = 2:f:n*f
        im2(i,j) = im2(i,j-1);
    end
end
for j = 1:f:n*f
    for i = 2:f:m*f
        im2(i,j) = im2(i-1,j);
    end
end
for i = 2:f:m*f
    for j = 2:f:n*f
        im2(i,j) = im2(i,j-1);
    end
end


% z = 2;
% T = [z 0 0; 0 z 0; 0 0 1];
% im2 = imwarp(im,affine2d(T),'OutputView',imref2d([m*z,n*z]));

imshowpair(im,im2,"montage");
title("Original Image vs Image after Zooming");