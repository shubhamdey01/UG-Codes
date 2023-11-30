/*************************
Name : Shubhan Dey
Roll No. :
Program : Min. of three numbersr.
Program No. : 016
Date : 2020.12.02
*************************/

#include<stdio.h>

void  main()
{
    int A,B,C,min;
    printf("Enter three numbers :\n");
    scanf("%d %d %d",&A,&B,&C);
    min = A;
    if (min>B)
    {
        min = B;
    }
    if (min>C)
    {
        min = C;
    }
    printf("Minimum of %d, %d and %d is %d.",A,B,C,min);
}