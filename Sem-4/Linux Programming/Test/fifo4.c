// Program to perform two-way communication between two processes.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO "myfifo1"
#define PERM (S_IRUSR | S_IWUSR)

int main() {
    int fd1;
    int msg;

    mkfifo(FIFO, PERM);

    while(1) {
		printf("Enter : ");
		scanf("%d",&msg);
    	fd1 = open(FIFO, O_WRONLY);
	    printf("Process-2 - Writing message : %d\n",msg);
		write(fd1, &msg, sizeof(int));
		close(fd1);

		if(msg == 15)
		    break;
		// sleep(2);

    	fd1 = open(FIFO, O_RDONLY);
		read(fd1, &msg, sizeof(int));
		printf("Process-2 - Reading message : %d\n", msg);
		close(fd1);
    }

    return 0;
}
