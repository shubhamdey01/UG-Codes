// Header file for Array utilities

#include<stdio.h>
#include<stdlib.h>

int *memalloc(int p)
{
    int *A;
    A = (int*)calloc(p,sizeof(int));
    return A;
}

void input(int p,int *A)
{
    int i;
    for(i=0;i<p;i++)
        scanf("%d",&A[i]);
}

void display(int p,int *A)
{
    int i;
    for(i=0;i<p;i++)
        printf("%d  ",A[i]);
    printf("\n");
}