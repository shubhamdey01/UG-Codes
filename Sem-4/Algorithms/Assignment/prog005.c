/************************************************************************************
Name : Shubham Dey
Program : Write a C program to subtract one matrix from another by recursive approach.
Program No. : 005
Date : 04.05.2022
*************************************************************************************/

#include <stdio.h>
#include "matrix.h"

void subtract(int rs, int re, int cs, int ce, int **A, int **B, int **C);

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

	printf("Enter elements for matrix x (MINUEND):\n");
	input(r1,c1,x);
	printf("Enter elements for matrix y (SUBTRAHEND):\n");
	input(r1,c1,y);

	printf("Matrix X :\n");
	display(r1,c1,x);
	printf("Matrix Y :\n");
	display(r1,c1,y);

	subtract(0,r1,0,c1,x,y,z);


	printf("Resultant matrix Z :\n");
	display(r1,c1,z);


	return 0;
}

void subtract(int rs, int re, int cs, int ce, int **A, int **B, int **C)
{
	if(re-rs == 1)
		C[rs][cs] = A[rs][cs] - B[rs][cs];
	else
	{
		subtract(rs,(rs+re)/2,cs,(cs+ce)/2,A,B,C);
		subtract(rs,(rs+re)/2,(cs+ce)/2,ce,A,B,C);
		subtract((rs+re)/2,re,cs,(cs+ce)/2,A,B,C);
		subtract((rs+re)/2,re,(cs+ce)/2,ce,A,B,C);
	}
}