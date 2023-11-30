/*****************************************
Name : Shubham Dey
Program : Print first n Lucas numbers.
Program No. : 032
Date : 2021.01.09
******************************************/

#include<stdio.h>

void main()
{
    int n,a=2,b=1,c,count;

    printf("Enter the value of n :\t");
    scanf("%d",&n);

    printf("First %d Lucas numbers :-\n",n);
    if(n==1) printf("%d  ",a);
    else if(n>=2) printf("%d  %d  ",a,b);
    for(count=3 ; count<=n; count++)
    {
        c = a + b;
        printf("%d  ",c);
        a = b;
        b = c;
    }
}