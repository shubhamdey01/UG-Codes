/*********************************************************************************************
Name : Shubham Dey
Program : The price of one kg of rice is Rs. 16.75 and one kg of sugar is Rs.15. 
          Write a program to get these values from the user and display the prices as follows:
                        *** LIST OF ITEMS***
                        Item        Price
                        Rice        Rs. 16.75
                        Sugar       Rs. 15.00
Program No. : 2.5
**********************************************************************************************/

#include<stdio.h>

void main()
{
    float rice,sugar;

    printf("Enter the price of 1kg of Rice :\t");
    scanf("%f",&rice);
    printf("Enter the price of 1kg of Sugar :\t");
    scanf("%f",&sugar);

    printf("***  LIST OF ITEMS  ***\n");
    printf("Item\t\tPrice\n");
    printf("Rice\t\tRs. %.2f\n",rice);
    printf("Sugar\t\tRs. %.2f\n",sugar);
}