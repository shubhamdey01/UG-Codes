% 4. Show RGB color components separately of an image (in color)

f = imread('lenna.tiff');
subplot(2,4,1);
imshow(f);
title("Original");

[r,g,b] = imsplit(f);
[m,n,o] = size(f);

black = zeros(m, n, 'uint8');
R = cat(3,r,black,black);
G = cat(3,black,g,black);
B = cat(3,black,black,b);

subplot(2,4,5);
imshow(R);
title("Red (Color)");
subplot(2,4,6);
imshow(G);
title("Green (Color)");
subplot(2,4,7);
imshow(B);
title("Blue (Color)");