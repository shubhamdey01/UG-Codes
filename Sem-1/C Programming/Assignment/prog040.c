/*********************************************
Name : Shubham Dey
Program : Find the HCF and LCM of two numbers.
Program No. : 040
Date : 10.01.2021
**********************************************/

#include<stdio.h>

void  main()
{
    int a,b,lcm,hcf;

    printf("Enter two numbers :\n");
    scanf("%d %d",&a,&b);

    if (a>b) lcm = a;
    else lcm = b;
    while(1)
    {
        if(lcm%a==0 && lcm%b==0)
            break;
        lcm++;
    }
    hcf = a*b/lcm;
    printf("HCF of %d and %d is %d\n",a,b,hcf);
    printf("LCM of %d and %d is %d",a,b,lcm);
}