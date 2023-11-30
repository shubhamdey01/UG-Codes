/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
			*	*	*	*	*	*	*
				*	*	*	*	*
					*	*	*
						*
					*	*	*
				*	*	*	*	*
			*	*	*	*	*	*	*	
Program No. : 045-11
Date : 2021.01.19
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j,x;
step1:
    printf("\nEnter number of lines :\t");
    scanf("%d",&n);
    if(n%2==0)  goto step1;
    x=(n+1)/2;
    for(i=0;i<x;i++)
    {
        for(j=0;j<i;j++)
            printf("   ");
        for(j=1;j<=x-i;j++)
            printf("*  ");
        for(j=1;j<x-i;j++)
            printf("*  ");
        printf("\n");
    }
    for(i=1;i<x;i++)
    {
        for(j=1;j<x-i;j++)
            printf("   ");
        for(j=0;j<=i;j++)
            printf("*  ");
        for(j=0;j<i;j++)
            printf("*  ");
        printf("\n");
    }
}