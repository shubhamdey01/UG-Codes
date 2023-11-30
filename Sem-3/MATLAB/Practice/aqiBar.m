% Data from : https://aqicn.org/data-platform/register



x = 2014:2021;
y = [269.27 274.57 296.3 302.9 247.04 253.57 267.17 285.87];

subplot(2,1,1);
bar(x,y);
xlabel("Years",'FontWeight','bold',"FontSize",12);
ylabel("AQI (pm_{25})",'FontWeight','bold',"FontSize",12);
title("Average AQI(pm_{25}) of Delhi of the month NOVEMBER (2014 - 21)","FontSize",14);

subplot(2,1,2);
plot(x,y,'-rp');
xlabel("Years",'FontWeight','bold',"FontSize",12);
ylabel("AQI (pm_{25})",'FontWeight','bold',"FontSize",12);
title("Average AQI(pm_{25}) of Delhi of the month NOVEMBER (2014 - 21)","FontSize",14);