#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  int pipe1[2]; /* pipe1[0] for reading, pipe1[1] for writing */
  pid_t child_pid;
  char buff[10];
  int n, i, j, idle_pipe = 0;

  /* Create a pipe for parent-child communication */
  pipe(pipe1);
 
  /* Making the read descriptor non-blocking, so that the process reading
     the descriptor does not block on it. */
  if (fcntl(pipe1[0], F_SETFL, O_NONBLOCK) < 0)
        exit(2);

  if(child_pid=fork() == 0)
  {
    close(pipe1[0]); /* Pipe closed for reading by child */
    
    for(j = 0; j < 5; j++)
    {
      printf("Buff content updated by child :\n");
      for(i=0; i<10; i++)
      {
        buff[i] = j*10 + i;
        printf("%d  ", buff[i]);
      }
      printf("\n");
    
      write(pipe1[1], buff, 10);
    
      sleep(1);
    }
   
    exit(0);
  }
  else
  {
    close(pipe1[1]); /* Pipe closed for writing by parent */
    printf("Before reading from pipe, buff content in parent is :\n");
    for(i=0; i<10; i++)
    {
      buff[i] = 0;
      printf("%d  ", buff[i]);
    }
    printf("\n");

    /* As the read is non blocking, the read call should be made within a loop,
    where most of the time the pipe would be empty; and the read would return 
    -1 with an error = EAGAIN. If
    the return value = 0, it would mean end of transmission. If return value is
    positive, it would mean there is data in the pipe. */
    while(1)
    {
      n=read(pipe1[0], buff, 10);

      if(n == 0)
      { /* End of transmission */
        printf("End of Tx\n"); 
        break;
      }

      else if(n > 0)
      { /* There is data in the pipe */
        printf("Updated buff content in parent after %dth idle pipe read : \n", idle_pipe);
        for(i=0; i<10; i++)
          printf("%d  ", buff[i]);
        printf("\n");
        idle_pipe = 0;
      }
      else if (n < 1)
      {
        if(errno == EAGAIN) /* There is no data in the pipe yet. Need to try 
                               reading again. */
          idle_pipe ++;
        else
          exit(4); /* Some other error */
      }
    }
 
    waitpid(child_pid, NULL, 0); /* Wait for termination of child */
    
    exit(0);
  }
}
