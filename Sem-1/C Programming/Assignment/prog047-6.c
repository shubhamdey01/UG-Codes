/***************************************************************
Name : Shubham Dey
Program : Print the pattern by taking number of lines as input :
			                    1
			                1	1
			            1	2	1
			        1	3	3	1
			    1	4	6	4	1
			1	5	10	10	5	1
Program No. : 047-6
Date : 2021.01.21
****************************************************************/

#include<stdio.h>

void main()
{
    int n,i,j,a=1;
    printf("Enter number of lines :\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i;j++)
            printf("  ");
        for(j=0;j<=i;j++)
        {
            if(j==0 || i==0)
                a=1;
            else
                a=a*(i-j+1)/j;
            printf("%d ",a);
        }
        printf("\n");
    }
}