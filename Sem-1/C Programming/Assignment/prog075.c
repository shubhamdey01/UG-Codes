/*****************************************************
Name : Shubham Dey
Program : Reverse the string.
Program No. : 075
Date : 22/02/2021
******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 30

char *mem_alloc(int n);
void rev(char *A);

void main()
{
    char *str;

    str = mem_alloc(LEN);
    printf("Enter string :\t");
    scanf("%s",str);
    printf("Given string =\t%s\n",str);
    rev(str);
    printf("Reversed string =\t%s\n",str);
}

char *mem_alloc(int n)
{
    char *A;
    A = (char*)calloc(n,sizeof(char));
    return A;
}
void rev(char *A)
{
    int i,lim,n=strlen(A);
    char temp;
    lim = (n%2==0) ? n/2 : n/2+1;
    for(i=0;i<lim;i++)
    {
        temp = A[i];
        A[i] = A[n-i-1];
        A[n-i-1] = temp;
    }
}