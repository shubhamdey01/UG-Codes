/*****************************************************
Name : Shubhan Dey
Program : Check whether a number is Prime or Composite.
Program No. : 016
Date : 2020.12.02
******************************************************/

#include<stdio.h>
#include <math.h>

void main()
{
    int N,i;
    
    printf("Enter a number :\t");
    scanf("%d",&N);

    for(i=2;i<=(int)sqrt(N);i++)
    {
    	if (N%i==0)
    	{
    		printf("%d is a Composite Number.\n",N);
    		break;
    	}
    }
    if (i==(int)sqrt(N)+1)
    	printf("%d is a Prime Number.\n",N);
}