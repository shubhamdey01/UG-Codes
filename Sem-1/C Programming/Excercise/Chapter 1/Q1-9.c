/***********************************************************************
Name : Shubham Dey
Program : Convert temperature from Celsius to Fahrenheit and vice-versa.
Program No. : 1.9
************************************************************************/

#include<stdio.h>

void main()
{
    int ch;
    float c,f;

    while(1)
    {
        printf("\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Exit\n");
        printf("\nEnter your choice :\t");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("Enter temperature in Celsius :\t");
            scanf("%f",&c);
            f = (9*c/5)+32;
            printf("%f Celsius  =  %f Fahrenheit\n",c,f);
        }
        else if(ch==2)
        {
            printf("Enter temperature in Fahrenheit :\t");
            scanf("%f",&f);
            c = (f-32)*5/9;
            printf("%f Fahrenheit  =  %f Celsius\n",f,c);
        }
        else if(ch==3)
            break;
        else
            printf("\n!!  INVALID CHOICE  !!\n");
    } 
}