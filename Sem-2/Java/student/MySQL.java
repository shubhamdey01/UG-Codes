package student;

import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;

public class MySQL
{
	public static void main(String[] args)
	{
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost/student","root","shubham");
			Statement st = con.createStatement();
			ResultSet r = st.executeQuery("select * from SDATA where ID = 5");
			if(!r.next())
				System.out.println("Not found");
			else
				System.out.println(r.getString("Name"));
			
			con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}