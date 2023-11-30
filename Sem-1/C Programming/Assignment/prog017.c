/*************************************************
Name : Shubhan Dey
Program : Find all Prime numbers between 1 and N.
Program No. : 017
Date : 2020.12.04
**************************************************/

#include<stdio.h>
#include <math.h>

void main()
{
    int N,i,count,x=0;

    printf("Enter a number :\t");
    scanf("%d",&N);

    printf("List of all prime numbers beetween 1 and %d.\n",N);
    for (count=2; count<=N; count++)            // Checks numbers upto N
    {
        for(i=2; i<=(int)sqrt(count); i++)      // Checks Prime or not
        {
            if (count%i==0)
                break;
        }
        if (i==(int)sqrt(count)+1)
        {
    	    printf("%d  ",count);
            x++;
        }
    }
    printf("\nTotal number of prime numbers between 1 and %d is %d.\n",N,x);
}