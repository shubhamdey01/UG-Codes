/***************************************************
Name : Shubham Dey
Program : Multiply 1st N natural numbers recursively
Program No. : 008
Date : 14.03.2022
***************************************************/

#include<stdio.h>

int mul(int n);

int main()
{
	int n, p;

	printf("Enter n :\t");
	scanf("%d",&n);

	p = mul(n);

	printf("Product of 1st %d natural numbers = %d\n",n,p);
}

int mul(int n)
{
	if(n==1)
		return 1;
	return (n * mul(n-1));
}