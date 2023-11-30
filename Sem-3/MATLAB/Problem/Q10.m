x = 1:10;
y = 2*x + rand(1,10) - 0.5;
p = polyfit(x,y,1);
y2 = polyval(p,x);
plot(x,y,'LineWidth',1);
hold on;
plot(x,y2,'--','LineWidth',1);
hold off;
legend('raw data', 'best fit','Location','northwest');