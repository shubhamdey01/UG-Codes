f = imread("Images/lenna.bmp");
subplot(1,2,1);
imshow(f);
f1 = flip(f,2);
subplot(1,2,2);
imshow(f1);
