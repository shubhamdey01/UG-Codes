import java.util.Scanner;
import java.sql.*;

public class test6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ch;
        try {
//            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost/web","shubham","shubham");
            Statement st = con.createStatement();
            PreparedStatement pst = con.prepareStatement("insert into mcq values(null,?, ?, ?, ?, ?, null, ?, ?)");
            ResultSet r;

            do {
                System.out.println("\n1. New Bill");
                System.out.println("2. Search Bill");
                System.out.println("3. Exit\n");
                System.out.print("Enter your choice : ");
                ch = sc.nextInt();
                switch (ch) {
                    case 1:
                        sc.nextLine();
                        System.out.print("Customer Name : ");
                        String CName = sc.nextLine();
                        pst.setString(1,CName);
                        System.out.print("Item Name : ");
                        String IName = sc.nextLine();
                        pst.setString(2,IName);
                        System.out.print("Item Quantity : ");
                        int IQun = sc.nextInt();
                        pst.setInt(3,IQun);
                        System.out.print("Price per Item : ");
                        double PpI = sc.nextDouble();
                        pst.setDouble(4,PpI);
                        double gst = (double)Math.round(PpI * 0.18 * 100)/100;
                        pst.setDouble(5,gst);
                        double total = IQun * (PpI + gst);
                        pst.setDouble(6,total);
                        sc.nextLine();
                        System.out.print("Item Category : ");
                        String  ICat = sc.nextLine();
                        pst.setString(7,ICat);
                        System.out.println(pst.toString());
                        pst.executeUpdate();
                        break;
                    case 2:
                        String q = "select * from mcq";
                        r = st.executeQuery(q);
                        int i = 1;
                        while(r.next()) {
                            System.out.println("\nQ"+ i + ". "+ r.getString(1));
                            System.out.println(1 + ". " + r.getString(2));
                            System.out.println(2 + ". " + r.getString(3));
                            System.out.println(3 + ". " + r.getString(4));
                            System.out.print("Answer : ");
                            int a = sc.nextInt();
                            if(a == r.getInt(5))
                                System.out.println("CORRECT");
                            else {
                                int ca = r.getInt(5);
                                System.out.println("WRONG. Correct answer is :\n"+ca+". "+r.getString("op"+ca));
                            }
                            i++;
                        }
                        break;
                    case 3:
                        System.out.println("\nBYE.");
                        break;
                    default:
                        System.out.println("Please enter correct choice");
                }
            } while(ch != '3');
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
