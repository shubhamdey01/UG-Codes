/*******************************
Name : Shubhan Dey
Program : First N Prime numbers.
Program No. : 019
Date : 2020.12.04
********************************/

#include<stdio.h>
#include <math.h>

void main()
{
    int N,i,x=2,count;

    printf("Enter a number :\n");
    scanf("%d",&N);

    for (count=1; count<=N; x++)            // Counts N Prime numbers
    {
        for(i=2;i<=(int)sqrt(x);i++)    // Cheks Prime or not
        {
            if (x%i==0)
                break;
        }
        if (i==(int)sqrt(x)+1)
        {
    	    printf("%d  ",x);
            count++;
        }
    }
}