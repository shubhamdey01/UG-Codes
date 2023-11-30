/*********************************************
Name : Shubham Dey
Program : Find perfect numbers within a range.
Program No. : 042
Date : 10.01.2021
**********************************************/

#include<stdio.h>

void main()
{
    int n,i,j,sum;
    printf("Enter lower and upper limit :\n");
    scanf("%d %d",&i,&n);

    for(i; i<=n; i++)
    {    
        sum = 0;
        for(j=1; j<i; j++)
        {
            if (i%j==0)
                sum += j;
        }
        if (sum==i)
            printf("%d  ",i);
    }
}