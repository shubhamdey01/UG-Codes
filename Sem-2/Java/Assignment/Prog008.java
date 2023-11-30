// Complex matrix multiplication

package hw;

import java.util.Scanner;

class ComplexNum
{
	protected Scanner in = new Scanner(System.in);
	private float re,im;
	
	protected ComplexNum()
	{
		re = 0.0F;
		im = 0.0F;
	}
	protected ComplexNum getData()
	{
		ComplexNum n = new ComplexNum();
		n.re = in.nextFloat();
		n.im = in.nextFloat();
		return n;
	}
	protected void display() {
		if(im<0) {
			System.out.print(re+" - i "+ -im);
		}
		else {
			System.out.print(re+" + i "+im);
		}
	}
	protected ComplexNum add(ComplexNum x)
	{
		ComplexNum r = new ComplexNum();
		r.re = re + x.re;
		r.im = im + x.im;
		return r;
	}
	protected ComplexNum multiply(ComplexNum x)
	{
		ComplexNum r = new ComplexNum();
		r.re = re*x.re - im*x.im;
		r.im = re*x.im + x.re*im;
		return r;
	}
}

class Matrix extends ComplexNum
{
	private int row,col;
	private ComplexNum mat[][];
	public Matrix()
	{
		row = in.nextInt();
		col = in.nextInt();
		mat = new ComplexNum[row][col];
	}
	private Matrix(int row,int col)
	{
		this.row = row;
		this.col = col;
		mat = new ComplexNum[row][col];
	}
	public void input()
	{
		System.out.println("Enter real and imaginary parts for :");
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				System.out.println("element["+i+"]["+j+"] =");
				mat[i][j] = getData();
			}
	}
	public void display()
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				System.out.print("\t");
				mat[i][j].display();
				System.out.print("\t");
			}
			System.out.println();
		}
	}
	public Matrix multiply(Matrix x)
	{
		if(col != x.row)
		{
			System.out.println("\nCan't multiply these matrices.");
			System.exit(1);
		}
		Matrix res = new Matrix(row,x.col);
		for(int i=0;i<row;i++)
			for(int j=0;j<x.col;j++)
			{
				res.mat[i][j] = new ComplexNum();
				for(int k=0;k<col;k++)
					res.mat[i][j] = res.mat[i][j].add(mat[i][k].multiply(x.mat[k][j]));
			}
		
		return res;
	}
}

public class Prog008
{
	public static void main(String[] args)
	{
		System.out.println("Enter dimensions of the matrix A :");
		Matrix A = new Matrix();
		System.out.println("\nEnter elements for matrix A :");
		A.input();
		System.out.println("\nEnter dimensions of the matrix B :");
		Matrix B = new Matrix();
		System.out.println("\nEnter elements for matrix B :");
		B.input();
		System.out.println("\nMatrix A =");
		A.display();
		System.out.println("\nMatrix B =");
		B.display();
		Matrix C = A.multiply(B);
		System.out.println("\nProduct matrix C =");
		C.display();
	}
}