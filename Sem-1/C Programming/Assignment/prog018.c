/*****************************************************
Name : Shubhan Dey
Program : Find all Composite numbers between 1 and N.
Program No. : 018
Date : 2020.12.04
******************************************************/

#include<stdio.h>
#include <math.h>

void main()
{
    int N,i,count;

    printf("Enter a number :\n");
    scanf("%d",&N);

    for (count=4; count<=N; count++)        // Checks number upto N
    {
        for(i=2;i<=(int)sqrt(count);i++)    // Checks Composite or not
        {
            if (count%i==0)
            {
    	        printf("%d  ",count);
                break;
            }
        }
    }
}