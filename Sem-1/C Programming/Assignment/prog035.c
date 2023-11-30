/****************************************************
Name : Shubham Dey
Program : Check whether a number is armstrong or not.
Program No. : 035
Date : 09.01.2021
*****************************************************/

#include<stdio.h>

int armstrong(int n);

void  main()
{
    int num;

    printf("Enter any number :\t");
    scanf("%d",&num);
    if (armstrong(num))
        printf("%d is an Armstrong Number.",num);
    else
        printf("%d is not an Armstrong Number.",num);
}

int armstrong(int n)
{
    int num,rem,sum=0;
    num = n;
    while(n>=1)
    {
        rem = n%10;
        sum += rem*rem*rem;
        n = n/10;
    }
    if(num==sum)
        return 1;
    return 0;
}