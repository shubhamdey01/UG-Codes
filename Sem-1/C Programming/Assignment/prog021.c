/****************************************
Name : Shubhan Dey
Program : Find the factorial of a number.
Program No. : 021
Date : 2020.12.07
*****************************************/

#include<stdio.h>

void  main()
{
    int N,i,fact=1;
    
step1:
    printf("Enter the value of N :\t");
    scanf("%d",&N);

    if (N<0) goto step1;      // Factorial of -ve number is nor possible.

    for (i=2; i<=N; i++)
        fact *=i;
    printf("Factorial of %d = %d! = %d.\n",N,N,fact);
}