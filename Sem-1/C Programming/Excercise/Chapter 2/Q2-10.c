/******************************************************************************
Name : Shubham Dey
Program : Illustrate the use of symbolic constants in a real-life application.
Program No. : 2.10
*******************************************************************************/

#include<stdio.h>

#define MAX 200
#define print printf

void main()
{
    int i=0;
    while(i<=MAX)
    {
        print("%d  ",i);
        i+=10;
    }
}