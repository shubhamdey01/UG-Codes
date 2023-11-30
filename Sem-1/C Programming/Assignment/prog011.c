/*****************************************************
Name : Shubhan Dey
Program : Check whether a year is a Leap Year or not.
Program No. : 011
Date : 2020.12.02
******************************************************/

#include<stdio.h>

void main()
{
    int year;
    
    printf("Enter any Year :\n");
    scanf("%d",&year);

    if (year%4 == 0)
    {
        if (year%100 == 0)
        {
            if (year%400 == 0)
                printf("%d is a Leap Year.\n",year);
            else
                printf("%d is not a Leap Year.\n",year);
        }
        else
            printf("%d is a Leap Year.\n",year);
    }
    else
        printf("%d is not a Leap Year.\n",year);       
}