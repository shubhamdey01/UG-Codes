/**********************************************************
Name : Shubham Dey
Program : Print all Lucas and non-Lucas numbers less than n.
Program No. : 034
Date : 09.01.2021
***********************************************************/

#include<stdio.h>

void main()
{
    int n,a,b,c1,c2,i;
    
    printf("Enter the value of n :\t");
    scanf("%d",&n);
    
    a=2; b=1; c1=0;                                      // Lucas no. < n
    printf("\nFirst %d Lucas numbers :-\n",n);
    if(n==1) printf("%d  ",a);
    else if(n>=2) printf("%d  %d  ",a,b);
    c1 = a + b;
    while(c1<n)
    {
        printf("%d  ",c1);
        a = b;
        b = c1;
        c1 = a + b;
    }
    a=1; b=3; c1=4;                                       // non-Lucas no. < n
    printf("\n\nFirst %d non-Lucas numbers :-\n",n);
    c1 = a + b;
    while(c1<n)
    {
        a = b;
        b = c1;
        c2 = a + b;
        for(i=c1+1; i<c2; i++)
        {
            if(i<n)
                printf("%d  ",i);
            else break;
        }
        c1 = c2;
    }
}