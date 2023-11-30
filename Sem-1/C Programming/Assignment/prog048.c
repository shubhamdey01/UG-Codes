/***************************************************************
Name : Shubham Dey
Program : Recursive funtion to print the factorial of a number.
Program No. : 048
Date : 03/02/2021
****************************************************************/

#include<stdio.h>

unsigned fact(int n);

void main()
{
    int n;

    printf("Enter any number :\t");
    scanf("%d",&n);

    printf("%d! = %d",n,fact(n));
}

unsigned fact(int n)
{
    if(n==0 || n==1)
        return 1;
    return (fact(n-1)*n);
}