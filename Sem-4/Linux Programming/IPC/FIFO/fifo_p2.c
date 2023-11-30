#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#ifndef FIFO_EXIST
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
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

  /* IMPORTANT TO REMEMBER : Order of opening the file descriptors should be 
     opposite in parent and child. E.g if parent opens the fd for READ followed 
     by fd for WRITE, the child has to open fd for WRITE followed by READ. 
     Otherwise, open fd for READ blocks unless the same fd is already open'ed 
     for WRITE. If the order is same, both parent and child can get into a 
     deadlock. */
  printf("Process 2 ..\n");
  readfd = open(FIFO2, O_RDONLY, 0);
  printf("FIFO2 opened readonly\n");
  writefd = open(FIFO1, O_WRONLY, 0); 
  printf("FIFO1 opened writeonly\n");

  printf("Process 2 : FIFO2 for READONLY, FIFO1 for WRITEONLY\n");
  printf("Give number of elements to be updated by child :\n");
  scanf("%d", &num_elmt);

  printf("Before reading from FIFO, buff content in parent is :\n");
  for(i=0; i<num_elmt; i++)
  {
    buff[i] = 0;
    printf("%d  ", buff[i]);
  }
  printf("\n");


  printf("Process 2 sends num_elmt = %d to child \n", num_elmt);
  write(writefd, &num_elmt, sizeof(int));

  if((n=read(readfd, buff, num_elmt)) > 0)
  {
    printf("Updated buff content in process 2 after FIFO read : \n");
    for(i=0; i<num_elmt; i++)
      printf("%d  ", buff[i]);
    printf("\n");
  }
 
}
