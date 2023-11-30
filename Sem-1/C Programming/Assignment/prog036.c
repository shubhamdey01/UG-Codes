/***************************************************
Name : Shubham Dey
Program : Find all the armstrong numbers from 1 to N.
Program No. :  036
Date : 10.01.2021
****************************************************/

#include<stdio.h>

int armstrong(int n);

void  main()
{
    int i,N;
    printf("Enter N :\t");
    scanf("%d",&N);

    for(i=1; i<=N; i++)
        if (armstrong(i))
            printf("%d  ",i);
}

int armstrong(int n)
{
    int num,rem,sum=0;
    num = n;
    while(n>=1)
    {
        rem = n%10;
        sum += rem*rem*rem;
        n = n/10;
    }
    if(num==sum)
        return 1;
    return 0;
}