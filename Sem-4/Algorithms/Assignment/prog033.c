/******************************************************
Name : Shubham Dey
Program : Write a C program to implement Radix sort.
Program No. : 033
Date : 01.07.2022
*******************************************************/

#include <stdio.h>
#include "array.h"

int getMax(int *A, int n);
void countingSort(int *A, int n, int place);
void radixSort(int *A, int n);

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
	radixSort(ar,n);
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

void countingSort(int *A, int n, int place)
{
	int *output = memalloc(n);
	int *count = memalloc(10);

	for (int i = 0; i < n; i++)
		count[(A[i]/place)%10]++; 

	for(int i = 1; i<10; i++)   
		count[i] += count[i-1];

	for (int i = n - 1; i >= 0; i--)
	{  
		output[count[(A[i]/place)%10] - 1] = A[i];  
		count[(A[i]/place)%10]--;
	}  

	for(int i = 0; i<n; i++)
		A[i] = output[i]; 
}

void radixSort(int *A, int n)
{
	int max = getMax(A, n);
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(A, n, place);
}
