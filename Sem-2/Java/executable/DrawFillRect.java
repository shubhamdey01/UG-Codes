package executable;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class DrawFillRect extends JFrame implements ActionListener {
	private class Draw extends JPanel {
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
	
	JPanel bg = new JPanel();
	JButton b = new JButton("Enter");
	JLabel l1 = new JLabel("Width :");
	JLabel l2 = new JLabel("Height :");
	JTextField tf1 = new JTextField(5);
	JTextField tf2 = new JTextField(5);
	Draw d;
	
	public DrawFillRect() {
		bg.add(l1);
		bg.add(tf1);
		bg.add(l2);
		bg.add(tf2);
		bg.add(b);
		
		b.addActionListener(this);
		
		add(bg);
		setTitle("Rectangle");
		setLocation(100,100);
		setBackground(Color.white);
		pack();
		setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		int w = Integer.parseInt(tf1.getText());
		int h = Integer.parseInt(tf2.getText());
		d = new Draw(w,h);
		remove(bg);
		add(d);
		setBounds(100,100,2*w+150,h+150);
	}
}