/*********************************************
Name : Shubham Dey
Program : Print first n non-Lucas numbers.
Program No. : 033
Date : 2021.01.09
**********************************************/

#include<stdio.h>

void main()
{
    int n,i,a=2,b=1,c1,c2,count;

    printf("Enter the value of n :\t");
    scanf("%d",&n);

    printf("First %d non-Fibonacci numbers :-\n",n);
    for(count=1 ; count<=n;)
    {
        c1 = a + b;
        a = b;
        b = c1;
        c2 = a + b;
        for(i=c1+1; i<c2; i++)
        {
            printf("%d  ",i);
            count++;
            if(count>n) break;
        }
    }
}