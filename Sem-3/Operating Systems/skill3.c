#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void forkexample()
{
	int x = 1;
	if(fork()==0)
		printf("child x = %d\n",++x);
	else
		printf("parent x = %d\n",--x);
}

int main()
{
	forkexample();
	return 0;
}