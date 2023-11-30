/*************************************************************************
Name : Shubhan Dey
Program : Find the roots of a Quadratic equation and discuss their nature.
Program No. : 015
Date : 2020.12.07
**************************************************************************/

#include<stdio.h>
#include<math.h>

void  main()
{
    int a,b,c;
    float D,x1,x2,re,im;

    printf("Enter the coefficient a,b,c :\n");
    scanf("%d %d %d",&a,&b,&c);
    D = (b*b)-4*a*c;

    if (D>0)    // Two real and diffrent roots.
    {
        printf("Quadratic equation has TWO REAL and DIFFERENT ROOTS.\n");
        x1 = (-b + sqrt(D))/(2*a);
        x2 = (-b - sqrt(D))/(2*a);
        printf("Roots are :\t%f and %f.\n",x1,x2);
    }
    else if (D==0)  // Two real and equal roots.
    {
        printf("The above quadratic equation has TWO REAL and EQUAL ROOTS.\n");
        x1 = (-b + sqrt(D))/(2*a);
        printf("Roots are :\t%f and %f.\n",x1,x1);
    }
    else    // Two imaginary roots.
    {
        printf("The above quadratic equation has TWO NON-REAL ROOTS.\n");
        re = -b/(float)(2*a);
        im = sqrt(-D)/2*a;
        printf("Roots are :\t[(-%d + i (%f)]/%d = %f + %f i\tand\t",b,D,2*a,re,im);
        printf("[(-%d - i (%f)]/%d = %f - %f i.\n",b,D,2*a,re,im);
    }
}