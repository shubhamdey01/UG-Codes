/***************************************************************************
Name : Shubham Dey
Program : Sort N numbers in decending order. Show sorted and unsorted lists.
Program No. : 057
Date : 10/02/2021
****************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int *mem_alloc(int n);
void input(int n,int *A);
void display(int n,int *A);
void D_sort(int n,int *A);

void main()
{
    int N,*lst;

    printf("\nEnter number of elements :\t");
    scanf("%d",&N);

    lst = mem_alloc(N);

    printf("\nEnter %d elements.\n\n",N);
    input(N,lst);

    printf("\nUnsorted list :\n");
    display(N,lst);
    D_sort(N,lst);
    printf("\nSorted list in Ascending order :\n");
    display(N,lst);
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
    {
        printf("Enter element %d :\t",i+1);
        scanf("%d",&A[i]);
    }
}
void display(int n,int *A)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d  ",A[i]);
    printf("\n");
}
void D_sort(int n,int *A)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(A[i]<A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}