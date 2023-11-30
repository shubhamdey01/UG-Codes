/*************************************************************************
Name : Shubham Dey
Program : Concatenate two strings without using any string function.
Program No. : 067
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>

void main()
{
    int i=0,j=0;
    char str1[20],str2[20];

    printf("Enter two strings :\n");
    gets(str1);
    gets(str2);
    printf("\nString 1 =\t");
    puts(str1);
    printf("\nString 2 =\t");
    puts(str2);
    printf("\n");

    while(str1[i]!='\0') i++;
    while(str2[j]!='\0')
    {
        str1[i+j]=str2[j];
        j++;
    }
    str1[i+j]='\0';
    
    printf("\nString 1 =\t");
    puts(str1);
    printf("\nString 2 =\t");
    puts(str2);
    printf("\n");
}