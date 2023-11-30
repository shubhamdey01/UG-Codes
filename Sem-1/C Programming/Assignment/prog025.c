/********************************************************************
Name : Shubham Dey
Program : Smallest and 2nd smallest of N numbers without using array.
Program No. : 025
Date : 2020.12.07
*********************************************************************/

#include<stdio.h>

void  main()
{
    int N,i,num,min1,min2;

    printf("How many numbers ?\t");
    scanf("%d",&N);
    printf("Enter %d numbers.\n",N);
    scanf("%d",&num);
    min1 = num;
    min2 = num;
    for (i=1; i<N; i++)
    {
        scanf("%d",&num);
        if (num<min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num<min2)
            min2 = num;
    }
    printf("Smallest = %d\tand\tSecond smallest = %d\n",min1,min2);
}