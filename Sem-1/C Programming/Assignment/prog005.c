/*****************************************************
Name : Shubham Dey
Program : Divide an integer number by another integer.
Program No. : 005
Date : 2020.12.02
******************************************************/

#include<stdio.h>

void main()
{
    int dividend, divisor, quotient, remainder;                      // Declaration

step1:
    printf("Enter Dividend and Divisor :\n");
    scanf("%d %d",&dividend,&divisor);                               // Input from user

    if (divisor==0)  goto step1;                                     // If Divisor==0, take input again

    quotient=dividend/divisor;                                       // Calculation of Quotient
    remainder=dividend%divisor;                                      // Calculation of Remainder

    printf("Dividend = %d\tDivisor = %d\tQuotient = %d\tand\tRemainder = %d.\n",dividend,divisor,quotient,remainder); 
}