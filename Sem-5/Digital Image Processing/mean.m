% 5. Different Brightness by changing mean value

i = imread("cameraman.tif");
subplot(131);
imshow(i);
m = mean2(i);
title(["Mean value of the image = ",num2str(m)]);

i1 = imadd(i,m);
i2 = imsubtract(i,m);
subplot(132);
imshow(i1);
m = mean2(i1);
title(["Mean value of the image = ",num2str(m)]);
subplot(133);
imshow(i2);
m = mean2(i2);
title(["Mean value of the image = ",num2str(m)]);