/*********************************************************************************************
Name : Shubham Dey
Program : Interchange the values of two variables by using and without using a third variable.
Program No. : 012
Date : 2020.12.07
**********************************************************************************************/

#include<stdio.h>

void main()
{
    int first,second,temp;

    // Using third variable.
    printf("Enter first number : ");
    scanf("%d",&first);
    printf("Enter second number : ");
    scanf("%d",&second);
    temp = first;
    first = second;
    second = temp;
    printf("First = %d\tand\tSecond = %d\n",first,second);

    // Without using third variable.
    printf("\nEnter first number : ");
    scanf("%d",&first);
    printf("Enter second number : ");
    scanf("%d",&second);
    first -= second;
    second += first;
    first = second - first;
    printf("First = %d\tand\tSecond = %d\n",first,second);
}