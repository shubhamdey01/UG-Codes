/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
		    1	1	1	1	1
				0	0	0	0
					1	1	1
						0	0
							1
Program No. : 046-4
Date : 2021.01.19
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j;
    printf("Enter number of lines :\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
            printf("   ");
        for(j=0;j<=n-i;j++)
        {
            if(i%2==0)
                printf("%d  ",0);
            else
                printf("%d  ",1);
        }
        printf("\n");
    }
}