% Data from : https://www.timeanddate.com/weather/india/bokaro-steel-city

x = 2009:2021;

ym = [18.84 19.46 19.16 19.27 19.62 19.84 19.90 20.24 21.31 19.16 20.35 21.64 20.72];
yM = [19.44 20.94 20.86 21.53 21.78 21.03 20.81 21.18 22.12 20.45 21.06 22.32 22.03];

y = [ym; yM];

subplot(2,1,1);
bar(x,y);
legend("Min. Temp.","Max. Temp.","Location","northwest");
xlabel("Years",'FontWeight','bold',"FontSize",12);
ylabel("Temperature (in \circC)",'FontWeight','bold',"FontSize",12);
title("Average temperature of BOKARO of the month OCTOBER (2009 - 21)","FontSize",14);

subplot(2,1,2);
plot(x,yM,'-ro');
hold on
plot(x,ym,'--b*');
hold off
legend("Max. Temp.","Min. Temp.","Location","northwest");
xlabel("Years",'FontWeight','bold',"FontSize",12);
ylabel("Temperature (in \circC)",'FontWeight','bold',"FontSize",12);
title("Average temperature of BOKARO of the month OCTOBER (2009 - 21)","FontSize",14);