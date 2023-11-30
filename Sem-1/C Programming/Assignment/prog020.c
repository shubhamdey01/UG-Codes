/**********************************
Name : Shubhan Dey
Program : First N Composite numbers.
Program No. : 020
Date : 2020.12.04
***********************************/

#include<stdio.h>
#include <math.h>

void main()
{
    int N,i,x=2,count;

    printf("Enter a number :\n");
    scanf("%d",&N);

    for (count=1; count<=N; x++)
    {
        for(i=2;i<=(int)sqrt(x);i++)
        {
            if (x%i==0)
            {
                printf("%d  ",x);
                count++;
                break;
            }
        }
    }
}