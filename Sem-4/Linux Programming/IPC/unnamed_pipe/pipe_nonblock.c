#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int pipe1[2]; /* pipe1[0] for reading, pipe1[1] for writing */
  pid_t child_pid;
  char buff[10];
  int n, i;

  /* Create a pipe for parent-child communication */
  pipe(pipe1);

  if(child_pid=fork() == 0)
  {
    close(pipe1[0]); /* Pipe closed for reading by child */
    printf("Buff content updated by child :\n");
    for(i=0; i<10; i++)
    {
      buff[i] = 10*i;
      printf("%d  ", buff[i]);
    }
    printf("\n");
    
    write(pipe1[1], buff, 10);
   
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

    if((n=read(pipe1[0], buff, 10)) > 0)
    {
      printf("Updated buff content in parent after pipe read : \n");
      for(i=0; i<10; i++)
        printf("%d  ", buff[i]);
      printf("\n");
    }
 
    waitpid(child_pid, NULL, 0); /* Wait for termination of child */
    
    exit(0);
  }
}
