/*******************************************
Name : Shubham Dey
Program : Display first N natural numbers.
Program No. : 013
Date : 2020.12.07
********************************************/

#include<stdio.h>

void main()
{
    int N,i;

    printf("Enter N :\t");
    scanf("%d",&N);

    for (i=1; i<=N; i++)
        printf("%d  ",i);
}