/**************************************************************
Name : Shubham Dey
Program : Find the HCF and LCM of n numbers without using array.
Program No : 041
Date : 10.01.2021
***************************************************************/

#include<stdio.h>

int LCM(int a,int b);
int HCF(int a,int b);

void main()
{
    int n,x1,y1,x2,y2,i=2,l,h;

    printf("How many numbers ?\t");
    scanf("%d",&n);
    printf("Enter %d numbers :\n",n);
    scanf("%d %d",&x1,&y1);
    x2=x1, y2=y1;
    while(i<=n)
    {
        l = LCM(x1,y1);
        h = HCF(x2,y2);
        if(i!=n)
        {
            x1 = l;
            x2 = h;
            scanf("%d",&y1);
            y2 = y1;
        }
        i++;
    }
    printf("LCM = %d\tHCF = %d",l,h);
}

int LCM(int a,int b)
{
    int lcm;
    if (a>b) lcm = a;
    else lcm = b;
    while(1)
    {
        if(lcm%a==0 && lcm%b==0)
            break;
        lcm++;
    }
    return lcm;
}

int HCF(int a,int b)
{
    int lcm,hcf;
    lcm = LCM(a,b);
    hcf = a*b/lcm;
    return hcf;
}