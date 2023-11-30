/****************************************************************************************************
Name : Shubham Dey
Program : To merge two sorted arrays in decending order. The two arrays are sorted in ascending order.
Program No. : 060
Date : 14/02/2021
*****************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

float *mem_alloc(int n);
void input(int n,float *A);
void A_sort(int n,float *A);
void display(int n,float *A);
void merge(int a,float *A,int b,float *B,float *C);

void main()
{
    int n1,n2;
    float *X,*Y,*Z;

    printf("Enter no. of elements in 1st list :\t");
    scanf("%d",&n1);
    X = mem_alloc(n1);
    printf("Enter %d numbers for 1st list :\n",n1);
    input(n1,X);

    printf("Enter no. of elements in 2nd list :\t");
    scanf("%d",&n2);
    Y = mem_alloc(n2);
    printf("Enter %d numbers for 2nd list :\n",n2);
    input(n2,Y);
    
    A_sort(n1,X);
    A_sort(n2,Y);
    printf("\nList-1 in ascending order :");
    display(n1,X);
    printf("List-2 in ascending order :");
    display(n2,Y);
    
    Z = mem_alloc(n1+n2);
    merge(n1,X,n2,Y,Z);
    printf("\nMerged list in decending order :\n");
    display(n1+n2,Z);
}

float *mem_alloc(int n)
{
    float *A;
    A = (float*)calloc(n,sizeof(float));
    return A;
}
void input(int n,float *A)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%f",&A[i]);
}
void A_sort(int n,float *A)
{
    int i,j;
    float temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
}
void display(int n,float *A)
{
    int i;
    for(i=0;i<n;i++)
        printf("%g  ",A[i]);
    printf("\n");
}
void merge(int a,float *A,int b,float *B,float *C)
{
    int i,j=0,k=0;
    for(i=a+b-1;i>=0;)
    {
        if(j<a && k<b)
        {
            if(A[j]<B[k])
            {
                C[i] = A[j];
                j++;
            }
            else
            {
                C[i] = B[k];
                k++;
            }
            i--;
        }
        else if(j==a)
            for(;i>=0;i--)
            {
                C[i] = B[k];
                k++;
            }
        else
            for(;i>=0;i--)
            {
                C[i] = B[j];
                j++;
            }
    }
}