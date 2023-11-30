/*****************************************************
Name : Shubham Dey
Program : Check whether a string is palindrome or not.
Program No. : 071
Date : 20/02/2021
******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *mem_alloc(int n);
int palindrome(int p,char *A);

void main()
{
    int len;
    char *str;

    printf("Enter the length of string :\t");
    scanf("%d",&len);
    str = mem_alloc(len);
    printf("Enter string :\t");
    scanf("%s",str);
    if(palindrome(len,str))
        printf("\"%s\" is a Palindrome.",str);
    else
        printf("\"%s\" is not a Palindrome.",str);
}

char *mem_alloc(int n)
{
    char *A;
    A = (char*)calloc(n,sizeof(char));
    return A;
}
int palindrome(int n,char *A)
{
    int i,lim;
    lim = (n%2==0) ? n/2 : n/2+1;
    for(i=0;i<lim;i++)
        if(A[i] != A[n-i-1])
            break;
    if(i==lim)
        return 1;
    return 0;
}