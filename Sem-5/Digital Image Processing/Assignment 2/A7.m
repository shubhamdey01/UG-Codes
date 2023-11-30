% 1. Contrast Stretching: Stretch the contrast of an image 
% and plot the both the images along with their histograms.

r = imread("contrast.tif");
subplot(2,2,1);
imshow(r);
title("Original");
subplot(2,2,2);
imhist(r);
title("Histogram : Original");

M = input("M = ");
E = input("E = ");
s = 1./(1+(M./double(r)+eps).^E);

subplot(2,2,3);
imshow(s);
title("After Contrast Streching");
subplot(2,2,4);
imhist(s);
title("Histogram : After Contrast Streching");