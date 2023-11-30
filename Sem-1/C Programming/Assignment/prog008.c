/************************************************
Name : Shubham Dey
Program : Check whether a number is even or odd.
Program No. : 008
Date : 2020.12.02
*************************************************/

#include<stdio.h>

void main()
{
    int n;
    
    printf("Enter the Number : \n");
    scanf("%d",&n);

    if(n%2==0)
        printf("%d is an Even Number\n",n);
    else
        printf("%d is an Odd number\n",n);
}