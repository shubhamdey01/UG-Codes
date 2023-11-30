/****************************************************************************
Name : Shubham Dey
Program : Find the sum of the series : x - x^3/3! + x^5/5! - ... (+/-) x^n/n!
Program No. : 027-d
Date : 2021.01.05
*****************************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int x,n,i,j,k=1;
    long int fact;
    float sum=0;

    printf("Enter the value of x :\n");
    scanf("%d",&x);
step1:
    printf("Enter the value of n (odd) :\n");
    scanf("%d",&n);
    if(n%2==0)  goto step1;

    for(i=1; i<=n; i+=2)
    {
        fact *= i;
        if(k%2==0)
            sum -= (float)pow(x,i)/fact;
        else
            sum += (float)pow(x,i)/fact;
        k++;
    }
    printf("Sum of the series : ");
    if(n==1)
        printf("%d = %f",x,sum);
    else if(n==3)
        printf("%d - %d^3/3! = %f",x,x,sum);
    else if(n==5)
        printf("%d - %d^3/3! + %d^5/5! = %f",x,x,x,sum);
    else if(n==7)
        printf("%d - %d^3/3! + %d^5/5! - %d^7/7! = %f",x,x,x,x,sum);
    else
    {
        if(k%2==0)
            printf("%d - %d^3/3! + %d^5/5! - ... + %d^%d/%d! = %f",x,x,x,x,n,n,sum);
        else
            printf("%d - %d^3/3! + %d^5/5! - ... - %d^%d/%d! = %f",x,x,x,x,n,n,sum);
    }
}