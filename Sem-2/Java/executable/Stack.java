package executable;

import java.util.Scanner;

public class Stack {
	private class Node {
		int data;
		Node next;
	}

	private Node top;
	private Scanner in = new Scanner(System.in);

	public Stack() {
		this.top = null;
	}
	private void push(int n) {
		Node temp = new Node();
		temp.data = n;
		temp.next = top;
		top = temp;
	}
	private boolean isEmpty() {
		return top == null;
	}
	private int peek() {
		return top.data;
	}
	private int pop() {
		int item = top.data;
		top = top.next;
		return item;
	}
	private void display() {
		if (isEmpty())
			System.out.println("\nUnderflow!!  Stack is empty.");
		else {
			Node temp = top;
			System.out.println(temp.data + " <- top");
			temp = temp.next;
			while(temp != null) {
				System.out.println(temp.data);
				temp = temp.next;
			}
		}
	}
	public void menu() {
		int ch;
		do {
			System.out.println("\nStack Operations");
			System.out.println("--------------------");
			System.out.println("1. Push\n2. Pop\n3. Peek\n4. Display current Stack\n5. Exit");
			System.out.print("\nEnter your choice :\t");
			ch = in.nextInt();

			switch(ch) {
				case 1:
					System.out.print("\nEnter a number :\t");
					push(in.nextInt());
					break;
				case 2:
					if(!isEmpty())
						System.out.println("\nPopped element is " + pop());
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

		for(int i=0; i<30; i++)
			System.out.print("=");
		System.out.println();
	}
}