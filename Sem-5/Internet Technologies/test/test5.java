import java.util.Scanner;
import java.sql.*;

public class test5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char ch;
        try {
//            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost/web","shubham","shubham");
            Statement st = con.createStatement();
            PreparedStatement pst = con.prepareStatement("insert into mcq values(?, ?, ?, ?, ?)");
            ResultSet r;

            do {
                System.out.println("\n1. Enter Questions");
                System.out.println("2. MCQ");
                System.out.println("3. Exit\n");
                System.out.print("Enter your choice : ");
                ch = sc.next().charAt(0);
                sc.nextLine();

                if(ch == '1') {
                    System.out.println("Enter the question :");
                    String que = sc.nextLine();
                    pst.setString(1,que);
                    System.out.println("Enter the option 1 :");
                    String op1 = sc.nextLine();
                    pst.setString(2,op1);
                    System.out.println("Enter the option 2 :");
                    String op2 = sc.nextLine();
                    pst.setString(3,op2);
                    System.out.println("Enter the option 3 :");
                    String op3 = sc.nextLine();
                    pst.setString(4,op3);
                    System.out.println("Enter correct option :");
                    int ans = sc.nextInt();
                    pst.setInt(5,ans);
                    pst.executeUpdate();
                }
                else if (ch == '2') {
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
                }
            } while(ch != '3');
        } catch (Exception e) {
//            System.out.println(e);
        }
    }
}
