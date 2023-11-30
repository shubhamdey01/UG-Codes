package internal;

import java.util.Scanner;

class Matrix
{
	Scanner in = new Scanner(System.in);
	private int row,col,mat[][];
	Matrix()					// Default Constructor
	{
		row = in.nextInt();
		col = in.nextInt();
		mat = new int[row][col];
	}
	Matrix(int row,int col)		// Parameterized Constructor
	{
		this.row = row;
		this.col = col;
		mat = new int[row][col];
	}
	public void input()			// Data input for matrix
	{
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				mat[i][j] = in.nextInt();
	}
	public void display()		// Displays matrix in proper format
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				System.out.print("\t" + mat[i][j]);
			System.out.println();
		}
	}
	public Matrix multiply(Matrix x) 	// Multiplies two matrices
	{
		if(col != x.row)
		{
			System.out.println("\nCan't multiply these matrices.");
			System.exit(1);
		}
		Matrix res = new Matrix(row,x.col);
		for(int i=0;i<row;i++)
			for(int j=0;j<x.col;j++)
				for(int k=0;k<col;k++)
					res.mat[i][j] += mat[i][k] * x.mat[k][j];
		
		return res;
	}
}

public class Q_1
{
	public static void main(String[] args)
	{
		System.out.println("Enter dimentions of the matrix A :");
		Matrix A = new Matrix();
		System.out.println("Enter elements for matrix A :");
		A.input();
		System.out.println("Enter dimentions of the matrix B :");
		Matrix B = new Matrix();
		System.out.println("Enter elements for matrix B :");
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