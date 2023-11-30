/********************************************************************************
Name : Shubham Dey
Program : Compute the area of the triangle given, the values of sides a, b and c.
Program No. : 1.10
*********************************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    float a,b,c,s,ar;

    printf("Enter the sides of the triangle :\n");
    scanf("%f %f %f",&a,&b,&c);

    s = (a+b+c)/2;
    ar = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("\nArea of the triangle = %f sq units.\n",ar);
}