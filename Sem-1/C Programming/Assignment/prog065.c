/*************************************************************************
Name : Shubham Dey
Program : Copy one string to another without using string function.
Program No. : 065
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>

void copy(char s2[20],char s1[20]);

void main()
{
    char str1[20],str2[20];

    printf("Enter any string :\t");
    gets(str1);
    copy(str2,str1);
    printf("String 1 = %s\nString 2 = %s\n",str1,str2);
}

void copy(char s2[20],char s1[20])
{
    int i=0;
    while(s1[i]!='\0')
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
}