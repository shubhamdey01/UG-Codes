import java.util.Scanner;
import java.sql.*;

public class test3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char ch;
        try {
//            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost/web","shubham","shubham");
            Statement st = con.createStatement();
            PreparedStatement pst = con.prepareStatement("insert into expressions values(?, ?)");
            do {
                System.out.print("Enter the expression : ");
                String ex = sc.nextLine();
                ResultSet re = st.executeQuery("select " + ex);
                re.next();
                pst.setString(1, ex);
                pst.setDouble(2, re.getDouble(1));
                pst.executeUpdate();
                System.out.println("Successfully updated the table.\n");
                System.out.print("Want to insert more ? (y/n) : ");
                ch = sc.next().charAt(0);
                sc.nextLine();
            } while(ch == 'y' || ch == 'Y');
        } catch (Exception e) {
//            System.out.println(e);
        }
    }
}