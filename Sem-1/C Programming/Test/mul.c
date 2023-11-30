/*************************
Name : Shubhan Dey
Roll No. :
Program : Multiply first N natural numbers.
Program No. : 010
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int n,x=1,prod=1;
    printf("Enter any number :\n");
    scanf("%d",&n);

step1:
    x = x+1;
    prod = prod*x;
    if (x==n)
    {
        printf("Product of first %d natural numbers is %d.",n,prod);
    }
    else goto step1;
}


//Program No.             Program              File Name                          Date