/******************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement selection sort. Use dynamic memory allocation and subfunction.
Program No. : 020
Date : 05.06.2022
*******************************************************************************************************/

#include <stdio.h>
#include "array.h"

void sort(int *ar, int n);
void swap(int *x, int *y);

int main()
{
	int n,*ar,x;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = memalloc(n);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nUnsorted array :\n");
    display(n,ar);
    sort(ar,n);
    printf("\nSorted array :\n");
    display(n,ar);
}

void sort(int *ar, int n)
{
	int i, j, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		if (ar[j] < ar[min])
			min = j;

		swap(&ar[min], &ar[i]);
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
