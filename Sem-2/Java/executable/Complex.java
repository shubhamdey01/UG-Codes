package executable;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Complex {
	protected double re,im;
	protected static Scanner sc = new Scanner(System.in);
	
	protected Complex() {
		re = 0;
		im = 0;
	}
	protected Complex(String s) {
		Pattern p1 = Pattern.compile("([-]?[0-9]+\\.?[0-9]{0,}?)([-|+]+[0-9]+\\.?[0-9]{0,}?)[i$]+");
		Pattern p2 = Pattern.compile("([-]?[0-9]+\\.?[0-9]{0,}?)$");
		Pattern p3 = Pattern.compile("([-]?[0-9]+\\.?[0-9]{0,}?)[i$]");
		
		Matcher m1 = p1.matcher(s);
		Matcher m2 = p2.matcher(s);
		Matcher m3 = p3.matcher(s);
		
		if(m1.find()) {
			re = Double.parseDouble(m1.group(1));
			im = Double.parseDouble(m1.group(2));
		}
		else if(m2.find()) {
			re = Double.parseDouble(m2.group(1));
			im = 0;
		}
		else if(m3.find()) {
			re = 0;
			im = Double.parseDouble(m3.group(1));
		}
	}
	protected void display() {
		if(im < 0)
			System.out.println(re+""+im+"i");
		else
			System.out.println(re+"+"+im+"i");
	}
	protected Complex add(Complex c) {
		Complex r = new Complex();
		r.re = re + c.re;
		r.im = im + c.im;
		return r;
	}
	protected Complex subtract(Complex c) {
		Complex r = new Complex();
		r.re = re - c.re;
		r.im = im - c.im;
		return r;
	}
	protected Complex multiply(Complex c) {
		Complex r = new Complex();
		r.re = re * c.re - im * c.im;
		r.im = re * c.im + im * c.re;
		return r;
	}
	protected Complex divide(Complex c) {
		Complex r = new Complex();
		r.re = (re * c.re + im * c.im)/(c.re*c.re + c.im*c.im);
		r.im = (im * c.re - re * c.im)/(c.re*c.re + c.im*c.im);
		return r;
	}
	public void run() {
		Complex a,b,c;
		System.out.print("Enter 1st Complex number :\t");
		a = new Complex(sc.next());
		System.out.print("Enter 2nd Complex number :\t");
		b = new Complex(sc.next());
		System.out.print("\nA = ");
		a.display();
		System.out.print("\nB = ");
		b.display();
		System.out.println();
		c = a.add(b);
		System.out.print("\nA + B = ");
		c.display();
		c = a.subtract(b);
		System.out.print("\nA - B = ");
		c.display();
		c = a.multiply(b);
		System.out.print("\nA * B = ");
		c.display();
		c = a.divide(b);
		System.out.print("\nA / B = ");
		c.display();
		System.out.println();
		
		for(int i=0; i<30; i++)
			System.out.print("=");
		System.out.println();
	}
}