/****************************************************************************
Name : Shubham Dey
Program : Find the sum of the series : 1 - x^2/2! + x^4/4! - ... (+/-) x^n/n!
Program No. : 027-c
Date : 2021.01.05
*****************************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int x,n,i,j,k=1;
    long int fact=1;
    float sum=1;

    printf("Enter the value of x :\n");
    scanf("%d",&x);
step1:
    printf("Enter the value of n (even) :\n");
    scanf("%d",&n);
    if(n%2!=0)  goto step1;

    for(i=2; i<=n; i+=2)
    {
        fact *= i;
        if(k%2==0)
            sum += (float)pow(x,i)/fact;
        else
            sum -= (float)pow(x,i)/fact;
        k++;
    }
    printf("Sum of the series : ");
    if(n==0)
        printf("1 = %f",sum);
    else if(n==2)
        printf("1 - %d^2/2! = %f",x,sum);
    else if(n==4)
        printf("1 - %d^2/2! + %d^4/4! = %f",x,x,sum);
    else if(n==6)
        printf("1 - %d^2/2! + %d^4/4! - %d^6/6! = %f",x,x,x,sum);
    else
    {
        if(k%2==0)
            printf("1 - %d^2/2! + %d^4/4! - ... - %d^%d/%d! = %f",x,x,x,n,n,sum);
        else
            printf("1 - %d^2/2! + %d^4/4! - ... + %d^%d/%d! = %f",x,x,x,n,n,sum);
    }
}