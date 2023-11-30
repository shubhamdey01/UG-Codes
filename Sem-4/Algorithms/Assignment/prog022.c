/**************************************************************************
Name : Shubham Dey
Program : Write a C program to create a binary maxheap or a binary minheap.
Program No. : 022
Date : 06.06.2022
***************************************************************************/

// Binary Max Heap

#include <stdio.h>
#include "array.h"

void maxHeap(int *A, int n);
void heapify(int *A, int i, int n);
int largest(int *A, int i, int n);
void swap(int *A, int i, int j);

int main()
{
	int n,*ar;

	printf("Enter no. of elements :\t");
	scanf("%d",&n);

	ar = memalloc(n);

	printf("Enter %d elements :\n",n);
	input(n,ar);

	printf("\nBinary Max Heap :\n");
	maxHeap(ar,n);
	display(n,ar);

	return 0;
}

void maxHeap(int *A, int n)
{
	for(int i=(n-1)/2; i>=0; i--)
		heapify(A,i,n);
}

void heapify(int *A, int i, int n)
{
	int large, max;
	if(2*i>=n)
		return;
	max = largest(A,i,n);

	if(max != i)
	{
		swap(A,i,max);
		heapify(A,max,n);
	}

}

int largest(int *A, int i, int n)
{
	int m = i;
	for(int j=1; j<=2; j++)
	{
		if(2*i+j < n && A[m] < A[2*i+j])
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
