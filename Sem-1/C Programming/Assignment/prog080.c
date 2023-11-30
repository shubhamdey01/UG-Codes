/***************************************************
Name : Shubham Dey
Program : Check whether a matrix is symmetric or not.
Program No. : 080
Date : 22/02/2021
****************************************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int r,int c);
void input(int r,int c,int **A);
void display(int r,int c,int **A);
int symmetric(int r,int c,int **P);

void main()
{
    int r,c,**X;
    
    do
    {
        printf("Enter no. of rows and columns for matrix X :\n");
        scanf("%d %d",&r,&c);
    }while(r!=c);

    X = mem_alloc(r,c);
    printf("\nEnter elements for matrix X.\n");
    input(r,c,X);

    printf("\nGiven Matrix X =\n");
    display(r,c,X);
    if(symmetric(r,c,X))
        printf("\nGiven Matrix X is a symmetric matrix.\n");
    else
        printf("\nGiven Matrix X is not a symmetric matrix.\n");
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
int symmetric(int r,int c,int **P)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(P[j][i] != P[i][j])
                break;
    if(i==r && j==c)
        return 1;
    return 0;
}