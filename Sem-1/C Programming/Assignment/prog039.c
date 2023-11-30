/************************************************
Name : Shubham Dey
Program : Find the sum of all digits of a number.
Program No. : 039
Date : 10.01.2021
*************************************************/

#include<stdio.h>

void main()
{
    int num,n,r,sum=0;

    printf("Enter any number :\t");
    scanf("%d",&num);

    n = num;
    while(n>=1)
    {
        r = n%10;
        sum += r;
        n /= 10;
    }
    printf("Sum of all the digits of %d = %d.\n",num,sum);
}