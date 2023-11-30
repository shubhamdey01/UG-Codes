/*************************************
Name : Shubham Dey
Program : Implement bubble sort
Program No. : 006
Date : 14.03.2022
*************************************/

#include<stdio.h>
#include<stdlib.h>

int *mem_alloc(int p);
void input(int n,int *A);
void display(int n,int *A);
void sort(int p,int *A);
void swap(int *a,int *b);

void main()
{
    int n,*ar,x;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = mem_alloc(n);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nUnsorted array :\n");
    display(n,ar);
    sort(n,ar);
    printf("\nSorted array :\n");
    display(n,ar);
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
void sort(int p,int *A)
{
    int i,j,temp;
    for(i=0;i<p-1;i++)
        for(j=i+1;j<p;j++)
            if(A[i]>A[j])
                swap(&A[i],&A[j]);
}
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}