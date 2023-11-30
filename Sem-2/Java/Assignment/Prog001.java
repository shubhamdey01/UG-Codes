// Factorial

package hw;

public class Prog001 {
	public static void main(String[] args) {
		int n=6,fact=1;
		for(int i=n;i>0;i--) {
			fact *= i;
		}
		System.out.println("Factorial = "+fact);
	}
}