// Student : Total Marks = Exam Marks + Sports Grace Marks

package hw;

class Student
{
	private String name = " ";
	private int roll = 0;
	
	public void getData(String name,int roll)
	{
		this.name = name;
		this.roll = roll;
	}
	
	protected void showData()
	{
		System.out.println("Name :\t" + name);
		System.out.println("Roll No. :\t" + roll);
	}
}

class Exam extends Student
{
	protected float Exam_Marks;
	
	public void getMarks(float sub1,float sub2)
	{
		Exam_Marks = sub1 + sub2;
	}
	
	protected void showMarks()
	{
		System.out.println("Exam Marks =\t" + Exam_Marks);
	}
}

interface Sports
{
	float Sports_Grace_Marks = 6.0F;
	void showSMarks();
}

class Results extends Exam implements Sports
{
	private float total;
	
	public void showSMarks()
	{
		System.out.println("Sports Grace Marks =\t" + Sports_Grace_Marks);
	}
	
	public void display()
	{
		total = Exam_Marks + Sports_Grace_Marks;
		showData();
		System.out.println();
		showMarks();
		showSMarks();
		System.out.println("Total Marks =\t" + total);
	}
}

public class Prog007
{
	public static void main(String[] args)
	{
		Results student = new Results();
		student.getData("Sonu",123);
		student.getMarks(27.5F,33.0F);
		student.display();
	}
}