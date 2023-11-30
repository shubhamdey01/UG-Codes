/*****************************************************
Name : Shubham Dey
Program : Check whether a number is palindrome or not.
Program No. : 028
Date : 2021.01.05
******************************************************/

#include<stdio.h>

void main()
{
    int n,num,rev=0,remainder;

    printf("Enter the number :\t");
    scanf("%d",&n);
    num = n;
    while(n != 0)
    {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }
    if(num == rev)
        printf("%d is a Palindrome number.",num);
    else
        printf("%d is not a Palindrome number.",num);       
}