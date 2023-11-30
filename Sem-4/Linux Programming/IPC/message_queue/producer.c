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
  int i, j, num_post;

  mqd = mq_open(argv[1], O_WRONLY | O_CREAT, FILE_MODE, NULL);
  len = atoi(argv[2]);
  num_post = atoi(argv[3]);

  mq_getattr(mqd, &attr);
  printf("max #msgs = %d, max #bytes/msg = %d, #currently on queue = %d\n", attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

  ptr = (char *)calloc(len, sizeof(char));

  for(j=0; j<num_post; j++)
  {
    printf("Buffer content written by server is :\n");
    for(i=0; i<len; i++)
    {
      ptr[i] = 10*(j*len+i);
      printf("%d  ", ptr[i]);
    }
    printf("\n");
    
    prio = num_post - j;

    mq_send(mqd, ptr, len, prio);
    printf("Buffer sent through message Q with priority = %d\n", prio);

    sleep(1);
  }
}

