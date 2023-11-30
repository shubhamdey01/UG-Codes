/**********************************************************************
Name : Shubham Dey
Program : Write a C program to sort a list of numbers by using quick sort.
Program No. : 031
Date : 01.07.2022
***********************************************************************/

#include <stdio.h>
#include "array.h"

void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void swap(int *a, int *b);

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
	quickSort(ar,0,n-1);
	printf("\nSorted array :\n");
	display(n,ar);
}

void quickSort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
