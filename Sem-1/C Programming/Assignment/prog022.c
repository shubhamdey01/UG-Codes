/**************************************************
Name : Shubhan Dey
Program : Average of N numbers without using array.
Program No. : 022
Date : 2020.12.07
***************************************************/

#include<stdio.h>

void  main()
{
    int N,i;
    float num,sum=0,avg;

    printf("How many numbers ?\t");
    scanf("%d",&N);
    printf("Enter %d numbers.\n",N);
    for (i=0; i<N; i++)
    {
        scanf("%f",&num);
        sum += num;
    }
    avg = sum/N;
    printf("Average = %f\n",avg);
}