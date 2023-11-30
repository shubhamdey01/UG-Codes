#include <stdio.h>
// #include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("This is parent process\n");
	fork();
	printf("Hello World\n");
}