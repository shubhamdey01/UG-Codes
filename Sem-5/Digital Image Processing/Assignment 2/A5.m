% 5. Plot Histogram of a color image.

f = imread("lenna.tiff");
subplot(2,3,1);
imshow(f);
title("Image");

[r,g,b] = imsplit(f);
subplot(2,3,2);
imhist(r);
hist = findobj(gca, 'Type', 'Stem');
hist.Color = [1 0 0];
title("Red");
subplot(2,3,3);
imhist(g);
hist = findobj(gca, 'Type', 'Stem');
hist.Color = [0 1 0];
title("Green");
subplot(2,3,4);
imhist(b);
title("Blue");
hist = findobj(gca, 'Type', 'Stem');
hist.Color = [0 0 1];

[yR,x] = imhist(r);
[yG,x] = imhist(g);
[yB,x] = imhist(b);
subplot(2,3,5);
bar(yR,'Red'); hold on;
bar(yG,'Green'); hold on;
bar(yB,'Blue'); hold off;
title('RGB - Histogram');
subplot(2,3,6);
plot(x,yR,'Red',x,yG,'Green',x,yB,'Blue');
title('RGB - Plot');