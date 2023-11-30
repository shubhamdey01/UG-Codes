/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
           *  *  *  *
              *  *  *
                 *  *
                    * 
Program No. : 045-4
Date : 2021.01.18
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter number of lines :\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            printf("   ");
        for(j=0;j<n-i;j++)
            printf("*  ");
        printf("\n");
    }
}