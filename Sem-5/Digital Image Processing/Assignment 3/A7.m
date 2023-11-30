% 7. Calculate intersection of two images and
% display the intersection image.

i1 = imread("lungs1.tif");
subplot(1,3,1);
imshow(i1);
title("Image1");

i2 = imread("lungs2.tif");
subplot(1,3,2);
imshow(i2);
title("Image2");

[r,c] = size(i1);
i = 255.*ones(r,c,'uint8');
for j = 1:r
    for k = 1:c
        if i1(j,k) == i2(j,k)
            i(j,k) = i1(j,k);
        end
    end
end

subplot(1,3,3);
imshow(i);
title("Image1 INTERSECT Image2");