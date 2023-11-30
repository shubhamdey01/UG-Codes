/************************************************************
Name : Shubham Dey
Program : Generate all combinations of 1,2,3 using while loop.
Program No. : 043
Date : 10.01.2021
*************************************************************/

#include<stdio.h>

void main()
{
    int a,b,c;

    a = 1;
    while(a<=3)
    {
        b = 1;
        while(b<=3)
        {
            c = 1;
            while(c<=3)
            {
                if(a!=b && b!=c && c!=a)
                    printf("%d%d%d\n",a,b,c);
                c++;
            }
            b++;
        }
        a++;
    }
}