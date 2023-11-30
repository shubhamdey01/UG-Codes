/***********************************************************************
Name : Shubham Dey
Program : Find binary equivalent of a decimal number using sub-function.
Program No. : 051
Date : 07/02/2021
************************************************************************/

#include<stdio.h>

int binary(int n);

void main()
{
    int n;

    printf("Enter decimal number :\t");
    scanf("%d",&n);

    printf("Binary equivalent of Decimal %d is %d.\n",n,binary(n));
}

int binary(int n)
{
    int b=0,rem,i=1;
    while(n>0)
    {
        rem = n%2;
        b += i*rem;
        n /= 2;
        i *= 10;
    }
    return b;
}