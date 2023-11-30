/****************************************************************************************
Name : Shubham Dey
Program : Use funtion add() to add and sub() to find the difference of two given numbers.
Program No. : 1.7
Date : 2020/12/18
****************************************************************************************/

#include <stdio.h>

int add(int x, int y);
int sub(int x, int y);

void main()
{
    int a=20,b=10,sum,diff;

    sum = add(a,b);
    printf("%d + %d = %d\n",a,b,sum);

    diff = sub(a,b);
    printf("%d - %d = %d\n",a,b,diff);
}

int add(int x,int y)
{
    int s;
    s = x + y;
    return s;
}

int sub(int x,int y)
{
    int d;
    d = x - y;
    return d;
}