/********************************************************
Name : Shubham Dey
Program : Evaluate C(n,r) and P(n,r) using sub-functions.
Program No. : 049
Date : 03/02/2021
*********************************************************/

#include<stdio.h>

float C(int n,int r);
float P(int n,int r);

void main()
{
    int ch,n,r;
step1:
    printf("\n1. Evaluate C(n,r)\n2. Evaluate P(n,r)\nAny other key to Exit.\n");
    printf("\nEnter your choice :\t");
    scanf("%d",&ch);

    switch (ch)
    {
        case 1:
step2:
            printf("Enter the values of n and r :\n");
            scanf("%d %d",&n,&r);
            if(n<r) goto step2;
            printf("C(%d,%d) = %.0f\n",n,r,C(n,r));
            goto step1;
        case 2:
step3:
            printf("Enter the values of n and r :\n");
            scanf("%d %d",&n,&r);
            if(n<r) goto step3;
            printf("P(%d,%d) = %.0f\n",n,r,P(n,r));
            goto step1;
        default:
            printf("\nTerminated!!");
            break;
    }
}

float C(int n,int r)
{
    float term =1;
    while(n>r)
    {
        term = term*n/(n-r);
        n--;
    }
    return term;
}

float P(int n,int r)
{
    int i=n-r;
    float term =1;
    while(n>i)
    {
        term = term*n;
        n--;
    }
    return term;
}