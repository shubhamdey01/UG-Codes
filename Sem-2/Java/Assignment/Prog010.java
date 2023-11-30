// 3d Cube

package hw;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

class Cube1 extends JFrame
{
	Cube1()
	{
		setTitle("Cube with Shadow");
		setBounds(100,100,300,300);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}
	public void paint(Graphics g)
	{
		int x[] = {50,150,220,120};
		int y[] = {150,150,180,180};
		int n = 4;
		g.setColor(Color.red);
		g.fill3DRect(50,50,100,100,true);
		g.setColor(Color.gray);
		g.fillPolygon(x,y,n);
	}
}
class Cube2 extends JFrame
{
	Cube2()
	{
		setTitle("Cube with Shadow");
		setBounds(100,100,400,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}
	public void paint(Graphics g)
	{
		int xS[] = {50,150,220,120};
		int yS[] = {150,150,180,180};
		int x1[] = {50,150,185,85};
		int y1[] = {100,100,65,65};
		int x2[] = {150,150,185,185};
		int y2[] = {100,200,165,65};
		int n = 4;
		g.setColor(Color.red);
		g.fill3DRect(50,100,100,100,true);
		g.setColor(new Color(255,75,75));
		g.fillPolygon(x1,y1,n);
		g.fillPolygon(x2,y2,n);
		g.setColor(Color.black);
		g.drawRect(50,100,100,100);
		g.drawPolygon(x1,y1,n);
		g.drawPolygon(x2,y2,n);
		g.setColor(Color.gray);
		//g.fillPolygon(xS,yS,n);
	}
}

public class Prog010
{
	public static void main(String[] args)
	{
		new Cube1();
		new Cube2();
	}
}
