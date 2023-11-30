#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	pid_t pid,p;
	p = fork();
	pid = getpid();
	if(p<0)
	{
		fprintf(stderr,"Fork Failed");
		return 1;
	}
	printf("Output of fork id : %d\nProcess id is : %d\n",p,pid);
	return 0;
}