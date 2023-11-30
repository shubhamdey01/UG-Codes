% 2D plot of quadratic function :
%      (x^2-3*x+7)/(sqrt(2*x+5)); 

x = -1:5;
y = (x.^2-3*x+7)./sqrt(2*x+5);

plot(x,y,'--gp',LineWidth=2,MarkerSize=8);