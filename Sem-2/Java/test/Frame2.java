package test;

import javax.swing.*;
import java.awt.event.*;

public class Frame2 extends JFrame
{
	private JButton button = new JButton("Press Me!");
	private JLabel label = new JLabel("Go on, press the button.");
	private JPanel background = new JPanel();
	
	public Frame2()
	{
		button.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				label.setText("Thank You!!");
			}
		});
		background.add(button);
		background.add(label);
		
		getContentPane().add(background);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		pack();
	}
	
	public static void main(String[] args)
	{
		new Frame2();
	}
}