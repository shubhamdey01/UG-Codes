/*********************************
Name : Shubham Dey
Program : WAP to add two matrices
Program No. : 001
Date : 14.03.2022
*********************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
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

    X = mem_alloc(r1,c1);
    Y = mem_alloc(r2,c2);
    Z = mem_alloc(r1,c2);
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

int **mem_alloc(int r,int c)
{
    int i,**A;
    A = (int**)calloc(r,sizeof(int*));
    for(i=0;i<r;i++)
        A[i] = (int*)calloc(c,sizeof(int));
    return A;
}
void input(int r,int c,int **A)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&A[i][j]);
}
void display(int r,int c,int **A)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}
void add(int r,int c,int **P,int **Q,int **R)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            R[i][j] = P[i][j] + Q[i][j];
}