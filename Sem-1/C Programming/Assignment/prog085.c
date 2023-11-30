/*************************************************************************
Name : Shubham Dey
Program : Find the maximum and minimum number from all elements of a matrix.
Program : 085
Date : 25/02/2021
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
void max_min(int r,int c,int *a,int **A);

void main()
{
    int r,c,**X,M[2];

    printf("Enter the number of rows and columns for the matrix :\n");
    scanf("%d %d",&r,&c);

    X = mem_alloc(r,c);
    printf("\nEnter elements for the matrix.\n");
    input(r,c,X);
    printf("\nMatrix X :\n");
    display(r,c,X);
    max_min(r,c,M,X);
    printf("\nMaximun number = %d\nMinimun number = %d\n",M[0],M[1]);
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
            printf("Enter element[%d][%d] :\t",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
}
void display(int r,int c,int **A)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("\t%d",A[i][j]);
        printf("\n");
    }
}
void max_min(int r,int c,int *a,int **A)
{
    int i,j;

    a[0] = (A[0][0]>A[1][0]) ? A[0][0] : A[1][0];
    a[1] = (A[0][0]<A[1][0]) ? A[0][0] : A[1][0];
    for(i=0;i<r;i++)
        for(j=1;j<c;j++)
        {
            a[0] = (a[0]>A[i][j]) ? a[0] : A[i][j];
            a[1] = (a[1]<A[i][j]) ? a[1] : A[i][j];
        }
}