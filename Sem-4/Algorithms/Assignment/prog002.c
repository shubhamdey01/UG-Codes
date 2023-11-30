/*************************************************************************************
Name : Shubham Dey
Program : Write a C program to subtract one matrix from another by iterative approach.
Program No. : 002
Date : 03.05.2022
**************************************************************************************/

#include <stdio.h>
#include "matrix.h"

void subtract(int r,int c,int **P,int **Q,int **R);

void main()
{
    int r1,c1,r2,c2,**A,**B,**C;

    do
    {
        printf("Enter no. of rows and columns for first matrix A :\n");
        scanf("%d %d",&r1,&c1);
        printf("Enter no. of rows and columns for second matrix B :\n");
        scanf("%d %d",&r2,&c2);
    }while (r1!=r2 || c1!=c2);

    A = memalloc(r1,c1);
    B = memalloc(r2,c2);
    C = memalloc(r1,c2);
    printf("\nEnter elements for matrix A (MINUEND).\n");
    input(r1,c1,A);
    printf("\nEnter elements for matrix B (SUBTRAHEND).\n");
    input(r2,c2,B);

    printf("\nMatrix A (MINUEND) =\n");
    display(r1,c1,A);
    printf("\nMatrix B (SUBTRAHEND) =\n");
    display(r2,c2,B);
    subtract(r1,c1,A,B,C);
    printf("\nMatrix C (DIFFERENCE) =\n");
    display(r1,c2,C);
}

void subtract(int r,int c,int **P,int **Q,int **R)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            R[i][j] = P[i][j] - Q[i][j];
}
