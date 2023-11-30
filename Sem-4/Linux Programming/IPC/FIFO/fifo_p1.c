#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#ifndef FIFO_EXIST
#define FILE_MODE (S_IRUSR | S_IWUSR)
#define FIFO1 "tathagato.fifo.1"
#define FIFO2 "tathagato.fifo.2"
#else
#define FIFO1 argv[1]
#define FIFO2 argv[2]
#endif

int main(int argc, char *argv[])
{
  int readfd, writefd;
  pid_t child_pid;
  char buff[10];
  int n, i, num_elmt;

  printf("%x %x %x\n", S_IRUSR, S_IWUSR, S_IXUSR);
  printf("%x %x %x\n", S_IRGRP, S_IWGRP, S_IXGRP);
  printf("%x %x %x\n", S_IROTH, S_IWOTH, S_IXOTH);
#ifndef FIFO_EXIST
  /* Create two FIFOs; OK if they already exist */
  if ((mkfifo(FIFO1, FILE_MODE) < 0) && errno != EEXIST)
    printf("Can't create %s\n", FIFO1);
  else
    printf("FIFO1 created\n");

  if ((mkfifo(FIFO2, FILE_MODE) < 0) && errno != EEXIST)
  {
    unlink(FIFO1);
    printf("Can't create %s\n", FIFO2);
  }
  else
    printf("FIFO2 created\n");
#endif
  

  /* IMPORTANT TO REMEMBER : Order of opening the file descriptors should be 
     opposite in parent and child. E.g if parent opens the fd for READ followed 
     by fd for WRITE, the child has to open fd for WRITE followed by READ. 
     Otherwise, open fd for READ blocks unless the same fd is already open'ed 
     for WRITE. If the order is same, both parent and child can get into a 
     deadlock. */
  printf("Process 1 ..");
  fflush(stdout);
  writefd = open(FIFO2, O_WRONLY, 0); 
  if(writefd <= 0)
    printf("FIFO2 could not be opened\n");
  else
    printf("FIFO2 opened writeonly\n");
  fflush(stdout);
  readfd = open(FIFO1, O_RDONLY, 0);
  if(readfd <= 0)
    printf("FIFO2 could not be opened \n");
  else
    printf("FIFO1 opened readonly\n");
  printf("Process 1 : FIFO1 for READONLY, FIFO2 for WRITEONLY\n");

  if((n=read(readfd, &num_elmt, sizeof(int))) > 0)
  {
    printf("Buff content updated by P1 :\n");
    
    for(i=0; i<num_elmt; i++)
    {
      buff[i] = 10*i;
      printf("%d  ", buff[i]);
    }
    printf("\n");
  }

  write(writefd, buff, num_elmt);
}
