/********************************************************************
Name : Shubham Dey
Program : Print the sum of all elements of each column of a matrix.
Program No. : 081
Date : 25/02/2021
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
void sum_C(int r,int c,int **P);
void display_sum(int c,int *S);

void main()
{
    int r,c,**X;

    printf("Enter no. of rows and columns for matrix X :\n");
    scanf("%d %d",&r,&c);

    X = mem_alloc(r,c);
    printf("\nEnter elements for matrix X.\n");
    input(r,c,X);

    printf("\nGiven Matrix X =\n");
    display(r,c,X);
    printf("\nSum of all elements of each column :\n");
    sum_C(r,c,X);
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
void sum_C(int r,int c,int **P)
{
    int i,j;
    int *sum = (int*)calloc(c,sizeof(int));

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[j] += P[i][j];
    display_sum(c,sum);
}
void display_sum(int c,int *S)
{
    int i;
    for(i=0;i<c;i++)
        printf("Sum of column %d = %d\n",i+1,S[i]);
}