/******************************************************
Name : Shubham Dey
Program : Two dimensional dynamic array implementation
******************************************************/

#include <stdio.h>
#include <stdlib.h>

int** memalloc(int r,int c);
void input(int** a,int r,int c);
void display(int** a,int r,int c);

int main()
{
	int r,c;
	printf("No. of rows & coulmns :\n");
	scanf("%d %d",&r,&c);
	int** ar = memalloc(r,c);
	printf("Enter items for %dx%d matrix :\n",r,c);
	input(ar,r,c);
	printf("\nItems of the array :\n");
	display(ar,r,c);
}

int** memalloc(int r,int c)
{
	int** x = (int**)calloc(r,sizeof(int*));
	for(int i=0;i<r;i++)
		x[i] = (int*)calloc(c,sizeof(int));
	return x;
}
void input(int** a,int r,int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);
}
void display(int** a,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d\t",*(*(a+i)+j));
		printf("\n");
	}
}
