/******************************************************************************************************
Name : Shubham Dey
Program : Write a C program to sort (ascending or descending) a list of elements through a binary heap.
Program No. : 024
Date : 07.06.2022
*******************************************************************************************************/

// Binary Heap Sort - Decending

#include <stdio.h>
#include "array.h"

void heapSort(int *A, int n);
void heapify(int *A, int i, int n);
int smallest(int *A, int i, int n);
void swap(int *A, int i, int j);

int main()
{
	int n,*ar;

	printf("Enter no. of elements :\t");
	scanf("%d",&n);

	ar = memalloc(n);

	printf("Enter %d elements :\n",n);
	input(n,ar);

	printf("\nUnsorted List :\n");
	display(n,ar);

	heapSort(ar,n);
	printf("\nSorted List :\n");
	display(n,ar);

	return 0;
}

void heapSort(int *A, int n)
{
	int i;
	for(i=(n-1)/2; i>=0; i--)
		heapify(A,i,n);
	
	for(i=n-1; i>0; i--)
	{
		swap(A,0,i);
		heapify(A,0,i);
	}
}

void heapify(int *A, int i, int n)
{
	if(2*i>=n)
		return;
	int min = smallest(A,i,n);

	if(min != i)
	{
		swap(A,i,min);
		heapify(A,min,n);
	}

}

int smallest(int *A, int i, int n)
{
	int m = i;
	for(int j=1; j<=2; j++)
	{
		if(2*i+j < n && A[m] > A[2*i+j])
			m = 2*i+j;
	}
	return m;
}

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
