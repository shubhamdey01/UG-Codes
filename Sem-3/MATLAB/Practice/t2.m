aqi = readtable("aqi2.csv");

x = string.empty;
y = int16.empty;

for i = 1:height(aqi)
    x(i) = aqi(i,1);
    y(i) = aqi(i,2);
end

disp(y);