import java.util.Scanner;

/**
 * This is my first program in Java.
 * @author Shubham Dey
 */

public class Hello {
	/**
	 * Prints Hello on the Console
	 * @param args does nothing
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1,s2,s3,s4;
		System.out.println("!!! Hello World !!!");
		System.out.println("Name : ");
		s1 = sc.next();
		s2 = sc.next();
		s3 = sc.next();
		s4 = sc.next();
		System.out.println(s1);
		System.out.println(s2);
		System.out.println(s3);
		System.out.println(s4);
		sc.close();
	}
}