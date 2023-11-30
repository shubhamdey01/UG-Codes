package executable;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class DrawingPad extends JFrame implements ActionListener{
	JPanel p = new JPanel();
	JButton b = new JButton("Color");
	JButton c = new JButton();
	JRadioButton r1 = new JRadioButton("Circular Marker");
	JRadioButton r2 = new JRadioButton("Star Marker");
	JRadioButton r3 = new JRadioButton("Drag to draw");
	ButtonGroup gr = new ButtonGroup();
	Color color;
	Draw d = new Draw();

	public DrawingPad() {
		setLayout(new BorderLayout());
		setBounds(50, 50, 600, 500);
		setVisible(true);
		
		gr.add(r1);
		gr.add(r2);
		gr.add(r3);
		p.add(b);
		p.add(c);
		p.add(r1);
		p.add(r2);
		p.add(r3);
		
		add(p,"North");
		add(d,"Center");
		
		b.addActionListener(this);
		c.setBackground(Color.black);
	}
	
	public void actionPerformed(ActionEvent e) {
		color = JColorChooser.showDialog(this, "Select a Color", Color.black);
		c.setBackground(color);
	}
	
	public class Draw extends JPanel implements MouseListener, MouseMotionListener {
		
		Draw() {
			addMouseListener(this);
			addMouseMotionListener(this);
			setBackground(Color.white);
		}
		
		public void mouseDragged(MouseEvent e) {
			if(r3.isSelected()) {
				Graphics g = getGraphics();
				g.setColor(color);
				g.fillOval(e.getX()-3, e.getY()-3, 6, 6);
			}
		}
		
		public void mouseMoved(MouseEvent e) {}
		
		public void mouseClicked(MouseEvent e) {
			if(r1.isSelected()) {
				Graphics g = getGraphics();
				g.setColor(color);
				g.fillOval(e.getX()-20, e.getY()-20, 40, 40);
			}
			if(r2.isSelected()) {
				Graphics g = getGraphics();
				g.setColor(color);
				int X = e.getX(), Y = e.getY();
				int[] x = {X, X-7, X-31, X-12, X-19, X, X+19, X+12, X+31, X+7};
				int[] y = {Y-32, Y-10, Y-10, Y+4, Y+26, Y+12, Y+26, Y+4, Y-10, Y-10};
				g.fillPolygon( x, y, 10);
			}
		}
		
		public void mousePressed(MouseEvent e) {}
		
		public void mouseReleased(MouseEvent e) {}
		
		public void mouseEntered(MouseEvent e) {}
		
		public void mouseExited(MouseEvent e) {}
	}
}