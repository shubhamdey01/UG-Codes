// Stack implementation : using array

package hw;

import java.util.Scanner;

class Stack
{
	Scanner in = new Scanner(System.in);
	private int top;
	private static final int MAX = 20;
	private int stk[];
	
	Stack()
	{
		top = -1;
		stk = new int[MAX];
	}
	private boolean isEmpty()
	{
		if(top < 0)
			return true;
		else
			return false;
	}
	private void push(int n)
	{
		top++;
		stk[top] = n;
	}
	private void pop()
	{
		System.out.println("\n"+top+" - "+stk[top]);
		stk[top] = 0;
		top--;
		if(isEmpty())
			System.out.println("Stack is empty.");
		else
			System.out.println("New Top =\t"+top);
	}
	private void peek()
	{
		System.out.println("\nTOP-> "+top+" - "+stk[top]);
	}
	private void display()
	{
		for(int i=top;i>=0;i--)
		{
			if(i==top)
				System.out.println("\nTOP-> "+i+" - "+stk[i]);
			else
				System.out.println("\t"+i+" - "+stk[i]);
		}
	}
	public void menu()
	{
		int ch;
		do
		{
			System.out.println("\n\tStack Operations");
			System.out.println("\t--------------------");
			System.out.println("1. Push\n2. Pop\n3. Peek\n4. Display current Stack\n5. Exit");
			System.out.print("\nEnter your choice :\t");
			ch = in.nextInt();
			
			switch(ch)
			{
				case 1:
					System.out.print("\nEnter a number :\t");
					push(in.nextInt());
					break;
				case 2:
					if(isEmpty())
						System.out.println("\nCan't pop. Stack is empty.");
					else
						pop();
					break;
				case 3:
					if(isEmpty())
						System.out.println("\nStack is empty.");
					else
						peek();
					break;
				case 4:
					if(isEmpty())
						System.out.println("\nStack is empty.");
					else
						display();
					break;
				case 5:
					System.out.println("\nThank You...");
					break;
				default:
					System.out.println("\n!! INVALID CHOICE !!");
			}
		} while(ch != 5);
	}
}

public class Prog006
{
	public static void main(String[] args)
	{
		Stack s = new Stack();
		s.menu();
	}
}