#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc>1)
		argv[argc] = NULL;
	execvp(argv[1],&argv[1]);
	printf("Ending.....\n");
	return 0;
}