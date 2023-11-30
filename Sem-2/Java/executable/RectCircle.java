package executable;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class RectCircle extends JFrame implements ActionListener {
	JButton b1 = new JButton("Rectangle");
	JButton b2 = new JButton("Circle");
	JLabel l = new JLabel();
	JPanel bg = new JPanel();
	JPanel top = new JPanel();
	JPanel bot = new JPanel();
	Draw d = new Draw();
	int shape = 0;
	
	public RectCircle() {
		top.add(b1);
		top.add(b2);
		bot.add(l);
		bg.setLayout(new BorderLayout());
		bg.add(d,"Center");
		bg.add(top,"North");
		bg.add(bot,"South");
		bg.setBackground(Color.white);
		
		b1.setBackground(Color.lightGray);
		b2.setBackground(Color.lightGray);
		b1.addActionListener(this);
		b2.addActionListener(this);
		l.setFont(new Font(Font.SANS_SERIF,Font.BOLD,15));
		
		getContentPane().add(bg);
		setTitle("Rectangle & Circle");
		setBounds(200,200,600,300);
		setVisible(true);
	}
	
	private class Draw extends JComponent {
		public void paint(Graphics g) {
			if(shape == 1) {
				g.setColor(Color.blue);
				g.drawRect(50,50,200,100);
				g.setColor(Color.red);
				g.fillRect(300,50,200,100);
			}
			else if(shape == 2) {
				g.setColor(Color.red);
				g.drawOval(100,50,100,100);
				g.setColor(Color.blue);
				g.fillOval(350,50,100,100);
			}
		}
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b1) {
			shape = 1;
			l.setText("Rectangle");
			b1.setBackground(Color.gray);
			b2.setBackground(Color.lightGray);
		}
		else if(e.getSource() == b2) {
			shape = 2;
			l.setText("Circle");
			b1.setBackground(Color.lightGray);
			b2.setBackground(Color.gray);
		}
		d.repaint();
	}
}