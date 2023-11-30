// Combination : nCr

package hw;

public class Prog002 {
	public static void main(String[] args) {
		int n=10,r=4;
		float C=1;
	    while(n>r)
	    {
	        C = C*n/(n-r);
	        n--;
	    }
	    System.out.println("nCr = C(10,4) = "+C);
	}
}
