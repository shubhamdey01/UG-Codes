s1 = input("Enter string 1 :  ","s");
s2 = input("Enter string 2 :  ","s");
s3 = [s1 ' ' s2];
disp(s3);
disp(char('*'*ones(size(s3))));
disp(s3(length(s3):-1:1));