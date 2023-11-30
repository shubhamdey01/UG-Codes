/**********************************************************
Name : Shubham Dey
Program : Given values of a,b and c. Display x = a/(b-c)
Program No. : 1.8
**********************************************************/

#include<stdio.h>

void main()
{
    int a,b,c;
    float x;

    printf("Enter the values of a, b, c :\n");
    scanf("%d %d %d",&a,&b,&c);
    if (b-c==0) printf("ERROR : Divisor = b-c = 0\n");
    else
    {
        x = a/(b-c);
        printf("%f",x);
    }
}