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
    int fd1;
    char msg[N];

    mkfifo(FIFO, PERM);
    fd1 = open(FIFO, O_WRONLY);

    while(1) {
	printf("Enter : ");
	scanf("%s", msg);
        printf("Process-2 - Writing message : %s\n",msg);
	write(fd1, msg, N);

	if(!strcmp(msg, "end")) {
	    close(fd1);
	    break;
	}
    }

    return 0;
}
