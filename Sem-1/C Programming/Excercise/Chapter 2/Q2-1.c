/*************************************************************
Name : Shubham Dey
Program : Compute and display the value of 1+1/2+1/3+....+1/n
Program No. : 2.1
**************************************************************/

#include<stdio.h>

void main()
{
    int n,i;
    float sum;

    printf("Ente rthe value of n :\t");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        sum += 1./i;
    printf("Required sum is %f.",sum);
}