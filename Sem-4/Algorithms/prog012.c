/**************************************
Name : Shubham Dey
Program : Calculate GCD using recursion
Program No. : 012
Date : 28.03.2022
**************************************/

#include <stdio.h>

int gcd(int a, int b);

int main()
{
	int x,y;

	printf("Enter the numbers :\n");
	scanf("%d %d",&x,&y);

	printf("GCD of %d and %d is %d\n",x,y,gcd(x,y));
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}