/*************************************************************************
Name : Shubham Dey
Program : Sort n words in lexiographic order. Display unsorted and sorted list.
Program No. : 070
Date : 18/02/2021
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

char **mem_alloc(int p);
void input(int p,char **A);
void display(int p,char **A);
void lg_sort(int p,char **A);

void main()
{
    int n;
    char **txt;

    printf("Enter number of words :\t");
    scanf("%d",&n);

    txt = mem_alloc(n);
    input(n,txt);
    printf("\nUnsorted list :\n");
    display(n,txt);
    lg_sort(n,txt);
    printf("\nSorted list :\n");
    display(n,txt);
}

char **mem_alloc(int p)
{
    int i;
    char **A;
    A = (char**)calloc(p,sizeof(char*));
    if(A==NULL)
    {
        printf("Memory not allocated.");
        exit(1);
    }
    for(i=0;i<p;i++)
    {    A[i] = (char*)calloc(MAX,sizeof(char));
        if(A[i]==NULL)
        {
            printf("Memory not allocated.");
            exit(1);
        }
    }
    return A;
}
void input(int p,char **A)
{
    int i;
    for(i=0;i<p;i++)
    {
    step1:
        printf("Enter word[%d] =\t",i+1);
        scanf("%s",A[i]);
        if(strlen(A[i])>MAX)
        {
            printf("Plese enter word of specified length.\n");
            goto step1;
        }
    }
}
void display(int p,char **A)
{
    int i,j;
    for(i=0;i<p;i++)
        printf("%s   ",A[i]);
    printf("\n");
}
void lg_sort(int p,char **A)
{
    int i,j;
    char *temp;
    temp = (char*)calloc(MAX,sizeof(char));
    for(i=0;i<p-1;i++)
        for(j=i+1;j<p;j++)
            if(strcmp(A[i],A[j])>0)
            {
                strcpy(temp,A[i]);
                strcpy(A[i],A[j]);
                strcpy(A[j],temp);
            }
}