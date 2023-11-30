#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int a = 100;
	if(fork()==0)
	{
		a = a + 5;
		printf("%d, %p\n",a,&a);
	}
	else
	{
		a = a - 5;
		printf("%d, %p\n",a,&a);
	}
	return 0;
}