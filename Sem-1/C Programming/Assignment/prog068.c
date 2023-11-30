/*************************************************************************
Name : Shubham Dey
Program : Count the number of occurance of a character in a given line of text.
Program No. : 068
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>

int count(char txt[50],char a);

void main()
{
    char c,str[50];

    printf("Enter a sentence :\n");
    gets(str);
    printf("Enter character :\t");
    c = getchar();

    printf("%c occurs %d times in the given line of text.\n",c,count(str,c));
}

int count(char txt[50],char a)
{
    int i=0,j=0;
    while(txt[i]!='\0')
    {
        if(txt[i]==a)
            j++;
        i++;
    }
    return j;
}