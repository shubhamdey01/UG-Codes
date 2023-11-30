/******************************************************
Name : Shubham Dey
Program : One dimensional dynamic array implementation
******************************************************/

#include <stdio.h>
#include <stdlib.h>

void input(int* a,int n);
void display(int* a,int n);
int* memalloc(int n);

int main()
{
	int n;
	printf("How many items :");
	scanf("%d",&n);
	int* ar = memalloc(n);
	printf("Enter %d items :\n",n);
	input(ar,n);
	printf("\nItems of the array :\n");
	display(ar,n);
}

int* memalloc(int n)
{
	int* x = (int*)calloc(n,sizeof(int));
	return x;
}
void input(int* a,int n)
{
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
}
void display(int* a,int n)
{
	for(int i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
}