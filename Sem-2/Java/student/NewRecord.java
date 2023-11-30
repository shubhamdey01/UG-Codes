package student;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

public class NewRecord extends JPanel implements ActionListener
{
	JLabel l1 = new JLabel("ID");
	JLabel l2 = new JLabel("Name");
	JLabel l3 = new JLabel("Age");
	JLabel l4 = new JLabel();
	JTextField tf1 = new JTextField(15);
	JTextField tf2 = new JTextField(15);
	JComboBox tf3 = new JComboBox();
	JButton b1 = new JButton("Submit");
	JRadioButton r1 = new JRadioButton("Male");
	JRadioButton r2 = new JRadioButton("Female");
	ButtonGroup gr = new ButtonGroup();
	
	NewRecord()
	{
		tf3.addItem("Select Age");
		for(int i=15;i<=30;)
			tf3.addItem(i++);
		
		l1.setLabelFor(tf1);
		l2.setLabelFor(tf2);
		l3.setLabelFor(tf3);
		gr.add(r1);
		gr.add(r2);
		
		setLayout(new GridLayout(5,2,2,2));
		add(l1);
		add(tf1);
		add(l2);
		add(tf2);
		add(l3);
		add(tf3);
		add(r1);
		add(r2);
		add(b1);
		add(l4);

		b1.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			entry();
			clear();
		}
	}
	
	protected void entry()
	{
		int id = Integer.parseInt(tf1.getText());
		String name = tf2.getText();
		String g = " ";
		int age = (int) tf3.getSelectedItem();
		if(r1.isSelected())
			g = "M";
		if(r2.isSelected())
			g = "F";
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost/student","root","shubham");
			Statement st = con.createStatement();
			st.executeUpdate(String.format("insert into SData values(%d,'%s','%s',%d)",id,name,g,age));
			con.close();
			l4.setForeground(Color.green);
			l4.setText("Details submitted");
		} catch(Exception e) {
			l4.setForeground(Color.red);
			l4.setText("An error occurred");
		}
	}
	protected void clear()
	{
		tf1.setText("");
		tf2.setText("");
		tf3.setSelectedIndex(0);
		gr.clearSelection();
	}
}