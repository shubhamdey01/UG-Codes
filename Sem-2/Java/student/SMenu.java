package student;

import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SMenu extends JMenuBar implements ActionListener
{
	JMenu p = new JMenu("*_*");
	JMenu m = new JMenu("Menu");
	
	JMenuItem i1 = new JMenuItem("Update");
	JMenuItem i2 = new JMenuItem("Delete");
	JMenuItem i3 = new JMenuItem("Change Password");
	JMenuItem i4 = new JMenuItem("LogOUT");
	
	SMenu()
	{
		m.setForeground(Color.blue);
		p.setForeground(Color.blue);
		
		m.add(i1);
		m.add(i2);
		p.add(i3);
		p.add(i4);
		
		add(m);
		add(p);
	}
	public void actionPerformed(ActionEvent e)
	{
		
	}
}