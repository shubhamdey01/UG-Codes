#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  pid_t child_pid;
  char buff[10], c;
  int n, i;
  unsigned int loc;

  for(i=0; i<10; i++)
    buff[i] =i;

  if(child_pid=fork() == 0)
  {
    printf("Hit a key to update content in child :\n");
    c = getchar();
    loc = (unsigned int)buff;
    printf("Updated buff content of location %x in child:\n", loc);
    for(i=0; i<10; i++)
    {
      buff[i] = 10*i;
      printf("%d  ", buff[i]);
    }
    printf("\n");
    exit(0);
  }
  else
  {
    loc = (unsigned int)buff;
    printf("Buff content of location %x in parent before updation by child :\n", loc);
    for(i=0; i<10; i++)
      
      printf("%d  ", buff[i]);
    printf("\n");
    
    waitpid(child_pid, NULL, 0); /* Wait for termination of child */

    loc = (unsigned int)buff;
    printf("Buff content of location %x in parent after updation in child \n", loc);
    for(i=0; i<10; i++)
      printf("%d  ", buff[i]);
    printf("\n");

    exit(0);
  }
}
