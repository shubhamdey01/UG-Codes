/***************************************************************
Name : Shubham Dey
Program : Write a program to display the following simple arithmetic calculator
                x       =          y          =
                Sum     =          Difference =
                Product =          Division   =
Program /no. : 1.14
****************************************************************/

#include<stdio.h>

void main()
{
    float x,y,sum,diff,prod,div;

    printf("Enter the values of x and y :\n");
    scanf("%f %f",&x,&y);
    sum=x+y;
    diff=x-y;
    prod=x*y;
    div=x/y;

    printf("x\t= %f\t\ty\t\t= %f\n",x,y);
    printf("Sum\t= %f\t\tDifference\t= %f\n",sum,diff);
    printf("Product\t= %f\t\tDividion\t= %f",prod,div);
}