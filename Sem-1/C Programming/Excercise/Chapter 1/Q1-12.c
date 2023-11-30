/***********************************************************************************
Name : Shubham Dey
Program : A point on the circumference of a circle whose center is (0, 0) is (4, 5).
          Write a program to compute perimeter and area of the circle.
Program No. : 1.12
************************************************************************************/

#include<stdio.h>
#include<math.h>

#define PI  22/7.

void main()
{
    int o1=0, o2=0 , x=4, y=5;
    float r,cr,ar;

    r = sqrt(pow((x-o1),2)+pow((y-o2),2));

    cr = 2*PI*r;
    ar = PI*r*r;

    printf("\nCircumference = %f units\tArea = %f sq units\n",cr,ar);
}