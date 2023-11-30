package internal;

import java.awt.Graphics;
import java.awt.Color;
import javax.swing.*;

class Shape extends JFrame
{
	public Shape()
	{
		setTitle("Rectangle & Circle");
		setBounds(200,200,800,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		g.setColor(Color.blue);
		g.drawRect(100,100,200,100);
		g.fillOval(550,250,100,100);
		g.setColor(Color.red);
		g.drawOval(150,250,100,100);
		g.fillRect(500,100,200,100);
	}
}

public class Q_2
{
	public static void main(String[] args)
	{
		new Shape();
	}
}
