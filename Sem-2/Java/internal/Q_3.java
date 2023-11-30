package internal;

import java.util.Scanner;
import java.lang.Math;

class Rational
{
	Scanner in = new Scanner(System.in);
	private int p,q;
	
	public Rational()
	{
		do
		{
			System.out.println("Enter the numerator & denominator of the rational number :");
			p = in.nextInt();
			q = in.nextInt();
			if(q==0)
				System.out.println("Denominator can't be zero. Please enter again.\n");
		} while(q == 0);
		
		reduce();
	}
	
	private Rational(int p,int q)
	{
		this.p = p;
		this.q = q;
		
		reduce();
	}
	
	private int gcd (int num1, int num2)
	{
		while(num1 != num2)
		{
			if(num1 > num2)
				num1 = num1 - num2;
			else
				num2 = num2 - num1;
		}
		return num1;
	}
	
	private void reduce ()
	{
		if(q<0)
		{
			p *= -1;
			q *= -1;
		}
		if(p != 0)
		{
			int common = gcd(Math.abs(p), q);
			p = p / common;
			q = q / common;
		}
	}
	
	public Rational add(Rational x)
	{
		int de = q*x.q;
		int nu1 = p*x.q;
		int nu2 = x.p*q;
		
		Rational sum = new Rational(nu1+nu2, de);
		return sum;
	}
	
	public void display()
	{
		System.out.println(p + "/" + q);
	}
}

public class Q_3
{
	public static void main(String[] args)
	{
		Rational A = new Rational();
		Rational B = new Rational();
		System.out.print("\nRational number A =  ");
		A.display();
		System.out.print("Rational number B =  ");
		B.display();
		Rational C = A.add(B);
		System.out.print("\nSum C =  ");
		C.display();
	}
}