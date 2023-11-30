/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
                1						1
                2	2				2	2
                3	3	3		3	3	3
                4	4	4	4	4	4	4
Program No. : 046-6
Date : 2021.01.20
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter number of lines :\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
            printf("%d  ",i);
        for(j=1;j<2*(n-i);j++)
            printf("   ");
        for(j=0;j<i;j++)
        {
            if(j!=n-1)
                printf("%d  ",i);
        }
        printf("\n");
    }
}