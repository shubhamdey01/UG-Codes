% 3. Perform division of images.

i1 = imread("rice.tif");
subplot(1,3,1);
imshow(i1);
title("Image1");

i2 = imread("bg.tif");
subplot(1,3,2);
imshow(i2);
title("Image2");

i = imdivide(i1,i2);
subplot(1,3,3);
imshow(i,[]);
title("Image1 / Image2");