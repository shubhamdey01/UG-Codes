/***********************************************************************
Name : Shubham Dey
Program : Interchange the values of two variables by using sub-function.
Program No. : 052
Date : 07/02/2021
************************************************************************/

#include<stdio.h>

void swap(int *n1,int *n2);

void main()
{
    int num1,num2;

    printf("Enter first number :\t");
    scanf("%d",&num1);
    printf("Enter second number :\t");
    scanf("%d",&num2);

    printf("\nBEFORE SWAPING :\nNum1 = %d\tNum2 = %d\n",num1,num2);
    swap(&num1,&num2);
    printf("\nAFTER SWAPING :\nNum1 = %d\tNum2 = %d\n",num1,num2);
}

void swap(int *n1,int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}