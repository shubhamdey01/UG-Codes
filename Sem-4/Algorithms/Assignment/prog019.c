/******************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement insertion sort. Use dynamic memory allocation and subfunction.
Program No. : 019
Date : 04.06.2022
*******************************************************************************************************/

#include <stdio.h>
#include "array.h"

void sort(int *arr, int n);

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

void sort(int *arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
