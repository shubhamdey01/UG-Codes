/*************************************************************************
Name : Shubham Dey
Program : Count the number of occurance of a sub-string in a string.
Program No. : 069
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>
#include<string.h>

int count(char txt[50],char a[10]);

void main()
{
    char str[50],c[10];

    printf("Enter a sentence :\n");
    gets(str);
    printf("Enter sub-string :\t");
    gets(c);

    printf("\"%s\" occurs %d times in the given line of text.\n",c,count(str,c));
}

int count(char txt[50],char a[10])
{
    int i=0,j,k,n=0;
    while(txt[i]!='\0')
    {
        if(txt[i]==a[0])
        {
            for(j=1,k=i+1;txt[k]==a[j];j++,k++);
            if(j==strlen(a))
                n++;
        }
        i++;
    }
    return n;
}