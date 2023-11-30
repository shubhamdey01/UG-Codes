% 6. Obtain two images with low contrast (light and dark) and
% high contrast and plot respective histograms. Observe the difference.

f1 = imread("light1.tif");
subplot(2,3,1);
imshow(f1);
title("Low Contrast (light)");
subplot(2,3,4);
imhist(f1);
title("Histogram: Low Contrast (light)");

f2 = imread("dark1.tif");
subplot(2,3,2);
imshow(f2);
title("Low Contrast (dark)");
subplot(2,3,5);
imhist(f2);
title("Histogram: Low Contrast (dark)");

f3 = imread("high1.tif");
subplot(2,3,3);
imshow(f3);
title("High Contrast");
subplot(2,3,6);
imhist(f3);
title("Histogram: High Contrast");