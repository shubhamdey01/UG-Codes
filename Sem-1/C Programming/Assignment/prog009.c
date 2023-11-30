/**************************************************
Name : Shubham Dey
Program : Centigrade to Fahrenheit and vice-versa.
Program No. : 009
Date : 2020.12.07
***************************************************/

#include<stdio.h>

void main()
{
    int ch;
    float C,F,ce,fh;

step1:
    printf("\n1. Centigrade to Fahrenheit.\n2. Fahrenheit to Centigrade.\n3. Exit.\n");
    printf("Enter your choice :\n");
    scanf("%d",&ch);

    if (ch==1)  // Centigrade to Fahrenheit.
    {
        printf("Enter temperature in Centigrade :\n");
        scanf("%f",&C);
        fh = 9*C/5.0+32;
        printf("%f Centigrade  =  %f Fahrenheit\n",C,fh);
        goto step1;
    }
    else if (ch==2) // Fahrenheit to Centigrade.
    {
        printf("Enter temperature in Fahrenheit :\n");
        scanf("%f",&F);
        ce = 5*(F-32)/9.0;
        printf("%f Fahrenheit  =  %f Centigrade\n",F,ce);
        goto step1;
    }
    else if (ch==3) // Exit
        printf("Thank You...\n");
    else
    {
        printf("Invalid choice.\n");
        goto step1;
    }
}