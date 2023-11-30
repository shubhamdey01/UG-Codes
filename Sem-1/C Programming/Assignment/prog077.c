/********************************************
Name : Shubham Dey
Program : Subtract one matrix from the other.
Program No. : 077
Date : 22/02/2021
*********************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
void subtract(int r,int c,int **P,int **Q,int **R);

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
    printf("\nEnter elements for matrix X (MINUEND).\n");
    input(r1,c1,X);
    printf("\nEnter elements for matrix Y (SUBTRAHEND).\n");
    input(r2,c2,Y);

    printf("\nMatrix X (MINUEND) =\n");
    display(r1,c1,X);
    printf("\nMatrix Y (SUBTRAHEND) =\n");
    display(r2,c2,Y);
    subtract(r1,c1,X,Y,Z);
    printf("\nMatrix Z (DIFFERENCE) =\n");
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
        {
            printf("Enter the value of element[%d][%d] =\t",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
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