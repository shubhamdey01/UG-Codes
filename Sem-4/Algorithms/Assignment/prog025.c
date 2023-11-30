/******************************************************************************************************
Name : Shubham Dey
Program : Write a C program to sort (ascending or descending) a list of elements through a k-ary heap.
Program No. : 025
Date : 07.06.2022
*******************************************************************************************************/

// k-ary Heap Sort - Assending

#include <stdio.h>
#include "array.h"

void heapSort(int *A, int n, int k);
void heapify(int *A, int i, int n, int k);
int largest(int *A, int i, int n, int k);
void swap(int *A, int i, int j);

int main()
{
	int n,k,*ar;

	printf("Enter k (K-ary) :\t");
	scanf("%d",&k);

	printf("Enter no. of elements :\t");
	scanf("%d",&n);

	ar = memalloc(n);

	printf("Enter %d elements :\n",n);
	input(n,ar);

	printf("\nUnsorted List :\n");
	display(n,ar);

	heapSort(ar,n,k);
	printf("\nSorted List :\n");
	display(n,ar);

	return 0;
}

void heapSort(int *A, int n, int k)
{
	int i;
	for(i=(n-1)/k; i>=0; i--)
		heapify(A,i,n,k);
	
	for(i=n-1; i>0; i--)
	{
		swap(A,0,i);
		heapify(A,0,i,k);
	}
}

void heapify(int *A, int i, int n, int k)
{
	int large, max;
	if(k*i>=n)
		return;
	max = largest(A,i,n,k);

	if(max != i)
	{
		swap(A,i,max);
		heapify(A,max,n,k);
	}

}

int largest(int *A, int i, int n, int k)
{
	int m = i;
	for(int j=1; j<=k; j++)
	{
		if(k*i+j < n && A[m] < A[k*i+j])
			m = k*i+j;
	}
	return m;
}

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// OUTPUT
/*
Enter k (K-ary) :	3
Enter no. of elements :	10
Enter 10 elements :
5 4 1 9 -5 0 2 -3 6 0

Unsorted List :
5  4  1  9  -5  0  2  -3  6  0  

Sorted List :
-5  -3  0  0  1  2  4  5  6  9 
*/