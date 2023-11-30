/******************************************************
Name : Shubham Dey
Program : Write a C program to implement Bucket sort.
Program No. : 034
Date : 01.07.2022
*******************************************************/

#include <stdio.h>
#include "array.h"

int getMax(int *A, int n);
void bucketSort(int *A, int n);

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
	bucketSort(ar,n);
	printf("\nSorted array :\n");
	display(n,ar);
}

int getMax(int *A, int n) 
{  
	int max = A[0];  
	for (int i = 1; i < n; i++)  
		if (A[i] > max)  
			max = A[i];  
	return max;  
}

void bucketSort(int *A, int n)
{  
	int max = getMax(A, n);
	int *bucket = memalloc(max); 
	 
	for (int i = 0; i < n; i++)
		bucket[A[i]]++; 
	for (int i = 0, j = 0; i <= max; i++)  
	{  
		while (bucket[i] > 0)  
		{  
			A[j++] = i;  
			bucket[i]--;  
		}  
	}  
}
