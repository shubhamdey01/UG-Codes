import java.sql.*;

public class test1
{
    public static void main(String[] args)
    {
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost","shubham","shubham");
            Statement st = con.createStatement();
            try {

                String q1 = "create database College_Data";
                st.executeUpdate(q1);
            } catch(Exception e) {
                System.out.println(e);
            }
            String q = "use College_Data";
            st.executeUpdate(q);
            try {
                String q1 = "create table Student_Register(Roll int primary key, Date date, Name varchar(20) not null);";
                st.executeUpdate(q1);
            } catch(Exception e) {
                System.out.println(e);
            }

//            q = "insert into Student_Register values(1,\"2022-10-12\",\"Madhusudan\")";
//            st.executeUpdate(q);
//            q = "insert into Student_Register values(2,\"2022-11-12\",\"Ritidip\")";
//            st.executeUpdate(q);
//            q = "insert into Student_Register values(3,\"2022-10-9\",\"SK Uddin\")";
//            st.executeUpdate(q);
//            q = "insert into Student_Register values(4,\"2022-10-12\",\"Bishnu\")";
//            st.executeUpdate(q);
            ResultSet r = st.executeQuery("select * from Student_Register");
            while(r.next())
                System.out.println(r.getString(1)+'\t'+r.getString(2)+'\t'+r.getString(3));

            con.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
