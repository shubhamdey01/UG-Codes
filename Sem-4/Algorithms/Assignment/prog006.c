/*************************************************************************
Name : Shubham Dey
Program : Write a C program to multiply two matrices by recursive approach.
Program No. : 006
Date : 04.05.2022
**************************************************************************/

#include <stdio.h>
#include "matrix.h"

void multiply(int ars, int are, int acs, int ace, int brs, int bre, int bcs, int bce, int **A, int **B, int **C);

int main()
{
	int r1,c1,r2,c2,**x,**y,**z;

	do {
		printf("Enter the no. of rows and columns for X :\n");
		scanf("%d %d",&r1,&c1);
		printf("Enter the no. of rows and columns for Y :\n");
		scanf("%d %d",&r2,&c2);
	} while(c1!=r2);

	x = memalloc(r1,c1);
	y = memalloc(r2,c2);
	z = memalloc(r1,c2);

	printf("Enter elements for matrix x :\n");
	input(r1,c1,x);
	printf("Enter elements for matrix y :\n");
	input(r2,c2,y);

	printf("Matrix X :\n");
	display(r1,c1,x);
	printf("Matrix Y :\n");
	display(r2,c2,y);

	multiply(0,r1,0,c1,0,r2,0,c2,x,y,z);


	printf("Resultant matrix Z :\n");
	display(r1,c2,z);


	return 0;
}

void multiply(int ars, int are, int acs, int ace, int brs, int bre, int bcs, int bce, int **A, int **B, int **C)
{
	if(are-ars == 1)
		C[ars][bcs] += A[ars][acs] * B[acs][bcs];
	else
	{
		multiply(ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2,A,B,C);
		multiply(ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2,A,B,C);
		multiply(ars,(ars+are)/2,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce,A,B,C);
		multiply(ars,(ars+are)/2,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce,A,B,C);
		multiply((ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,bcs,(bcs+bce)/2,A,B,C);
		multiply((ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,bcs,(bcs+bce)/2,A,B,C);
		multiply((ars+are)/2,are,acs,(acs+ace)/2,brs,(brs+bre)/2,(bcs+bce)/2,bce,A,B,C);
		multiply((ars+are)/2,are,(acs+ace)/2,ace,(brs+bre)/2,bre,(bcs+bce)/2,bce,A,B,C);
	}
}