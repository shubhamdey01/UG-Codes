// Program to perform two-way communication between two processes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define N 25
#define FIFO "myfifo1"
#define PERM (S_IRUSR | S_IWUSR)

int table(int);

int main() {
    int fd;
    int msg;

    mkfifo(FIFO, PERM);

    while(1) {
	    fd = open(FIFO, O_RDONLY);
		read(fd, &msg, sizeof(int));
		printf("Process-1 - Reading message : %d\n",msg);
		close(fd);

		if(msg == 15) {
		    msg = table(msg);
		    break;
		}
		msg = table(msg);
	    fd = open(FIFO, O_WRONLY);
		printf("Process-1 - Writing message : %d\n", msg);
		write(fd, &msg, sizeof(int));
	    close(fd);
		sleep(1);
    }

    return 0;
}

int table(int n) {\
    int i;
    for(i=1; i<=10; i++)
	printf("%d X %d = %d\n",n,i,n*i);
    printf("\n");
    return n*i;
}
