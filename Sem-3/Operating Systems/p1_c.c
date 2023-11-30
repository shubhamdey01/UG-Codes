#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int status;
	int pid;
	printf("parent\n");
	pid = fork();
	if(pid<0)
	{
		printf("Error\n");
		exit(1);
	}
	else if(pid==0)
	{
		printf("Child process\n");
		printf("c pid : %d\n", getpid());
		printf("c parent's pid : %d\n", getppid());
		exit(0);
	}
	else
	{
		wait(&status);
		// sleep(5);
		printf("\nParent process\n");
		printf("p pid : %d\n", getpid());
		printf("p parent's pid : %d\n", getppid());
		exit(0);
	}
}