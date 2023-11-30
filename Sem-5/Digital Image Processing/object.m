bg = imread("background.jpg");
A = imread("tom.jpg");
B = flip(imread("jerry.jpg"),2);
[m,n,o] = size(bg);
A = imresize(A,[m,n,]);
B = imresize(B,[m,n,]);

mask1 = A>12;
mask2 = B>12;

bg(mask1) = A(mask1);
bg(mask2) = B(mask2);
imshow(bg);