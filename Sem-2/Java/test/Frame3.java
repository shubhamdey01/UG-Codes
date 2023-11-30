package test;

import javax.swing.*;
import java.awt.Color;
import java.awt.event.*;

public class Frame3 extends JFrame implements ActionListener
{
	private JButton rect = new JButton("Rect");
	private JButton tri = new JButton("Tri");
	private JLabel label = new JLabel("Go on, press the button.");
	private JPanel background = new JPanel();
	
	public Frame3()
	{
		rect.addActionListener(this);
		tri.addActionListener(this);
		background.add(rect);
		background.add(tri);
		background.add(label);
		
		getContentPane().add(background);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		pack();
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==rect)
			label.setText("Rectangle");
		if(e.getSource()==tri)
			label.setText("Triangle");
	}
	
	public static void main(String[] args)
	{
		new Frame3();
	}
}