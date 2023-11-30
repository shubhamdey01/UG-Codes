/**********************************************************************
Name : Shubham Dey
Program : Find the sum of the series : 1 + 1/2^2 + 1/3^3 + ... + 1/n^n.
Program No. : 026-e
Date : 2021.01.04
***********************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int n,i;
    float sum=0;

    printf("Enter the value of n :\t");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        sum += 1/pow(i,i);

    printf("Sum of the series : ");
    if(n==1)
        printf("1 = %f",sum);
    else if(n==2)
        printf("1 + 1/2^2 = %f",sum);
    else if(n==3)
        printf("1 + 1/2^2 + 1/3^3 = %f",sum);
    else if(n==4)
        printf("1 + 1/2^2 + 1/3^3 + 1/4^4 = %f",sum);
    else
        printf("1 + 1/2^2 + 1/3^3 + ... + 1/%d^%d = %f",n,n,sum);
}