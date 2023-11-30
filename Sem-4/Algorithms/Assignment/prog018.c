/***************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement bubble sort. Use dynamic memory allocation and subfunction.
Program No. : 018
Date : 04.06.2022
****************************************************************************************************/

#include <stdio.h>
#include "array.h"

void sort(int p,int *A);
void swap(int *a,int *b);

void main()
{
    int n,*ar,x;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = memalloc(n);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nUnsorted array :\n");
    display(n,ar);
    sort(n,ar);
    printf("\nSorted array :\n");
    display(n,ar);
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
