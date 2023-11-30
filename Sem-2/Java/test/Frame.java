package test;

import javax.swing.*;

public class Frame {
	public static void main(String[] args) {
		JFrame f = new JFrame("My First GUI");
		JPanel bg = new JPanel();
		JButton b = new JButton("Press Me!");		// create button
		JButton b2 = new JButton("Press");
		b.setBounds(10,10,100,35);
		b2.setBounds(10,50,100,35);
		bg.setLayout(null);
		bg.add(b);
		bg.add(b2);
		f.getContentPane().add(bg,"Center");					// add the button to the frame
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setBounds(200,200,600,400);
		f.setVisible(true);
	}
}