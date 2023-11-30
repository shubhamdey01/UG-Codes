/*************************************************************************
Name : Shubham Dey
Program : Compare two strings without using any string function.
Program No. : 066
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>

int compare(char a[20],char b[20]);

void main()
{
    char str1[20],str2[20];

    printf("Enter two string to compare :\n");
    gets(str1);
    gets(str2);
    if(compare(str1,str2))
        printf("\nGiven strings are equal\n");
    else
        printf("\nGiven strings are not equal.\n");
}

int compare(char a[20],char b[20])
{
    int i=0;
    while(a[i]!='\0' && b[i]!='\0')
    {
        if(a[i] != b[i])
            return 0;
        i++;
    }
    return 1;
}