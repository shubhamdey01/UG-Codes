/**********************************************************
Name : Shubham Dey
Program : WAP to subtract a matrix B from another matrix A
Program No. : 002
Date : 14.03.2022
**********************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
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

    A = mem_alloc(r1,c1);
    B = mem_alloc(r2,c2);
    C = mem_alloc(r1,c2);
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
void subtract(int r,int c,int **P,int **Q,int **R)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            R[i][j] = P[i][j] - Q[i][j];
}