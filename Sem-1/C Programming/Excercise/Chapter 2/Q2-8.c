/**************************************************************************************
Name : Shubham Dey
Program : Read two floating point numbers using a scanf statement, assign their sum to
          an integer variable and then output the values of all the three variables.
Program No. : 2.8
***************************************************************************************/

#include<stdio.h>

void main()
{
    float a,b;
    int sum;

    printf("Enter two floating point numbers :\n");
    scanf("%f %f",&a,&b);

    sum = a + b;
    printf("a = %f\tb = %f\tsum = %d\n",a,b,sum);
}