% 10. Adding objects to an external scenery using the above operator(s).

bg = imread("background.jpg");
subplot(221);
imshow(bg);
title('Background');
A = imread("tom-new.jpg");
subplot(222);
imshow(A);
title('Object-1');
B = imread("jerry-new.jpg");
subplot(223);
imshow(B);
title('Object-2');

obj = A + B;
bg = imresize(bg,[size(obj,1),size(obj,2)]);

white = ones(size(obj),'uint8');
mask = white./obj;

black = uint8(and(mask,bg));
img = (bg.*black)+obj;

subplot(224);
imshow(img);
title('Output');