/******************************************************
Name : Shubham Dey
Program : Count the number of vowels in a given string.
Program No. : 072
Date : 20/02/2021
*******************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LEN 100

char *mem_alloc(int n);
void count(char *A,int *a);

void main()
{
    char *str;
    int i=0,v[5]={0};

    str = mem_alloc(LEN);
    printf("Enter any string :\n");
    gets(str);
    count(str,v);
    printf("Total vowels = %d\n",v[0]+v[1]+v[2]+v[3]+v[4]);
    printf("No. of A/a = %d\n",v[0]);
    printf("No. of E/e = %d\n",v[1]);
    printf("No. of I/i = %d\n",v[2]);
    printf("No. of O/o = %d\n",v[3]);
    printf("No. of U/u = %d\n",v[4]);
}

char *mem_alloc(int n)
{
    char *A;
    A = (char*)calloc(n,sizeof(char));
    return A;
}
void count(char *A,int *a)
{
    int i=0;
    while(A[i]!='\0')
    {
        if(A[i]=='A'||A[i]=='a')
            a[0]++;
        if(A[i]=='E'||A[i]=='e')
            a[1]++;
        if(A[i]=='I'||A[i]=='i')
            a[2]++;
        if(A[i]=='O'||A[i]=='o')
            a[3]++;
        if(A[i]=='U'||A[i]=='u')
            a[4]++;
        i++;
    }
}