// Max Heap

#include <stdio.h>
#include <stdlib.h>

int *memalloc(int n);
void input(int *A, int n);
void display(int *A, int n);
void maxHeap(int *A, int n, int k);
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
	input(ar,n);

	printf("Max Heap :\n");
	maxHeap(ar,n,k);
	display(ar,n);

	return 0;
}

int *memalloc(int n)
{
	int *A = (int*)calloc(n,sizeof(int));
	return A;
}

void input(int *A, int n)
{
	for(int i=0; i<n; i++)
		scanf("%d",A+i);
}

void display(int *A, int n)
{
	for(int i=0; i<n; i++)
		printf("%d  ",*(A+i));
	printf("\n");
}

void maxHeap(int *A, int n, int k)
{
	for(int i=(n-1)/k; i>=0; i--)
		heapify(A,i,n,k);
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