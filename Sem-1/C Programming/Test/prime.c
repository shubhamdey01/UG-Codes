/*************************
Name : Shubhan Dey
Roll No. :
Program : Check Prime Number
Program No. : 007
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int N, K=2;
    printf("Enter any number :\n");
    scanf("%d",&N);
step1:
    if (K<N)
    {
        if (N%K == 0)
        {
            printf("%d is not a Prime Number.",N);
        }
        else
        {
            K = K+1;
            goto step1;
        }
    }
    else
    {
        printf("%d is a Prime Number.",N);
    }
}