/*******************************************************************
Name : Shubham Dey
Program : Print all Fibonacci and non-Fibonacci numbers less than n.
Program No. : 031
Date : 2021.01.09
********************************************************************/

#include<stdio.h>

void main()
{
    int n,a,b,c1,c2,i;
    
    printf("Enter the value of n :\t");
    scanf("%d",&n);
    
    a=1,b=1;                                       // Fibonacci no. < n
    printf("\nFibonacci numbers less than %d :-\n",n);
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
    a=1,b=2;                                      // non-Fibonacci no. < n
    printf("\n\nNon-Fibonacci numbers less than %d :-\n",n);
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