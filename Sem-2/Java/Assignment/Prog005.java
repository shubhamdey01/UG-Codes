// Complex number

package hw;

import java.util.Scanner;

class Imaginary {
	protected float im;
	Scanner in = new Scanner(System.in);
	
	public void get_i() {
		System.out.print("Enter imaginary number :  ");
		im = in.nextFloat();
	}
	public void display() {
		System.out.println(im+" i\n");
	}
}
class Complex extends Imaginary {
	protected float re;
	public void get_r() {
		System.out.print("Enter real number :  ");
		re = in.nextFloat();
	}
	public Complex mul(Complex x) {
		Complex r = new Complex();
		r.re = re*x.re - im*x.im;
		r.im = re*x.im + x.re*im;
		return r;
	}
	public void display() {
		if(im<0) {
			System.out.println(re+" - i "+ -im+"\n");
		}
		else {
			System.out.println(re+" + i "+im+"\n");
		}
	}
}

public class Prog005 {

	public static void main(String[] args) {
		Imaginary x = new Imaginary();
		Complex a = new Complex();
		Complex b = new Complex();
		Complex c = new Complex();
		x.get_i();
		x.display();
		a.get_r();
		a.get_i();
		a.display();
		b.get_r();
		b.get_i();
		b.display();
		c = a.mul(b);
		System.out.print("Product =\t");
		c.display();
	}
}