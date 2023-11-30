package student;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import javax.swing.*;

public class UpdateRecord extends JPanel implements ActionListener
{
	JLabel l1 = new JLabel("Student ID");
	JLabel l2 = new JLabel();
	JTextField tf = new JTextField(10);
	JButton b = new JButton("Proceed >>");

	JLabel l3 = new JLabel("Name");
	JLabel l4 = new JLabel("Age");
	JTextField tf3 = new JTextField(15);
	JComboBox tf4 = new JComboBox();
	JRadioButton r1 = new JRadioButton("Male");
	JRadioButton r2 = new JRadioButton("Female");
	ButtonGroup gr = new ButtonGroup();
	JButton b1 = new JButton("Submit");

	int id,age;
	String name,g;

	UpdateRecord() {
		setName("UpdateRecord");
	}
	protected void takeID()
	{
		removeAll();
		setName("takeID");
		setLayout(new GridLayout(2,2,5,5));
		add(l1);
		add(tf);
		add(b);
		add(l2);
		b.addActionListener(this);
	}
	private void check()
	{
		id = Integer.parseInt(tf.getText());
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost/student","root","shubham");
			PreparedStatement st = con.prepareStatement("SELECT * FROM sdata WHERE id = ?");
			st.setInt(1,id);
			ResultSet r = st.executeQuery();
			if(!r.next())
			{
				l2.setForeground(Color.red);
				l2.setText("No such ID exists!!");
			}
			else {
				l2.setText(" ");
				name = r.getString("Name");
				age = r.getInt("Age");
				g = r.getString("Sex");
				takeData();
			}
			con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	private void takeData()
	{
		removeAll();
		setName("takeData");
		tf4.addItem("Select Age");
		for(int i=15;i<=30;)
			tf4.addItem(i++);

		l3.setLabelFor(tf3);
		l4.setLabelFor(tf4);
		gr.add(r1);
		gr.add(r2);

		tf3.setText(name);
		tf4.setSelectedIndex(age-14);
		if(g.equals("M"))
			r1.setSelected(true);
		if(g.equals("F"))
			r2.setSelected(true);

		setLayout(new GridLayout(4,2,2,2));
		add(l3);
		add(tf3);
		add(l4);
		add(tf4);
		add(r1);
		add(r2);
		add(b1);

		b1.addActionListener(this);
	}
	protected void submit()
	{
		name = tf3.getText();
		age = (int) tf4.getSelectedItem();
		if(r1.isSelected())
			g = "M";
		if(r2.isSelected())
			g = "F";
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost/student","root","shubham");
			Statement st = con.createStatement();
			st.executeUpdate(String.format("update SData set name='%s',sex='%s',age=%d where id=%d",name,g,age,id));
			con.close();
			l2.setForeground(Color.green);
			l2.setText("Details submitted");
		} catch(Exception e) {
			l2.setForeground(Color.red);
			l2.setText("An error occurred");
		}
		takeID();
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource() == b)
			check();
		if(e.getSource() == b1)
			submit();
	}
}