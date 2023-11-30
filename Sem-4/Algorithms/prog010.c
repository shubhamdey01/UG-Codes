/********************************************
Name : Shubham Dey
Program : WAP to add two matrices recursively
Program No. : 010
Date : 28.03.2022
********************************************/

#include <stdio.h>
#include <stdlib.h>

int **memalloc(int m, int n);
void input(int m, int n, int **A);
void display(int m, int n, int **A);
void add(int rs, int re, int cs, int ce, int **A, int **B, int **C);

int main()
{
	int r1,c1,r2,c2,**x,**y,**z;

	do {
		printf("Enter the no. of rows and columns for X :\n");
		scanf("%d %d",&r1,&c1);
		printf("Enter the no. of rows and columns for Y :\n");
		scanf("%d %d",&r2,&c2);
	} while(r1!=r2 && c1!=c2);

	x = memalloc(r1,c1);
	y = memalloc(r1,c1);
	z = memalloc(r1,c1);

	printf("Enter elements for matrix x :\n");
	input(r1,c1,x);
	printf("Enter elements for matrix y :\n");
	input(r1,c1,y);

	printf("Matrix X :\n");
	display(r1,c1,x);
	printf("Matrix Y :\n");
	display(r1,c1,y);

	add(0,r1,0,c1,x,y,z);


	printf("Resultant matrix  Z :\n");
	display(r1,c1,z);


	return 0;
}

int **memalloc(int m, int n)
{
	int **A = (int**)calloc(m,sizeof(int*));
	for(int i=0; i<m; i++)
		A[i] = (int*)calloc(n,sizeof(int));
	return A;
}

void input(int m, int n, int **A)
{
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d",&A[i][j]);
}

void display(int m, int n, int **A)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%5d",A[i][j]);
		printf("\n");
	}
}

void add(int rs, int re, int cs, int ce, int **A, int **B, int **C)
{
	if(re-rs == 1)
		C[rs][cs] = A[rs][cs] + B[rs][cs];
	else
	{
		add(rs,(rs+re)/2,cs,(cs+ce)/2,A,B,C);
		add(rs,(rs+re)/2,(cs+ce)/2,ce,A,B,C);
		add((rs+re)/2,re,cs,(cs+ce)/2,A,B,C);
		add((rs+re)/2,re,(cs+ce)/2,ce,A,B,C);
	}
}