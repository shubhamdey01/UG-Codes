/*************************************
Name : Shubham Dey
Program : Implement bubble sort recursively
Program No. : 009
Date : 19.03.2022
*************************************/

#include <stdio.h>
#include <stdlib.h>

int *mem_alloc(int n);
void input(int n,int *A);
void display(int n,int *A);
void sort(int *A, int n);
void swap(int *a,int *b);

int main()
{
	int n, *ar;
	printf("Enter no. of elements :\t");
	scanf("%d",&n);
	ar = mem_alloc(n);
	printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nUnsorted array :\n");
    display(n,ar);
    sort(ar,n);
    printf("\nSorted array :\n");
    display(n,ar);

	return 0;
}

int *mem_alloc(int n)
{
    int *A;
    A = (int*)calloc(n,sizeof(int));
    return A;
}
void input(int n,int *A)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
}
void display(int n,int *A)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",A[i]);
    printf("\n");
}
void sort(int *A, int n)
{
	if(n == 1)
		return;
	for(int i=0; i<n-1; i++)
		if(A[i] > A[i+1])
			swap(&A[i], &A[i+1]);
	sort(A,n-1);
}
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}