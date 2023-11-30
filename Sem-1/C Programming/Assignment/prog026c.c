/**********************************************************************
Name : Shubham Dey
Program : Find the sum of the series : 1 + 1/2^2 + 1/3^2 + ... + 1/n^2.
Program No. : 026-c
Date : 2021.01.04
***********************************************************************/

#include<stdio.h>

void main()
{
    int n,i;
    float sum=0;

    printf("Enter the value of n :\t");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        sum += 1./(i*i);

    printf("Sum of the series : ");
    if(n==1)
        printf("1 = %f",sum);
    else if(n==2)
        printf("1 + 1/2^2 = %f",sum);
    else if(n==3)
        printf("1 + 1/2^2 + 1/3^2 = %f",sum);
    else if(n==4)
        printf("1 + 1/2^2 + 1/3^2 + 1/4^2 = %f",sum);
    else
        printf("1 + 1/2^2 + 1/3^2 + ... + 1/%d^2 = %f",n,sum);
}