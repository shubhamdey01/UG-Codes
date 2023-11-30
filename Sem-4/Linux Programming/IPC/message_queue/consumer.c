#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <mqueue.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int agrc, char *argv[])
{
  mqd_t mqd;
  struct mq_attr attr;
  char *ptr;
  size_t len;
  unsigned int prio;
  int i;

  mqd = mq_open(argv[1], O_RDONLY);

  // mq_getattr(mqd, &attr);
  // ptr = (char *)calloc(attr.mq_msgsize, sizeof(char));

  while(1)
  {
    mq_getattr(mqd, &attr);
    ptr = (char *)calloc(attr.mq_msgsize, sizeof(char));
    printf("Num messages in the queue = %ld\n", attr.mq_curmsgs);
    if(attr.mq_curmsgs == 0)
      break;
    len = mq_receive(mqd, ptr, attr.mq_msgsize, &prio);
    printf("Read %d bytes, priority = %d from message queue\n", len, prio);
    for(i=0; i<len; i++)
    {
      printf("%d  ", ptr[i]);
    }
    printf("\n");
    free(ptr);
    sleep(1);
    // mq_getattr(mqd, &attr);
  }
}
