% Plotting of Logarithmic graphs ( LogvsL ) :     y = 2^(-0.2x + 10)    for  0.1<=x<=60

x = [0.1:0.1:60];
 y = 2.^(-0.2*x + 10);
 semilogx(x,y,'--r','LineWidth',1);
 xlabel('Log','EdgeColor','k','BackgroundColor','c');
 ylabel('Linear','EdgeColor','k','BackgroundColor','c');
 title("y = 2^{-0.2x + 10} ;    0.1 <= x <= 60",'FontSize',15,'FontAngle','italic','Color','b','FontWeight','light');