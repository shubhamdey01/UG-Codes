/***********************************************************************************
Name : Shubham Dey
Program : The line joining the points (2,2) and (5,6) which lie on the circumference of a circle is the
          diameter of the circle. Write a program to compute the area of the circle.
Program No. : 1.12
************************************************************************************/

#include<stdio.h>
#include<math.h>

#define PI  22/7.

void main()
{
    int x1=2, y1=2 , x2=5, y2=6;
    float r,ar;

    r = sqrt(pow((x2-x1),2)+pow((y2-y1),2))/2;
    ar = PI*r*r;
    printf("\nArea = %f sq units\n",ar);
}