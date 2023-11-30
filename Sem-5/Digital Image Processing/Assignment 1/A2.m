% 2. Read a gray-scale image of 256x256, add 20 with every intensity value.
% Write it to another image file and show it.

f1 = imread("cameraman.tif");
f2 = mod((f1*2),255);
imwrite(f2,"A2.tif");
subplot(1,2,1);
imshow(f1);
title("Original");
subplot(1,2,2);
imshow(f2);
title("Modified");