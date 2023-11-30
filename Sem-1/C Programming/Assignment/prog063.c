/*************************************************************************
Name : Shubham Dey
Program : Sort an array and insert an element in its appropriate position.
Program No. : 063
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int *mem_alloc(int p);
void input(int n,int *A);
void display(int n,int *A);
void sort(int p,int *A);
void insert(int p,int a,int *A);

void main()
{
    int n,*ar,x;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = mem_alloc(n+1);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nUnsorted array :\n");
    display(n,ar);
    sort(n,ar);
    printf("\nSorted array :\n");
    display(n,ar);
    printf("Enter the number to be inserted :\t");
    scanf("%d",&x);
    insert(n,x,ar);
    printf("\nAFTER inserting %d in sorted array :\n",x);
    display(n+1,ar);
}

int *mem_alloc(int p)
{
    int *A;
    A = (int*)calloc(p,sizeof(int));
    return A;
}
void input(int p,int *A)
{
    int i;
    for(i=0;i<p;i++)
        scanf("%d",&A[i]);
}
void display(int p,int *A)
{
    int i;
    for(i=0;i<p;i++)
        printf("%d  ",A[i]);
    printf("\n");
}
void sort(int p,int *A)
{
    int i,j,temp;
    for(i=0;i<p-1;i++)
        for(j=i+1;j<p;j++)
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}
void insert(int p,int a,int *A)
{
    int i=0,j;
    while(A[i]<a)  i++;
    for(j=p;j>i;j--)
        A[j]=A[j-1];
    A[j]=a;
    printf("i=%d, j=%d, p=%d\n",i,j,p);
}