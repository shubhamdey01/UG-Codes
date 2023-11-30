/******************************************************
Name : Shubham Dey
Program : Write a C program to implement Counting sort.
Program No. : 032
Date : 01.07.2022
*******************************************************/

#include <stdio.h>
#include "array.h"

int getMax(int *A, int n);
int getMin(int *A, int n);
void countSort(int *A, int n);

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
	countSort(ar,n);
	printf("\nSorted array :\n");
	display(n,ar);
}

int getMax(int *A, int n)
{  
	int max = A[0];  
	for(int i = 1; i<n; i++)
		if(A[i] > max)  
			max = A[i];
	return max;
}

int getMin(int *A, int n)
{  
	int min = A[0];  
	for(int i = 1; i<n; i++)
		if(A[i] < min)  
			min = A[i]; 
	return min;
}
  
void countSort(int *A, int n)
{  
	int max = getMax(A, n);
	int min = getMin(A, n);
	int range = max - min + 1; 
	int *output = memalloc(n);
	int *count = memalloc(range);  

	for (int i = 0; i < n; i++)
		count[A[i] - min]++; 

	for(int i = 1; i<range; i++)   
		count[i] += count[i-1];

	for (int i = n - 1; i >= 0; i--)
	{  
		output[count[A[i] - min] - 1] = A[i];  
		count[A[i] - min]--;
	}  

	for(int i = 0; i<n; i++)
		A[i] = output[i]; 
}
