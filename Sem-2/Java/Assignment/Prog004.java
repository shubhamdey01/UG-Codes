// Roots of a quadratic equation

package hw;

import java.lang.Math;
import java.util.Scanner;

class Roots {
	int a,b,c;
	double D,x1,x2,re,im;
	public void get() {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter coefficients a,b,c :");
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		in.close();
	}
	public void check() {
		D = b*b - 4*a*c;
		
		if(D>0) {
			System.out.println("Two Real & Distinct roots.");
			x1 = (-b + Math.sqrt(D))/(2*a);
			x2 = (-b - Math.sqrt(D))/(2*a);
			System.out.println("Roots are : "+x1+" & "+x2);
		}
		else if(D==0) {
			System.out.println("Two Real & Equal roots.");
			x1 = -b/(double)(2*a);
			System.out.println("Roots are : "+x1+" & "+x1);
		}
		else {
			System.out.println("Two Imaginary roots.");
			re = -b/(double)(2*a);
			im = Math.sqrt(-D)/(2*a);
			if(im<0) {
				System.out.println("Roots are : "+re+" + i "+-im+" & "+re+" - i "+-im);
			}
			else {
				System.out.println("Roots are : "+re+" + i "+im+" & "+re+" - i "+im);
			}
		}
	}
}

public class Prog004 {

	public static void main(String[] args) {
		Roots num = new Roots();
		num.get();
		num.check();
	}
}
