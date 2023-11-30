/********************************************************************************
Name : Shubham Dey
Program : Find the sum of the series : 1 + x - x^2/2! + x^3/3! - ... (+/-) x^n/n!
Program No. : 027-e
Date : 2021.01.05
*********************************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int x,n,i;
    long int fact;
    float sum=1;

    printf("Enter the values of x and n :\n");
    scanf("%d %d",&x,&n);

    for(i=1; i<=n; i+=2)
    {
        fact *= i;
        if(i%2==0)
            sum -= (float)pow(x,i)/fact;
        else
            sum += (float)pow(x,i)/fact;
    }
    printf("Sum of the series : ");
    if(n==0)
        printf("1 = %f",sum);
    else if(n==1)
        printf("1 + %d = %f",x,sum);
    else if(n==2)
        printf("1 + %d - %d^2/2! = %f",x,x,sum);
    else if(n==3)
        printf("1 + %d - %d^2/2! + %d^3/3! = %f",x,x,x,sum);
    else if(n==4)
        printf("1 + %d - %d^2/2! + %d^3/3! - %d^4/4! = %f",x,x,x,x,sum);
    else
    {
        if(n%2==0)
            printf("1 + %d - %d^2/2! + %d^3/3! - ... - %d^%d/%d! = %f",x,x,x,x,n,n,sum);
        else
            printf("1 + %d - %d^2/2! + %d^3/3! - ... + %d^%d/%d! = %f",x,x,x,x,n,n,sum);
    }
}