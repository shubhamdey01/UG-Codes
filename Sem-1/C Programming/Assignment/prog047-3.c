/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
			0	0	0	0	0
			1   1	1   1
			0	0	0
			1   1
			0
Program No. : 047-3
Date : 2021.01.21
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter number of lines :\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            if(i%2==0)
                printf("%d  ",1);
            else
                printf("%d  ",0);
        }
        printf("\n");
    }
}