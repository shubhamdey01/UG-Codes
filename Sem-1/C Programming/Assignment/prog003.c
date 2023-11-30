/**********************************************************
Name : Shubham Dey
Program : Subtract an integer number from another integer.
Program No. : 003
Date : 2020.12.02
************************************************************/

#include<stdio.h>

void main()
{
    int minuend, subtrahend, difference;                                                 // Declaration
    
    printf("Enter the value of Minuend and Subtrahend :\n");
    scanf("%d %d",&minuend,&subtrahend);                                                 // Input from user

    difference = minuend-subtrahend;                                                     // Calculation
    
    printf("The difference of %d from %d is %d.\n",subtrahend,minuend,difference);
}