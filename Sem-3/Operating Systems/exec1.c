#include <stdio.h>
#include <unistd.h>

int main()
{
	int n;
	printf("I am exec1.c called by execvp()\n");
	printf("Please enter an integer :\t");
	scanf("%d",&n);
	printf("The value you entered is %d\n",n);
	return 0;
}