/******************************************************************************************
Name : Shubham Dey
Program : Find mean, median, mode and standard deviation for ungrouped frequency type data.
Program No. : 058
Date : 10/02/2021
*******************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float *mem_alloc(int n);
void input(int n,float *A);
void display(int n,float *A);
void sort(int n,float *A);
float mean(int n,float *A);
float median(int n,float *A);
float mode(int n,float *A);
float st_dv(int n,float *A);

void main()
{
    int N;
    float *lst;

    printf("\nEnter number of elements :\t");
    scanf("%d",&N);

    lst = mem_alloc(N);

    printf("\nEnter %d elements.\n\n",N);
    input(N,lst);

    printf("\nUnsorted list :\n");
    display(N,lst);
    sort(N,lst);
    printf("\nSorted list :\n");
    display(N,lst);

    printf("Mean = %g\n",mean(N,lst));
    printf("Median = %g\n",median(N,lst));
    printf("Mode = %g\n",mode(N,lst));
    printf("Standard Deviation = %g\n",st_dv(N,lst));
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
    {
        printf("Enter element %d :\t",i+1);
        scanf("%f",&A[i]);
    }
}
void display(int n,float *A)
{
    int i;
    for(i=0;i<n;i++)
        printf("%g  ",A[i]);
    printf("\n");
}
void sort(int n,float *A)
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
float mean(int n,float *A)
{
    int i;
    float sum=0;
    for(i=0;i<n;i++)
        sum += A[i];
    return sum/n;
}
float median(int n,float *A)
{
    if(n%2==0)
        return (A[n/2-1]+A[n/2])/2.;
    return A[n/2];
}
float mode(int n,float *A)
{
    int i,j,count,maxcount=0;
    float mode;

    for(i=0;i<n-1;i++)
    {
        count = 0;
        for(j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
                count++;
        }
        if(count>maxcount)
        {
            maxcount = count;
            mode = A[i];
        }
    }
    return mode;
}
float st_dv(int n,float *A)
{
    int i;
    float sum=0,m=mean(n,A);
    for(i=0;i<n;i++)
        sum += pow((A[i]-m),2);
    return sqrt(sum/n);
}