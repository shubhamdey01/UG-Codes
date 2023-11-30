package test;

import java.util.Scanner;

/**
 * This class creates Stack using Linked List
 * @author Shubham
 */

public class StackLL
{
	/**
	 * Creates a linked list Node
	 */
	private class Node
	{
		int data;
		Node next;
	}

	Node top;
	Scanner in = new Scanner(System.in);

	/**
	 * sets top to null
	 */
	private StackLL()
	{
		this.top = null;
	}
	/**
	 * Utility function to add an element n in the stack
	 * @param n insert n in the beginning
	 * @return returns nothing
	 */
	private void push(int n)
	{
		Node temp = new Node();
		temp.data = n;
		temp.next = top;
		top = temp;
	}
	/**
	 * Utility function to check if the stack is empty or not
	 * @return true if top is not null, otherwise false
	 */
	private boolean isEmpty()
	{
		return top == null;
	}
	/**
	 * Utility function to return top element of a stack
	 * @return top element if top is not null, otherwise -1
	 */
	private int peek()
	{
		return top.data;
	}
	/**
	 * Utility function to remove the top element and return it
	 * @return top element of the stack
	 */
	private int pop()
	{
		int item = top.data;
		top = top.next;
		return item;
	}
	/**
	 * Utility function to display the current stack
	 */
	private void display()
	{
		if (isEmpty())
			System.out.println("\nUnderflow!!  Stack is empty.");
		else
		{
			Node temp = top;
			System.out.println(temp.data + " <- top");
			temp = temp.next;
			while(temp != null)
			{
				System.out.println(temp.data);
				temp = temp.next;
			}
		}
	}
	/**
	 * Provides menu to the user to perform stack operations
	 */
	public void menu()
	{
		int ch;
		do
		{
			System.out.println("\nStack Operations");
			System.out.println("--------------------");
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
				if(!isEmpty())
					System.out.println("\nPoped element is " + pop());
				else
					System.out.println("\nUnderflow!!  Stack is empty.");
				break;
			case 3:
				if(!isEmpty())
					System.out.println("\nTopmost element of the stack is " + peek());
				else
					System.out.println("\nUnderflow!!  Stack is empty.");
				break;
			case 4:
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
	/**
	 * This is the driver code of the program
	 * @param args not used
	 */
	public static void main(String[] args)
	{
		StackLL stk = new StackLL();
		stk.menu();
	}
}