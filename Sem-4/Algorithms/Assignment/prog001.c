/*********************************************************************
Name : Shubham Dey
Program : Write a C program to add two matrices by iterative approach.
Program No. : 001
Date : 03.05.2022
**********************************************************************/

#include <stdio.h>
#include "matrix.h"

void add(int r,int c,int **P,int **Q,int **R);

void main()
{
    int r1,c1,r2,c2,**X,**Y,**Z;

    do
    {
        printf("Enter no. of rows and columns for first matrix X :\n");
        scanf("%d %d",&r1,&c1);
        printf("Enter no. of rows and columns for second matrix Y :\n");
        scanf("%d %d",&r2,&c2);
    }while (r1!=r2 || c1!=c2);

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
    add(r1,c1,X,Y,Z);
    printf("\nSUM Matrix Z =\n");
    display(r1,c2,Z);
}

void add(int r,int c,int **P,int **Q,int **R)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            R[i][j] = P[i][j] + Q[i][j];
}
