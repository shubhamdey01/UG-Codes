/*************************
Name : Shubhan Dey
Roll No. :
Program : Check Perfect number.
Program No. : 011
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int N,I=1,sum=0;
    printf("Enter any number :\n");
    scanf("%d",&N);

step1:
    if (I==N)
    {
            if (sum==N)
            {
                printf("%d is a Perfect Number.",N);
            }
            else
            {
                printf("%d is not a Perfect Number.",N);
            }
    }
    else
    {
        if (N%I==0)
        {
            sum = sum+I;
            I = I+1;
            goto step1;
        }
        else
        {
            I = I+1;
            goto step1;
        }
        
        
    }
    
}