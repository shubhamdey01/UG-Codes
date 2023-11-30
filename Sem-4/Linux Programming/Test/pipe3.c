// Achieving two way communication using pipes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd1[2], fd2[2];
    char wmess[2][10] = {"Hello", "World"};
    char rmess[10];

    if(pipe(fd1) < 0) {
	printf("Unable to create pipe-1.\n");
	exit(1);
    }
    if(pipe(fd2) < 0) {
        printf("Unable to create pipe-2.\n");
	exit(1);
    }

    if(!fork()) {
	close(fd1[0]);
	close(fd2[1]);
	printf("Child - Writing message : %s\n", wmess[0]);
	write(fd1[1], wmess[0], 10);
	read(fd2[0], rmess, 10);
	printf("Child - Reading message : %s\n", rmess);

	exit(0);
    }
    else {
	close(fd1[1]);
	close(fd2[0]);
	printf("Parent - Writing Message : %s\n", wmess[1]);
	write(fd2[1], wmess[1], 10);
	read(fd1[0], rmess, 10);
	printf("Parent - Reading message : %s\n", rmess);
    }

    return 0;
}
