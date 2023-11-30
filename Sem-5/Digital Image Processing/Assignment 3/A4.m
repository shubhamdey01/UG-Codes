% 4. Calculate mean value of an image and also more than one image.

im1 = imread("stick1.tif");
im2 = imread("stick2.tif");
im2 = imresize(im2,size(im1));
im3 = imread("cameraman.tif");
im3 = imresize(im3,size(im1));
im = imadd(imadd(im1,im2),im3)./3;

subplot(221); imshow(im1);
m = mean2(im1); title(["Mean = ",num2str(m)]);
subplot(222); imshow(im2);
m = mean2(im2); title(["Mean = ",num2str(m)]);
subplot(223); imshow(im3);
m = mean2(im3); title(["Mean = ",num2str(m)]);
subplot(224); imshow(im);
m = mean2(im); title(["Mean = ",num2str(m)]);
