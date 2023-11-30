package test;

import java.util.Scanner;

public class table {
	public static void main(String[] args) {
		System.out.print("Enter the number : ");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=1;i<=10;i++)
			System.out.println(n+" X "+i+" = "+n*i);
	}
}