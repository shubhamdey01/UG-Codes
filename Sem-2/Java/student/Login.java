package student;

import java.awt.Color;
import java.awt.GridLayout;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class Login extends JPanel
{
	JLabel l1 = new JLabel("Username");
	JLabel l2 = new JLabel("Password");
	JLabel l3 = new JLabel();
	JTextField tf = new JTextField(15);
	JPasswordField pf = new JPasswordField(15);
	JButton b = new JButton("LogIN");
	
	Login()
	{
		l1.setLabelFor(tf);
		l2.setLabelFor(pf);
		
		setLayout(new GridLayout(3,2,2,2));
		add(l1);
		add(tf);
		add(l2);
		add(pf);
		add(b);
		add(l3);
	}
	protected boolean check(String user)
	{
		String pass = " ";
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost/student","root","shubham");
			Statement st = con.createStatement();
			ResultSet r = st.executeQuery(String.format("select pass from users where user = '%s'",user));
			r.next();
			pass = r.getString(1);
			con.close();
		} catch(Exception e) {pass = " ";}
		
		if(String.valueOf(pf.getPassword()).equals(pass))
		{
			l3.setText("");
			return true;
		}
		return false;
	}
	protected void clear(char c)
	{
		tf.setText("");
		pf.setText("");
		if(c=='A')
		{
			l3.setForeground(Color.red);
			l3.setText("Wrong details");
		}
		else
		{
			l3.setForeground(Color.green);
			l3.setText("Logged Out successfully");
		}
	}
}