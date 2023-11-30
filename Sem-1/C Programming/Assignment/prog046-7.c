/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
                4	4	4	4	4	4	4
                    3	3	3	3	3
                        2	2	2
                            1
Program No. : 046-7
Date : 2021.01.20
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
        for(j=1;j<=n-i;j++)
            printf("%d  ",n-i);
        for(j=1;j<n-i;j++)
            printf("%d  ",n-i);
        printf("\n");
    }
}