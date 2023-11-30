% 3. Resize given image

f = imread("lenna.tiff");
subplot(1,2,1);
imshow(f);
title("Original");
f1 = imresize(f,[128 NaN]);
subplot(1,2,2);
imshow(f1);
title("Resized");