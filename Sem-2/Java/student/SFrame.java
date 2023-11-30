package student;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;

public class SFrame extends JFrame implements ActionListener
{
	Login l = new Login();
	NewRecord d = new NewRecord();
	UpdateRecord u = new UpdateRecord();
	SMenu m = new SMenu();
	String user = " ";
	
	SFrame()
	{		
		setTitle("Student Management System");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		setLocation(200,150);

		getContentPane().add(l);
		pack();
		
		l.b.addActionListener(this);
		m.i4.addActionListener(this);
		m.i1.addActionListener(this);
		u.b.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==l.b)
		{
			user = l.tf.getText();
			if(l.check(user))
			{
				getContentPane().removeAll();
				getContentPane().add(d);
				setJMenuBar(m);
				pack();
			}
			else
				l.clear('A');
		}
		if(e.getSource()==m.i4)
		{
			setJMenuBar(null);
			getContentPane().removeAll();
			getContentPane().add(l);
			pack();
			l.clear(' ');
		}
		if(e.getSource()==m.i1)
		{
			getContentPane().removeAll();
			u.takeID();
			getContentPane().add(u);
			pack();
		}
		if(e.getSource() == u.b)
			if(u.getName().equals("takeData"))
				pack();
	}
}