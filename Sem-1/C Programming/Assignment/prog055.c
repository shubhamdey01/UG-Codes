/*******************************************************************************************
Name : Shubham Dey
Program : Write a program to check whether a number is product of consecutive numbers or not.
Program No. : 055
Date : 07/02/2021
********************************************************************************************/

#include<stdio.h>
#include<math.h>

int cons(int n,int i);

void main()
{
    int num,i,x=0,a;

    printf("Enter any number :\t");
    scanf("%d",&num);

    for(i=1;i<=num/2;i++)
    {
        a = cons(num,i);
        if(a)
        {
            printf("%d is product of consecutive numbers : ",num);
            for(x=i;x<=a;x++)
                printf("%d  ",x);
            printf("\n");
        }
    }
    if(!x)
        printf("%d is not a product of consecutive numbers.",num);
}

int cons(int n,int i)
{
    int j,p=1;
    for(j=i;j<=n/2;j++)
    {
        p *= j;
        if(p==n)
            return j;
        if(p>n)
            break;
    }
    return 0;
}