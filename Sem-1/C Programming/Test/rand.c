#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void main()
{
    int array[25],i,temp,index; 

    for (i = 0; i < 25; i++) 
        array[i] = i+1;
    for (i = 0; i < 25; i++)
    {
        srand(time(0));
        index = rand() % 25;
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
    for (int i = 0; i < 22; i++) 
        printf("%d,",array[i]);
    printf("\n");
}