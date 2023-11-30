/********************************************************************
Name : Shubham Dey
Program : Display the area of a circle by defining the constant π.
Program No. : 1.5
Date : 2020.12.18
*********************************************************************/

#include <stdio.h>

#define PI  22/7.

void main()
{
    float r,ar;

    printf("Enter radius of the circle :\t");
    scanf("%f",&r);

    ar = PI*r*r;
    printf("Area of the circle with radius %f is %f sq. units.\n",r,ar);
}