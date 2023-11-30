/*************************
Name : Shubhan Dey
Roll No. :
Program : Check Armstrong number.
Program No. : 012
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int num,N,rem,sum=0;
    printf("Enter any number :\n");
    scanf("%d",&num);
    N = num;
step1:
    if (N>=1)
    {
        rem = N%10;
        sum = sum + (rem*rem*rem);
        N = N/10;
        goto step1;
    }
    else
    {
        if (num==sum)
        {
            printf("%d is an Armstrong Number.",num);
        }
        else
        {
            printf("%d is not an Armstrong Number.",num);
        }
    }
}   