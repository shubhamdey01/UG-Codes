package test;

import java.util.Scanner;

public class Print_Int {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		System.out.print("Enter an integer :\t");
		int i = reader.nextInt();
		System.out.print("Enter an float :\t");
		float f = reader.nextFloat();
		System.out.println("\nYou entered : " + i + " & " + f);
		reader.close();
	}
}