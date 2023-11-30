/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
                1	1	1	1	1	1	1
                    2	2	2	2	2
                        3	3	3
                            4
                        3	3	3
                    2	2	2	2	2
                1	1	1	1	1	1	1
Program No. : 046-11
Date : 2021.01.20
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
    for(i=1;i<=x;i++)
    {
        for(j=1;j<i;j++)
            printf("   ");
        for(j=0;j<=x-i;j++)
            printf("%d  ",i);
        for(j=0;j<x-i;j++)
            printf("%d  ",i);
        printf("\n");
    }
    for(i=1;i<x;i++)
    {
        for(j=1;j<x-i;j++)
            printf("   ");
        for(j=0;j<=i;j++)
            printf("%d  ",x-i);
        for(j=0;j<i;j++)
            printf("%d  ",x-i);
        printf("\n");
    }
}