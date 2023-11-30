/*************************************************
Name : Shubham Dey
Program : Implement 3 way merge sort
Program No. : 
Date : 06.04.2022
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int *memalloc(int n);
void input(int n, int *A);
void display(int n, int *A);
void mergeSort3(int low, int up, int *A);
void merge(int low, int mid1, int mid2, int up, int *A);

int main()
{
	int *A,n;

	printf("How many numbers ? :\t");
	scanf("%d",&n);

	A = memalloc(n);

	printf("Enter %d elements :\n",n);
	input(n,A);
	printf("Unsorted Array :\n");
	display(n,A);

	mergeSort3(0,n-1,A);

	printf("Sorted Array :\n");
	display(n,A);

	return 0;
}

int *memalloc(int n)
{
	int *A = (int*)calloc(n,sizeof(int));
	return A;
}

void input(int n, int *A)
{
	for(int i=0; i<n; i++)
		scanf("%d",&A[i]);
}

void display(int n, int *A)
{
	for(int i=0; i<n; i++)
		printf("%d\t",A[i]);
	printf("\n");
}

void mergeSort3(int low, int up, int *A)
{
	if(low < up)
	{
		int mid1 = low + (up - low)/3;
		int mid2 = low + 2*(up - low)/3 + 1;
		mergeSort3(low, mid1, A);
		mergeSort3(mid1+1, mid2, A);
		mergeSort3(mid2+1, up, A);
		merge(low, mid1, mid2, up, A);
	}
}

void merge(int low, int mid1, int mid2, int up, int *A)
{
	int i,j,k,m,n1,n2,n3,*X,*Y,*Z;
	
	n1 = mid1 - low +1;
	n2 = mid2 - mid1;
	n3 = up - mid2;
	X = memalloc(n1);
	Y = memalloc(n2);
	Z = memalloc(n3);

	for(i=0; i<n1; i++)
		X[i] = A[low+i];
	for(i=0; i<n2; i++)
		Y[i] = A[mid1+1+i];
	for(i=0; i<n3; i++)
		Z[i] = A[mid2+1+i];

	i = j = k = 0;
	m = low;

	while(i<n1 && j<n2 && k<n3)
	{
		if(X[i]<=Y[j])
		{
			if(X[i]<=Z[k])
				A[m++] = X[i++];
			else
				A[m++] = Z[k++];
		}
		else
		{
			if(Y[j]<=Z[k])
				A[m++] = Y[j++];
			else
				A[m++] = Z[k++];
		}
	}

	while(i<n1 && j<n2)
	{
		if(X[i]<=Y[j])
			A[m++] = X[i++];
		else
			A[m++] = Y[j++];
	}

	while(i<n1 && k<n3)
	{
		if(X[i]<=Z[k])
			A[m++] = X[i++];
		else
			A[m++] = Z[k++];
	}

	while(j<n2 && k<n3)
	{
		if(Y[j]<=Z[k])
			A[m++] = Y[j++];
		else
			A[m++] = Z[k++];
	}

	while(i<n1)
		A[m++] = X[i++];
	
	while(j<n2)
		A[m++] = Y[j++];

	while(k<n3)
		A[m++] = Z[k++];

}