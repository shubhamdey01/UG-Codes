% 4. Plot Histogram of a grayscale image.

f = imread("cameraman.tif");
subplot(1,2,1);
imshow(f);
title("Image");
subplot(1,2,2);
imhist(f);
title("Histogram");

hist = findobj(gca, 'Type', 'Stem');
hist.Color = [0.5 0.5 0.5];