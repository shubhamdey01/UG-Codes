package executable;

import java.awt.Color;
import java.awt.Desktop;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * This class provides menu to the users and runs the program they want to.
 * 
 * @author Shubham Dey
 */

public class Menu extends JFrame implements ActionListener {
	JLabel l0,l1,l2,l3,l4,l5,l6,l7,l8,l9;
	JButton b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
	File f = new File("executable\\package-summary.html");
	JPanel bg = new JPanel();
	Font f1 = new Font("Segoe Print",1,16);
	Font f2 = new Font("Comic Sans MS",3,14);
	GridBagConstraints c = new GridBagConstraints();
	
	/**
	 * adds required objects to the JFrame and
	 * adds actionListener to the buttons
	 */
	public Menu() {
		bg.setLayout(new GridBagLayout());
		bg.setBackground(Color.cyan);
		c.fill = GridBagConstraints.HORIZONTAL;
		c.insets = new Insets(10,10,10,10);
		
		zero();
		one();
		two();
		three();
		four();
		five();
		six();
		seven();
		eight();
		nine();
		
		getContentPane().add(bg);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		//setBounds(150,150,300,500);
		setLocation(150,150);
		pack();
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b0) {
			try {
				Desktop.getDesktop().browse(f.toURI());
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
		if(e.getSource() == b1)
			new DrawFillRect();
		if(e.getSource() == b2)
			new RectCircle();
		if(e.getSource() == b3)
			new Cube();
		if(e.getSource() == b4)
			new Stack().menu();
		if(e.getSource() == b5)
			new MergeSort().run();
		if(e.getSource() == b6)
			new Complex().run();
		if(e.getSource() == b7)
			new ComplexMatrix().start();
		if(e.getSource() == b8)
			new DrawingPad();
		if(e.getSource() == b9)
			new TicTacToe();
	}
	
	/**
	 * modifies the style of JLabel & JButton
	 * @param l JLabel
	 * @param b JButton
	 */
	private void set(JLabel l, JButton b) {
		l.setFont(f1);
		b.setFont(f2);
		b.setBackground(Color.lightGray);
	}
	
	/**
	 * adds program "DrawFillRect" to the frame when called
	 */
	private void zero() {
		l0 = new JLabel("#  Documentation");
		b0 = new JButton("Open");
		b0.addActionListener(this);
		set(l0,b0);

		c.gridx = 0;
		c.gridy = 0;
		c.gridwidth = 3;
		bg.add(l0,c);

		c.gridx = 3;
		c.gridy = 0;
		bg.add(b0,c);
	}
	
	/**
	 * adds program "DrawFillRect" to the frame when called
	 */
	private void one() {
		l1 = new JLabel("1. Draw Hollow & Filled Rectangle");
		b1 = new JButton("Run(1)");
		b1.addActionListener(this);
		set(l1,b1);

		c.gridx = 0;
		c.gridy = 1;
		c.gridwidth = 3;
		bg.add(l1,c);

		c.gridx = 3;
		c.gridy = 1;
		bg.add(b1,c);
	}

	/**
	 * adds program "RectCircle" to the frame when called
	 */
	private void two() {
		l2 = new JLabel("2. Draw Rectangle & Circle");
		b2 = new JButton("Run(2)");
		b2.addActionListener(this);
		set(l2,b2);
		
		c.gridx = 0;
		c.gridy = 2;
		c.gridwidth = 3;
		bg.add(l2,c);

		c.gridx = 3;
		c.gridy = 2;
		bg.add(b2,c);
	}

	/**
	 * adds program "Cube" to the frame when called
	 */
	private void three() {
		l3 = new JLabel("3. Draw 3D Cube with shadow");
		b3 = new JButton("Run(3)");
		b3.addActionListener(this);
		set(l3,b3);
		
		c.gridx = 0;
		c.gridy = 3;
		c.gridwidth = 3;
		bg.add(l3,c);

		c.gridx = 3;
		c.gridy = 3;
		bg.add(b3,c);
	}
	
	/**
	 * adds program "Stack" to the frame when called
	 */
	private void four() {
		l4 = new JLabel("4. Stack implementation using Linked-List");
		b4 = new JButton("Run(4)");
		b4.addActionListener(this);
		set(l4,b4);
		
		c.gridx = 0;
		c.gridy = 4;
		c.gridwidth = 3;
		bg.add(l4,c);

		c.gridx = 3;
		c.gridy = 4;
		bg.add(b4,c);
	}

	/**
	 * adds program "MergeSort" to the frame when called
	 */
	private void five() {
		l5 = new JLabel("5. Merge Sort");
		b5 = new JButton("Run(5)");
		b5.addActionListener(this);
		set(l5,b5);
		
		c.gridx = 0;
		c.gridy = 5;
		c.gridwidth = 3;
		bg.add(l5,c);

		c.gridx = 3;
		c.gridy = 5;
		bg.add(b5,c);
	}

	/**
	 * adds program "Complex" to the frame when called
	 */
	private void six() {
		l6 = new JLabel("6. Complex Number Arithematic Operations");
		b6 = new JButton("Run(6)");
		b6.addActionListener(this);
		set(l6,b6);
		
		c.gridx = 0;
		c.gridy = 6;
		c.gridwidth = 3;
		bg.add(l6,c);

		c.gridx = 3;
		c.gridy = 6;
		bg.add(b6,c);
	}

	/**
	 * adds program "ComplexMatrix" to the frame when called
	 */
	private void seven() {
		l7 = new JLabel("7. Complex Matrix multiplication");
		b7 = new JButton("Run(7)");
		b7.addActionListener(this);
		set(l7,b7);
		
		c.gridx = 0;
		c.gridy = 7;
		c.gridwidth = 3;
		bg.add(l7,c);

		c.gridx = 3;
		c.gridy = 7;
		bg.add(b7,c);
	}

	/**
	 * adds program "DrawingPad" to the frame when called
	 */
	private void eight() {
		l8 = new JLabel("8. Drawing Pad");
		b8 = new JButton("Run(8)");
		b8.addActionListener(this);
		set(l8,b8);
		
		c.gridx = 0;
		c.gridy = 8;
		c.gridwidth = 3;
		bg.add(l8,c);

		c.gridx = 3;
		c.gridy = 8;
		bg.add(b8,c);
	}

	/**
	 * adds program "TicTacToe" to the frame when called
	 */
	private void nine() {
		l9 = new JLabel("9. Tic-Tac-Toe");
		b9 = new JButton("Run(9)");
		b9.addActionListener(this);
		set(l9,b9);
		
		c.gridx = 0;
		c.gridy = 9;
		c.gridwidth = 3;
		bg.add(l9,c);

		c.gridx = 3;
		c.gridy = 9;
		bg.add(b9,c);
	}
}
