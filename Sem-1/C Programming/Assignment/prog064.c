/*************************************************************************
Name : Shubham Dey
Program : Find the length of a string without using any string function.
Program No. : 064
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>


int length(char s[20]);

void main()
{
    char str[20];

    printf("Enter any string :\t");
    gets(str);
    printf("Length of the string \"%s\" is %d.\n",str,length(str));
}

int length(char s[20])
{
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
}