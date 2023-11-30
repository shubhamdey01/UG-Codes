// Program to write and read two messages through the pipe using the parent and child processes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd[2], status;
    char wmess[2][10] = {"Hello", "World"};
    char rmess[10];

    status = pipe(fd);
    if(status < 0)
        printf("Unable to create pipe.\n");

    if(!fork()) {
//      read(fd[0], rmess, 10);
//	printf("Child - Reading message-1 : %s\n",rmess);
//	read(fd[0], rmess, 10);
//	printf("Child - Reading message-1 : %s\n",rmess);

	printf("Child - Writing message-1 : %s\n", wmess[0]);
        write(fd[1], wmess[0], 10);
        printf("Child - Writing message-2 : %s\n", wmess[1]);
        write(fd[1], wmess[1], 10);


	exit(0);
    }
    else {
//	printf("Parent - Writing message-1 : %s\n", wmess[0]);
//	write(fd[1], wmess[0], 10);
//	printf("Parent - Writing message-2 : %s\n", wmess[1]);
//	write(fd[1], wmess[1], 10);

	read(fd[0], rmess, 10);
        printf("Parent - Reading message-1 : %s\n",rmess);
        read(fd[0], rmess, 10);
        printf("Parent - Reading message-1 : %s\n",rmess);
    }

    return 0;
}
