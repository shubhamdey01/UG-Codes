/****************************************************************************************
Name : Shubham Dey
Program : Write a funtion to implement the rule tahat a number is divisible by 11 or not.
Program No. : 054
Date : 07/02/2021
*****************************************************************************************/

#include<stdio.h>

int rule1(int n);

void main()
{
    int num;

    printf("Enter any number :\t");
    scanf("%d",&num);

    if(rule1(num))
        printf("%d is divisible by 11.\n",num);
    else
        printf("%d is not divisible by 11.\n",num);
}

int rule1(int n)
{
    int i=1,s=0,r;
    while(n>0)
    {
        r = n%10;
        if(i%2==0)
            s += r;
        else
            s -= r;
        n /= 10;
        i++;
    }
    if(s%11==0) return 1;
    return 0;
}