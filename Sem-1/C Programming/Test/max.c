/*************************
Name : Shubhan Dey
Roll No. :
Program : Max. of three numbersr.
Program No. : 015
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int A,B,C,max;
    printf("Enter three numbers :\n");
    scanf("%d %d %d",&A,&B,&C);
    max = A;
    if (max<B)
    {
        max = B;
    }
    if (max<C)
    {
        max = C;
    }
    printf("Maximum of %d, %d and %d is %d.",A,B,C,max);
}