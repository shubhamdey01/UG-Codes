/****************************************************************************
Name : Shubham Dey
Program : To read the price of an item in decimal form and print it in paise.
Program No. : 2.2
*****************************************************************************/

#include<stdio.h>

void main()
{
    int pa;
    float rs;

    printf("Enter price in decimal form :\t");
    scanf("%f",&rs);

    pa = rs*100 ;
    printf("Rs. %.2f = %d paise.",rs,pa);
}