/***************************************************************
Name : Shubhan Dey
Program : Largest and Smallest of N numbers without using array.
Program No. : 023
Date : 2020.12.07
****************************************************************/

#include<stdio.h>

void  main()
{
    int N,i,num,max,min;

    printf("How many numbers ?\t");
    scanf("%d",&N);
    printf("Enter %d numbers.\n",N);
    scanf("%d",&num);
    max = num;
    min = num;
    for (i=1; i<N; i++)
    {
        scanf("%d",&num);
        if (num>max)
            max = num;
        if (num<min)
            min = num;
    }
    printf("Largest = %d\tand\tSmallest = %d\n",max,min);
}