/***********************************************************************************
Name : Shubham Dey
Program : Write a program to do the following:
            a) Declare x and y as integer variables and z as a short integer variable.
            b) Assign two 6 digit numbers to x and y.
            c) Assign the sum of x and y to z.
            d) Output the value of x, y and z.
Program No. : 2.7
************************************************************************************/

#include<stdio.h>

void main()
{
    int x,y;
    short z;

    printf("Enter the values of x and y :\n");
    scanf("%d %d",&x,&y);

    z = x + y;

    printf("x = %d\ty = %d\tz = %d",x,y,z);
}