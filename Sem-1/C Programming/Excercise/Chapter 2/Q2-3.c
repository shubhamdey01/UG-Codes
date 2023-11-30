/*********************************************
Name : Shubham Dey
Program : Print the even numbers from 1 to 100.
Program No. : 2.3
**********************************************/

#include<stdio.h>

void main()
{
    int i;

    printf("Even numbers from 1 to 100 are :-\n");
    for(i=2; i<=100; i+=2)
        printf("%d  ",i);
}