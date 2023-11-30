/****************************************************
Name : Shubham Dey
Program : Find GCD of two numbers by using recursion.
Program No. : 050
Date : 07/02/2021
*****************************************************/

#include<stdio.h>

int GCD(int a,int b);

void main()
{
    int n1,n2;
    printf("Enter two numbers to compute GCD :\n");
    scanf("%d %d",&n1,&n2);

    printf("GCD of %d and %d is %d.\n",n1,n2,GCD(n1,n2));
}

int GCD(int a,int b)
{
    if(b==0)
        return a;
    return (GCD(b,a%b));
}