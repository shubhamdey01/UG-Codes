/********************************************************************
Name : Shubham Dey
Program : Print the sum of all elements of each row of a matrix.
Program No. : 081
Date : 25/02/2021
*********************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
void sum_R(int r,int c,int **P);
void display_sum(int r,int *S);

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
    printf("\nSum of all elements of each row :\n");
    sum_R(r,c,X);
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
void sum_R(int r,int c,int **P)
{
    int i,j;
    int *sum = (int*)calloc(r,sizeof(int));

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            sum[i] += P[i][j];
    display_sum(r,sum);
}
void display_sum(int r,int *S)
{
    int i;
    for(i=0;i<r;i++)
        printf("Sum of row %d = %d\n",i+1,S[i]);
}