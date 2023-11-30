// Interchange the values of two variables by using and without using a third variable.
// Using sub-funtion
// Date : 08.01.2021

#include<stdio.h>

void SWAP3(int *n1,int *n2);
void SWAP2(int *n1,int *n2);

void main()
{
    int num1,num2;

    // Using 3rd variable.
    printf("\nEnter first number :\t");
    scanf("%d",&num1);
    printf("Enter second number :\t");
    scanf("%d",&num2);

    printf("BEFORE :\tNumber 1 = %d\tNumber 2 = %d\n",num1,num2);
    SWAP3(&num1,&num2);
    printf("AFTER  :\tNumber 1 = %d\tNumber 2 = %d\n",num1,num2);

    // Without using 3rd variable.
    printf("\nEnter first number :\t");
    scanf("%d",&num1);
    printf("Enter second number :\t");
    scanf("%d",&num2);

    printf("BEFORE :\tNumber 1 = %d\tNumber 2 = %d\n",num1,num2);
    SWAP2(&num1,&num2);
    printf("AFTER  :\tNumber 1 = %d\tNumber 2 = %d\n",num1,num2);
}

void SWAP3(int *n1,int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void SWAP2(int *n1,int *n2)
{
    *n1 -= *n2;
    *n2 += *n1;
    *n1 = *n2 - *n1;
}