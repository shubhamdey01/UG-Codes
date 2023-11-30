/********************************************
Name : Shubham Dey
Program : Find the tranpose of a matrix.
Program No. : 079
Date : 22/02/2021
*********************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
void tranpose(int r,int c,int **P,int **R);

void main()
{
    int r,c,**X,**T;

    printf("Enter no. of rows and columns for matrix X :\n");
    scanf("%d %d",&r,&c);

    X = mem_alloc(r,c);
    T = mem_alloc(c,r);
    printf("\nEnter elements for matrix X.\n");
    input(r,c,X);

    printf("\nGiven Matrix X =\n");
    display(r,c,X);
    tranpose(r,c,X,T);
    printf("\nTranspose Matrix T  =\n");
    display(c,r,T);
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
void tranpose(int r,int c,int **P,int **R)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            R[j][i] = P[i][j];
}