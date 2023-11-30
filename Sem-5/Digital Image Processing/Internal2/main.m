% Histogram Equalization on Color Images
img = imread('../Images/lenna.tiff');
figure; imshow(img), title('Original Image');

r = equalize_hist(img(:,:,1));
g = equalize_hist(img(:,:,2));
b = equalize_hist(img(:,:,3));
rgb = cat(3, r, g, b);
figure, imshow(rgb), title('rebuild rgb img');

RGB = rgb_average_histogram(img);
figure, imshow(RGB), title('RGB hist img');

HSI = HSI_hist(img);
figure, imshow(HSI), title('HSI hist img');