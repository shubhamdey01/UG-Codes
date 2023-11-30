#include <stdio.h>
#include <stdlib.h>
/* The following header files are for threads */
#include <pthread.h>
#include <bits/pthreadtypes.h>

typedef struct {
  int low, high;
  int div; 
} fparam_t;

void *pthread_ft(void *);

int main(int argc, char *argv[])
{
  pthread_t th1, th2;
  fparam_t par1, par2;
  int ret1, ret2;

  par1.low = atoi(argv[1]);
  par1.high = atoi(argv[2]);
  par1.div = atoi(argv[3]);
  par2.low = atoi(argv[4]);
  par2.high = atoi(argv[5]);
  par2.div = atoi(argv[6]);

  pthread_create(&th1, NULL, pthread_ft, (void *)&par1); 
  pthread_create(&th2, NULL, pthread_ft, (void *)&par2); 

  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
}


void *pthread_ft(void *args)
{
  fparam_t *ptr;
  int rem;

  ptr = (fparam_t *)args;

  if((rem=ptr->low % ptr->div) != 0)
    ptr->low = ptr->low + (ptr->div - rem); 

  while(ptr->low <= ptr->high)
  {
    ptr->low += ptr->div;
    printf("*********Thread id : %ld **************\n", pthread_self());
    printf("Next multiple of %d = %d\n", ptr->div, ptr->low);
  }
}
