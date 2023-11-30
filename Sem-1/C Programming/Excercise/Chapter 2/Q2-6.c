/*****************************************************************************************************
Name : Shubham Dey
Program : Count and Print the number of negative and positive numbers in a given set of numbers.
          Use scanf to read the numbers. Reading should be terminated when the value 0 is encountered.
Program No. : 2.6
******************************************************************************************************/

#include<stdio.h>

void main()
{
    int po=0,ne=0,n;

    printf("Enter +ve or -ve numbers.\nEnter 0 to terninate.\n\n");
    while(1)
    {
        scanf("%d",&n);
        if(n!=0)
        {
            if(n>0)
                po++;
            else if(n<0)
                ne++;
        }
        else
        {
            printf("Positive numbers entered = %d\n",po);
            printf("Negetive numbers entered = %d\n",ne);
            break;
        }
    }
}