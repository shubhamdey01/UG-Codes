fid1 = fopen("input.txt","r");
txt = fscanf(fid1,"%s",inf);
fclose(fid1);
fid2 = fopen("output","w");
lines = strsplit(txt,';');
for i = lines
    x = strsplit(char(i),',');
    name = x(1);
    m1 =str2double(x(2));
    m2 =str2double(x(3));
    m3 =str2double(x(4));
    per = (m1+m2+m3)/150*100;
    fprintf(fid2,"Name : %s\t\tPercentage : %g\n",char(name),per);
end
fclose(fid2);
