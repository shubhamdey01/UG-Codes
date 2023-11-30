/*************************************
Name : Shubham Dey
Program : WAP to multiply two matrices
Program No. : 003
Date : 14.03.2022
*************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
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
    multiply(r1,c1,c2,X,Y,Z);
    printf("\nResultant Matrix Z =\n");
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
void multiply(int a,int b,int c,int **A,int **B,int **C)
{
    int i,j,k;
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                C[i][k] += A[i][j]*B[j][k];
}