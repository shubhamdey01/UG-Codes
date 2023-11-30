/*****************************************************
Name : Shubham Dey
Program : One dimensional static array implementation
*****************************************************/

#include <stdio.h>

#define I 5

void input(int* a);
void display(int* a);

int main()
{
	int ar[I];
	printf("Enter %d items :\n",I);
	input(ar);
	printf("\nItems of the array :\n");
	display(ar);
}

void input(int* a)
{
	for(int i=0;i<I;i++)
		scanf("%d",a+i);
}
void display(int* a)
{
	for(int i=0;i<I;i++)
		printf("%d\t",*a+i);
	printf("\n");
}