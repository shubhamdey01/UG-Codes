#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int pid,status;
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
		char *args[] = {"./exec1", NULL};
		execvp(args[0],args);
		printf("Ending.....\n");
		exit(0);
	}
	else
	{
		wait(&status);
		printf("\nParent process\n");
		printf("p pid : %d\n", getpid());
		printf("p parent's pid : %d\n", getppid());
		exit(0);
	}
}