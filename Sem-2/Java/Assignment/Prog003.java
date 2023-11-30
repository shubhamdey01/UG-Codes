// Circle : circumference, area, place of a point

package hw;

import java.lang.Math;
import java.util.Scanner;

class Circle {
	public double x,y,r;
	public double circumference() {
		return 2*Math.PI*r;
	}
	public double area() {
		return Math.PI*r*r;
	}
	public void inside() {
		double d = Math.sqrt(x*x + y*y);
		if(d>r) {
			System.out.println("Outside the circle.");
		}
		else if(d==r) {
			System.out.println("On the circle.");
		}
		else {
			System.out.println("Inside the circle.");
		}
	}
}

public class Prog003 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Circle a = new Circle();
		System.out.println("Enter r =\t");
		a.r = in.nextDouble();
		System.out.println("Enter x & y =\t");
		a.x = in.nextDouble();
		a.y = in.nextDouble();
		System.out.println("Circumference = "+a.circumference());
		System.out.println("Area = "+a.area());
		a.inside();
		in.close();
	}
}