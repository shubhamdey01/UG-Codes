/*********************************************************************************************
Name : Shubham Dey
Program : Given the values of the variables x, y and z, write a program to rotate their values
          such that x has the value of y, y has the value of z, and z has the value of x.
Program No. : 3.1
**********************************************************************************************/

#include<stdio.h>

void main()
{
    int x=10, y=20, z=30,t;
    printf("Before :\n\tx = %d,  y = %d,  z = %d\n",x,y,z);

    t = x;
    x = y;
    y = z;
    z = t;
    printf("After :\n\tx = %d,  y = %d,  z = %d\n",x,y,z);
}