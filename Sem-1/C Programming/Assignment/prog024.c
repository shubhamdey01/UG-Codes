/******************************************************************
Name : Shubhan Dey
Program : Largest and 2nd largest of N numbers without using array.
Program No. : 024
Date : 2020.12.07
*******************************************************************/

#include<stdio.h>

void  main()
{
    int N,i,num,max1,max2;

    printf("How many numbers ?\t");
    scanf("%d",&N);
    printf("Enter %d numbers.\n",N);
    scanf("%d",&num);
    max1 = num;
    max2 = num;
    for (i=1; i<N; i++)
    {
        scanf("%d",&num);
        if (num>max1)
        {
            max2 = max1;
            max1 = num;
        }
        else if (num>max2)
            max2 = num;
    }
    printf("Largest = %d\tand\tSecond largest = %d\n",max1,max2);
}