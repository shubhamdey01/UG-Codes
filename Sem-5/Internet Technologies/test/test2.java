import java.sql.*;
import java.time.LocalDate;

public class test2 {
    public static void main(String[] args) {
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost","shubham","shubham");
            Statement st = con.createStatement();
            try {

                String q1 = "create database College_Data";
                st.executeUpdate(q1);
            } catch(Exception e) {
//                System.out.println(e);
            }
            String q = "use College_Data";
            st.executeUpdate(q);
            try {
                String q1 = "create table Student_Register1(Roll int primary key, Date date, Name varchar(20) not null);";
                st.executeUpdate(q1);
            } catch(Exception e) {
//                System.out.println(e);
            }
            try {
                String Q = "insert into Student_Register1 values(?,?,?);";
                PreparedStatement pst = con.prepareStatement(Q);
                for(int i=1; i<=100; i++) {
                    LocalDate date = createRandomDate(1900, 2000);
                    String name = getAlphaNumericString(7);
                    pst.setInt(1, i);
                    pst.setDate(2, Date.valueOf(date));
                    pst.setString(3, name);
                    pst.executeUpdate();
                }
            } catch (Exception e) {
                System.out.println(e);
            }
//            ResultSet r = st.executeQuery("select * from Student_Register");
//            while(r.next())
//                System.out.println(r.getString(1)+'\t'+r.getString(2)+'\t'+r.getString(3));

            con.close();
        }
        catch(Exception e)
        {
//            System.out.println(e);
        }

    }
    public static int createRandomIntBetween(int start, int end) {
        return start + (int) Math.round(Math.random() * (end - start));
    }
    public static LocalDate createRandomDate(int startYear, int endYear) {
        int day = createRandomIntBetween(1, 28);
        int month = createRandomIntBetween(1, 12);
        int year = createRandomIntBetween(startYear, endYear);
        return LocalDate.of(year, month, day);
    }
    public static String getAlphaNumericString(int n)
    {
        String AlphaNumericString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" + "0123456789" + "abcdefghijklmnopqrstuvxyz";
        StringBuilder sb = new StringBuilder(n);
        for (int i = 0; i < n; i++) {
            int index  = (int)(AlphaNumericString.length() * Math.random());
            sb.append(AlphaNumericString.charAt(index));
        }
        return sb.toString();
    }
}
