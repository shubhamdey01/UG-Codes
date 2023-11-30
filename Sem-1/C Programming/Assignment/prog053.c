/*************************************************************************
Name : Shubham Dey
Program : Using recursive function print the Fibonacci series for n terms.
Program : 053
Date : 07/02/2021
**************************************************************************/

#include<stdio.h>

int fibo(int n);

void main()
{
    int n,i;

    printf("Enter number to terms :\t");
    scanf("%d",&n);

    printf("First %d Fibonacci numbers :-\n",n);
    for(i=0;i<n;i++)
        printf("%d  ",fibo(i));
}

int fibo(int n)
{
    if(n==0 || n==1) return 1;
    return (fibo(n-1)+fibo(n-2));
}