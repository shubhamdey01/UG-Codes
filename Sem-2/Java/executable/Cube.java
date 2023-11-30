package executable;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;

public class Cube extends JFrame {
	
	Cube() {
		setTitle("3D Cube");
		setBounds(100,100,360,320);
		setVisible(true);
	}

	public void paint(Graphics g) {
		int xS[] = {100,220,260,300,300,200};
		int yS[] = {220,220,180,220,300,300};
		int x1[] = {100,220,260,140};
		int y1[] = {100,100,60,60};
		int x2[] = {220,260,260,220};
		int y2[] = {100,60,180,220};
		int n = 4;
		g.setColor(Color.red);
		g.fill3DRect(100,100,120,120,true);
		g.setColor(new Color(255,90,80));
		g.fillPolygon(x1,y1,n);
		g.fillPolygon(x2,y2,n);
		g.setColor(Color.black);
		g.drawRect(100,100,120,120);
		g.drawPolygon(x1,y1,n);
		g.drawPolygon(x2,y2,n);
		g.setColor(Color.gray);
		g.fillPolygon(xS,yS,6);
	}
}