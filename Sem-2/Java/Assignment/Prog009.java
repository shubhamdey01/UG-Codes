// drawRect() & fillRect()

package hw;

import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Color;
import javax.swing.*;

class Shape extends JFrame implements ActionListener
{
	JPanel bg = new JPanel();
	JButton b = new JButton("Enter");
	JLabel l1 = new JLabel("Width :");
	JLabel l2 = new JLabel("Height :");
	JTextField tf1 = new JTextField(5);
	JTextField tf2 = new JTextField(5);
	Draw d;
	public Shape()
	{
		bg.add(l1);
		bg.add(tf1);
		bg.add(l2);
		bg.add(tf2);
		bg.add(b);
		
		b.addActionListener(this);
		
		add(bg,"North");
		setTitle("Rectangle");
		setLocation(100,100);
		pack();
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e)
	{
		int w = Integer.parseInt(tf1.getText());
		int h = Integer.parseInt(tf2.getText());
		d = new Draw(w,h);
		remove(bg);
		add(d);
		setBounds(100,100,2*w+150,h+150);
	}
}
class Draw extends JPanel
{
	private int w,h;
	Draw(int w,int h)
	{
		this.w = w;
		this.h = h;
	}
	public void paint(Graphics g)
	{
		g.setColor(Color.blue);
		g.drawRect(50,50,w,h);
		g.setColor(Color.red);
		g.fillRect(w+100,50,w,h);
	}
}

public class Prog009
{
	public static void main(String[] args)
	{
		new Shape();
	}
}
