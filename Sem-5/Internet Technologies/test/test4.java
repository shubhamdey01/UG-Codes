import java.util.Scanner;
import java.sql.*;

public class test4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char ch;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost/web","shubham","shubham");
            Statement st = con.createStatement();
            PreparedStatement pst = con.prepareStatement("insert into counts values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
            ResultSet re;
            String q;
            System.out.print("Enter the String : ");
            String str = sc.nextLine();
            pst.setString(1, str);
            for(int i=0; i<26; i++) {
                q = "select length(\""+str+"\")-length(replace(upper(\""+str+"\"),\""+(char)(65+i)+"\",\"\"))";
                re = st.executeQuery(q);
                re.next();
//                System.out.println((char)(65+i)+" = "+re.getInt(1));
                pst.setInt(2+i, re.getInt(1));
            }
            pst.executeUpdate();
            System.out.println("Successful.\n");

        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
