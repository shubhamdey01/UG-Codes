/**************************************************************************************************
Name : Shubham Dey
Program : Take two float type numbers from the user and then divides the first number by the second
          and display the result along with the numbers.
Program No. : 2.4
***************************************************************************************************/

#include<stdio.h>

void main()
{
    float x,y,div;

    printf("Enter dividend and divisor :\n");
    scanf("%f %f",&x,&y);

    div = x/y;
    printf("Dividend = %f\tDivisor = %f\tQuotient = %f",x,y,div);
}