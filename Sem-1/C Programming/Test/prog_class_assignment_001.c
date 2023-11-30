// Class Assignment (06.01.2021)
// LCM

#include<stdio.h>

void  main()
{
    int A,B,x;

    printf("Enter two numbers to find LCM :\n");
    scanf("%d %d",&A,&B);

    if (A>B) x = A;
    else x = B;
    while(1)
    {
        if(x%A==0 && x%B==0)
        {
            printf("LCM of %d and %d is %d",A,B,x);
            break;
        }
        x++;
    }  
}