#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void forkexample()
{
	int i,n=4,pid,status;
	for (i=1; i<=n; i++)
	{
		pid = fork();
		if(pid==0)
		{
			//sleep(2);
			printf("hello from child\n");
			printf("my pid is %d\n",getpid());
		}
		else
			wait(&status);
	}
}

int main()
{
	forkexample();
	return 0;
}