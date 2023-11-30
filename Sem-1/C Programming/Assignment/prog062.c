/***************************************************
Name : Shubham Dey
Program : Insert an element in the middle of a list.
Program No. : 062
Date : 18/02/2021
****************************************************/

#include<stdio.h>
#include<stdlib.h>

int *mem_alloc(int p);
void input(int n,int *A);
void display(int n,int *A);
void insert(int p,int a,int *A);

void main()
{
    int n,*ar,x;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = mem_alloc(n+1);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nBEFORE :\n");
    display(n,ar);
    printf("Enter the number to be inserted :\t");
    scanf("%d",&x);
    insert(n,x,ar);
    printf("\nAFTER inserting %d in the middle :\n",x);
    display(n+1,ar);
}

int *mem_alloc(int p)
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
void insert(int p,int a,int *A)
{
    int i;
    for(i=p;i>p/2;i--)
        A[i]=A[i-1];
    A[i]=a;
}