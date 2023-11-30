/**************************************************************************
Name : Shubham Dey
Program : Write a C program to multiply two matrices by iterative approach.
Program No. : 003
Date : 03.05.2022
***************************************************************************/

#include <stdio.h>
#include "matrix.h"

void multiply(int a,int b,int c,int **A,int **B,int **C);

void main()
{
    int r1,c1,r2,c2,**X,**Y,**Z;

    do
    {
        printf("No. of rows and columns for matrix X :\n");
        scanf("%d %d",&r1,&c1);
        printf("No. of rows and columns for matrix Y :\n");
        scanf("%d %d",&r2,&c2);
    } while (c1!=r2);

    X = memalloc(r1,c1);
    Y = memalloc(r2,c2);
    Z = memalloc(r1,c2);
    printf("\nEnter elements for matrix X.\n");
    input(r1,c1,X);
    printf("\nEnter elements for matrix Y.\n");
    input(r2,c2,Y);

    printf("\nMatrix X =\n");
    display(r1,c1,X);
    printf("\nMatrix Y =\n");
    display(r2,c2,Y);
    multiply(r1,c1,c2,X,Y,Z);
    printf("\nResultant Matrix Z =\n");
    display(r1,c2,Z);
}

void multiply(int a,int b,int c,int **A,int **B,int **C)
{
    int i,j,k;
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                C[i][k] += A[i][j]*B[j][k];
}
