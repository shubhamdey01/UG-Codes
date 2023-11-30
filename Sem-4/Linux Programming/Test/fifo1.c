// Program to perform one-way communication between two processes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define N 25
#define FIFO "myfifo"
#define PERM (S_IRUSR | S_IWUSR)

int main() {
    int fd;
    char msg[N];

    mkfifo(FIFO, PERM);

    while(1) {
	fd = open(FIFO, O_RDONLY);
	read(fd, msg, N);
	printf("Process-1 - Reading message : %s\n",msg);
	close(fd);
	if(!strcmp(msg, "end"))
	    break;
    }

    return 0;
}
