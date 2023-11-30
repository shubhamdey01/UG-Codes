/*******************************************************
Name : Shubham Dey
Program : Convert all uppercase characters to lowercase.
Program No. : 073
Date : 22/02/21
********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define LEN 30

char *mem_alloc(int n);
void convert_L(char *A);

void main()
{
    char *str;

    str = mem_alloc(LEN);
    printf("Enter any string :\t");
    gets(str);
    convert_L(str);
    printf("\nString in lowercase :\t%s",str);
}

char *mem_alloc(int n)
{
    char *A;
    A = (char*)calloc(n,sizeof(char));
    return A;
}
void convert_L(char *A)
{
    int i=0;
    while(A[i]!='\0')
    {
        if(isupper(A[i]))
            A[i]=tolower(A[i]);
        i++;
    }
}