/**************************************
Name : Shubham Dey
Program : Multiply two integer numbers
Program No. : 004
Date : 2020.12.02
****************************************/

#include<stdio.h>

void main()
{
    int a,b,c;                                             // Declaration
    
    printf("Enter two numbers :\n");
    scanf("%d %d",&a,&b);                                  // Input from user

    c=a*b;                                                 // Calculation
    
    printf("Product of %d and %d is %d.\n",a,b,c);
}