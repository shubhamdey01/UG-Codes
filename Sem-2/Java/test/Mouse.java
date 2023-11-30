package test;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Mouse extends JPanel implements MouseMotionListener, MouseListener {
	
	Mouse() {
		//addMouseMotionListener(this);
		addMouseListener(this);
		setBackground(Color.white);
	}
	
	public static void main(String[] args) {
		Mouse m = new Mouse();
		JFrame f = new JFrame();
		JLabel l = new JLabel("Click & drag to draw",JLabel.CENTER);
		
		f.setLayout(new BorderLayout());
		f.add(l,"North");
		f.add(m,"Center");
		
		f.setVisible(true);
		f.setBounds(100, 100, 300, 300);
		f.setDefaultCloseOperation(f.EXIT_ON_CLOSE);
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		Graphics g = getGraphics();
		g.setColor(Color.blue);
		g.fillOval(e.getX()-3, e.getY()-3, 6, 6);
	}

	@Override
	public void mouseMoved(MouseEvent e) {}

	@Override
	public void mouseClicked(MouseEvent e) {
		Graphics g = getGraphics();
		g.setColor(Color.blue);
		int X = e.getX(), Y = e.getY();
		int[] x = {X, X-7, X-31, X-12, X-19, X, X+19, X+12, X+31, X+7};
		int[] y = {Y-32, Y-10, Y-10, Y+4, Y+26, Y+12, Y+26, Y+4, Y-10, Y-10};
		g.fillPolygon( x, y, 10);
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
