/**********************************************
Name : Shubham Dey
Program : Print multiplication table for 1 to n.
Program No. : 044
Date : 10.01.2021
***********************************************/

#include<stdio.h>

void main()
{
    int n,i,j;

    printf("Enter n :\t");
    scanf("%d",&n);

    for(i=1;i<=10;i++)
    {
        for(j=1;j<=n;j++)
            printf("%dX%d=%d\t",j,i,i*j);
        printf("\n");
    }
}