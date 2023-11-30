/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
			0
            1   0
            0   1   0
            1   0   1   0
            0   1   0   1   0
Program No. : 047-1
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
        for(j=1;j<=i;j++)
        {
            if((i+j)%2==0)
                printf("%d  ",0);
            else
                printf("%d  ",1);
        }
        printf("\n");
    }
}