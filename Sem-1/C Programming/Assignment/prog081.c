/********************************************************************
Name : Shubham Dey
Program : Print the sum of all diagonal elements of a square matrix.
Program No. : 081
Date : 25/02/2021
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r);
void input(int r,int **A);
void display(int r,int **A);
int sum_D(int r,int **P);

void main()
{
    int r,c,**X;

    do
    {
        printf("Enter no. of rows and columns for matrix X :\n");
        scanf("%d %d",&r,&c);
    }while(r != c);

    X = mem_alloc(r);
    printf("\nEnter elements for matrix X.\n");
    input(r,X);

    printf("\nGiven Matrix X =\n");
    display(r,X);
    printf("\nSum of all diagonal elements = %d\n",sum_D(r,X));
}

int **mem_alloc(int r)
{
    int i,**A;
    A = (int**)calloc(r,sizeof(int*));
    for(i=0;i<r;i++)
        A[i] = (int*)calloc(r,sizeof(int));
    return A;
}
void input(int r,int **A)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
        {
            printf("Enter the value of element[%d][%d] =\t",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
}
void display(int r,int **A)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<r;j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
}
int sum_D(int r,int **P)
{
    int i,j,sum=0;
    for(i=0;i<r;i++)
        for(j=0;j<r;j++)
            if(i==j || i+j==r-1)
                sum += P[i][j];
    return sum;
}