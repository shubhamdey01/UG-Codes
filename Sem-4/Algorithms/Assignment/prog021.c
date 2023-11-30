/**************************************************************************************************
Name : Shubham Dey
Program : Write a C program to implement merge sort. Use dynamic memory allocation and subfunction.
Program No. : 021
Date : 05.06.2022
***************************************************************************************************/

#include <stdio.h>
#include "array.h"

void mergeSort(int low, int up, int *A);
void merge(int low, int mid, int up, int *A);

int main()
{
	int *A,n;

	printf("How many numbers ? :\t");
	scanf("%d",&n);

	A = memalloc(n);

	printf("Enter %d elements :\n",n);
	input(n,A);
	printf("\nUnsorted Array :\n");
	display(n,A);

	mergeSort(0,n-1,A);

	printf("\nSorted Array :\n");
	display(n,A);

	return 0;
}

void mergeSort(int low, int up, int *A)
{
	if(low < up)
	{
		int mid = low + (up - low)/2;
		mergeSort(low, mid, A);
		mergeSort(mid+1, up, A);
		merge(low, mid, up, A);
	}
}

void merge(int low, int mid, int up, int *A)
{
	int i,j,k,n1,n2,*X,*Y;
	
	n1 = mid - low +1;
	n2 = up - mid;
	X = memalloc(n1);
	Y = memalloc(n2);

	for(i=0; i<n1; i++)
		X[i] = A[low+i];
	for(i=0; i<n2; i++)
		Y[i] = A[mid+1+i];

	i = j = 0;
	k = low;

	while(i<n1 && j<n2)
	{
		if(X[i]<=Y[j])
			A[k++] = X[i++];
		else
			A[k++] = Y[j++];
	}

	while(i<n1)
		A[k++] = X[i++];
	
	while(j<n2)
		A[k++] = Y[j++];
}
