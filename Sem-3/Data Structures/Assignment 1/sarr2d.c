/*****************************************************
Name : Shubham Dey
Program : Two dimensional static array implementation
*****************************************************/

#include <stdio.h>

#define I 3
#define J 3

void input(int a[I][J]);
void display(int a[I][J]);

int main()
{
	int ar[I][J];
	printf("Enter items for %dx%d matrix :\n",I,J);
	input(ar);
	printf("\nItems of the matrix :\n");
	display(ar);
}

void input(int a[I][J])
{
	for(int i=0;i<I;i++)
		for(int j=0;j<J;j++)
			scanf("%d",&a[i][j]);
}
void display(int a[I][J])
{
	for(int i=0;i<I;i++)
	{
		for(int j=0;j<J;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}