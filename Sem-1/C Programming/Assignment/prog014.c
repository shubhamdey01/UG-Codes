/**************************************
Name : Shubhan Dey
Program : Add first N natural numbers.
Program No. : 014
Date : 2020.12.04
***************************************/

#include<stdio.h>

void main()
{
    int n,x=0,sum=0;

    printf("Enter any number :\n");
    scanf("%d",&n);

step1:
    x = x+1;
    sum = sum+x;
    if (x==n)
        printf("Sum of first %d natural numbers is %d.\n",n,sum);
    else goto step1;
}