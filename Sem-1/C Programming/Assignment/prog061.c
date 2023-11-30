/**********************************************
Name : Shubham Dey
Program : Reverse all the elements of an array.
Program No. : 061
Date : 14/02/2021
***********************************************/

#include<stdio.h>
#include<stdlib.h>

int *mem_alloc(int p);
void input(int n,int *A);
void display(int n,int *A);
void reverse(int n,int *A);

void main()
{
    int n,*ar;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    ar = mem_alloc(n);
    printf("Enter %d numbers :\n",n);
    input(n,ar);

    printf("\nBEFORE :\n");
    display(n,ar);
    reverse(n,ar);
    printf("\nAFTER Reversing :\n");
    display(n,ar);
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
void reverse(int p,int *A)
{
    int i,lim,temp;
    lim = (p%2==0) ? p/2 : p/2+1;
    for(i=0;i<lim;i++)
    {
        temp = A[i];
        A[i] = A[p-i-1];
        A[p-i-1] = temp;
    }
}