package executable;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractButton;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class TicTacToe extends JFrame {
	String p1,p2;
	Players pl = new Players();
	
	private class Players extends JPanel implements ActionListener {
		JLabel l1 = new JLabel("Player-1 (X) :");
		JLabel l2 = new JLabel("Player-2 (O) :");
		JTextField tf1 = new JTextField("P1",20);
		JTextField tf2 = new JTextField("P2",20);
		JButton b = new JButton("Next");
		
		Players() {
			setLayout(new GridLayout(3,2,5,5));
			add(l1);
			add(tf1);
			add(l2);
			add(tf2);
			add(b);
			
			b.addActionListener(this);
		}

		public void actionPerformed(ActionEvent e) {
			p1 = pl.tf1.getText().toUpperCase();
			p2 = pl.tf2.getText().toUpperCase();
			Game g = new Game();
			getContentPane().removeAll();
			getContentPane().add(g);
			pack();
		}
	}
	
	private class Game extends JPanel implements ActionListener {
		JLabel l1, l2;
		String s1 = "Player-1's Turn", s2 = "Player-2's Turn";
		JLabel l3 = new JLabel(s1,JLabel.CENTER);
		JButton[][] b = new JButton[3][3];
		JButton b3 = new JButton("New Game");
		GridBagConstraints c = new GridBagConstraints();
		JPanel top = new JPanel(new GridBagLayout());
		JPanel cen = new JPanel(new GridBagLayout());
		JPanel bot = new JPanel(new GridLayout(2,1,5,5));
		int x = 0;
		
		Game() {
			setLayout(new BorderLayout());
			c.fill = GridBagConstraints.HORIZONTAL;
			
			north();
			center();
			south();
			
			add(top,"North");
			add(cen,"Center");
			add(bot,"South");
		}
		
		private void north() {
			l1 = new JLabel("Player-1 (X) : " + p1);
			l2 = new JLabel("Player-2 (O) : " + p2);
			l1.setForeground(Color.blue);

			c.insets = new Insets(10,10,10,10);
			c.gridx = 0;
			c.gridy = 0;
			c.gridwidth = 3;
			top.add(l1,c);

			c.gridx = 3;
			c.gridy = 0;
			c.gridwidth = 3;
			top.add(l2,c);
		}
		private void center() {
			c.insets = new Insets(0,0,0,0);
			for(int i=0; i<3; i++)
				for(int j=0; j<3; j++) {
					b[i][j] = new JButton(" ");
					b[i][j].setFont(new Font(Font.SANS_SERIF,Font.BOLD,15));
					b[i][j].addActionListener(this);
					
					c.gridx = i * 10;
					c.gridy = j * 10;
					c.gridwidth = 10;
					c.ipady = 20;
					cen.add(b[i][j],c);
				}
		}
		private void south() {
			c.insets = new Insets(10,10,10,10);
			c.gridx = 0;
			c.gridy = 0;
			bot.add(l3,c);

			c.gridy = 10;
			bot.add(b3,c);
			b3.addActionListener(this);
		}
		private void check(ActionEvent e, String s) {
			for(int i=0; i<3; i++)
				for(int j=0; j<3; j++) {
					if(e.getSource()==b[i][j]) {
						b[i][j].setText(s);
						b[i][j].removeActionListener(this);
					}
				}
		}
		private String win() {
			String[][] ar = new String[3][3];
			if (x > 4) {
				for(int i=0; i<3; i++)
					for(int j=0;j<3; j++)
						ar[i][j] = b[i][j].getText();
				
				if(ar[0][0].equals(ar[0][1]) && ar[0][0].equals(ar[0][2]) && !ar[0][0].equals(" ")) {
					b[0][0].setBackground(Color.lightGray);
					b[0][1].setBackground(Color.lightGray);
					b[0][2].setBackground(Color.lightGray);
					return ar[0][0];
				}
				else if(ar[1][0].equals(ar[1][1]) && ar[1][0].equals(ar[1][2]) && !ar[1][0].equals(" ")) {
					b[1][0].setBackground(Color.lightGray);
					b[1][1].setBackground(Color.lightGray);
					b[1][2].setBackground(Color.lightGray);
					return ar[1][0];
				}
				else if(ar[2][0].equals(ar[2][1]) && ar[2][0].equals(ar[2][2]) && !ar[2][0].equals(" ")) {
					b[2][0].setBackground(Color.lightGray);
					b[2][1].setBackground(Color.lightGray);
					b[2][2].setBackground(Color.lightGray);
					return ar[2][0];
				}
				else if(ar[0][0].equals(ar[1][0]) && ar[0][0].equals(ar[2][0]) && !ar[0][0].equals(" ")) {
					b[0][0].setBackground(Color.lightGray);
					b[1][0].setBackground(Color.lightGray);
					b[2][0].setBackground(Color.lightGray);
					return ar[0][0];
				}
				else if(ar[0][1].equals(ar[1][1]) && ar[0][1].equals(ar[2][1]) && !ar[0][1].equals(" ")) {
					b[0][1].setBackground(Color.lightGray);
					b[1][1].setBackground(Color.lightGray);
					b[2][1].setBackground(Color.lightGray);
					return ar[0][1];
				}
				else if(ar[0][2].equals(ar[1][2]) && ar[0][2].equals(ar[2][2]) && !ar[0][2].equals(" ")) {
					b[0][2].setBackground(Color.lightGray);
					b[1][2].setBackground(Color.lightGray);
					b[2][2].setBackground(Color.lightGray);
					return ar[0][2];
				}
				else if(ar[0][0].equals(ar[1][1]) && ar[0][0].equals(ar[2][2]) && !ar[0][0].equals(" ")) {
					b[0][0].setBackground(Color.lightGray);
					b[1][1].setBackground(Color.lightGray);
					b[2][2].setBackground(Color.lightGray);
					return ar[0][0];
				}
				else if(ar[0][2].equals(ar[1][1]) && ar[0][2].equals(ar[2][0]) && !ar[0][2].equals(" ")) {
					b[0][2].setBackground(Color.lightGray);
					b[1][1].setBackground(Color.lightGray);
					b[2][0].setBackground(Color.lightGray);
					return ar[0][2];
				}
				return "A";
			}
			return "A";
		}
		private void remove() {
			for(int i=0; i<3; i++)
				for(int j=0; j<3; j++)
						b[i][j].removeActionListener(this);
		}
		public void actionPerformed(ActionEvent e) {
			if(e.getSource() == b3) {
				getContentPane().removeAll();
				getContentPane().add(pl);
				pack();
			}
			else {
				if(x%2==0) {
					check(e,"X");
					l3.setText(s2);
					l1.setForeground(Color.black);
					l2.setForeground(Color.blue);
					x++;
				}
				else {
					check(e,"O");
					l3.setText(s1);
					l2.setForeground(Color.black);
					l1.setForeground(Color.blue);
					x++;
				}
				String s = win();
				if(!s.equals("A")) {
					remove();
					l3.setForeground(Color.blue);
					if(s.equals("X")) {
						l1.setForeground(Color.green);
						l2.setForeground(Color.red);
						l3.setText(p1 + "  WINS !!");
					}
					else if(s.equals("O")) {
						l1.setForeground(Color.red);
						l2.setForeground(Color.green);
						l3.setText(p2 + "  WINS !!");
					}
				}
				else if(x == 9) {
					l1.setForeground(Color.black);
					l2.setForeground(Color.black);
					l3.setForeground(Color.blue);
					l3.setText("Game Ties..");
				}
			}
		}
	}
	
	public TicTacToe() {
		getContentPane().add(pl);
		setVisible(true);
		pack();
	}
}
