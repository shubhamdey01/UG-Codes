% 7. Write given 2-D data in image file

f = imread("flowers.ppm");
f1 = rgb2gray(f);
imwrite(f1,"A7.tif");
imshow(f1);