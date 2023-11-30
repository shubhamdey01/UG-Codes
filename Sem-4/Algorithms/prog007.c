/***********************************************
Name : Shubham Dey
Program : Add 1st N natural numbers recursively
Program No. : 007
Date : 14.03.2022
***********************************************/

#include<stdio.h>

int sum(int n);

int main()
{
	int n, s;

	printf("Enter n :\t");
	scanf("%d",&n);

	s = sum(n);

	printf("Sum of 1st %d natural numbers = %d\n",n,s);
}

int sum(int n)
{
	if(n==1)
		return 1;
	return (n + sum(n-1));
}