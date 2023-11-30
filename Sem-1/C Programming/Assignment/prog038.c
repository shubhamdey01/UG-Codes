/****************************************************************
Name : Shubham Dey
Program : Read a p-base number and find its q-base and vice-versa.
Program No. : 038
Date : 10.01.2021
*****************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int b1,b2,dec,i,x,r,n1,n2;

    printf("Enter base of the number :\t");
    scanf("%d",&b1);
    printf("Enter any number of base-%d :\t",b1);
    scanf("%d",&n1);
    printf("Enter convirsion base :\t");
    scanf("%d",&b2);

    dec=i=0;
    x=n1;
    while(x>=1)
    {
        r = x%10;
        dec += r*pow(b1,i);
        i++;
        x /= 10;
    }
    n2 = 0;
    i = 1;
    while(dec>=1)
    {
        r = dec%b2;
        n2 += r*i;
        i *= 10;
        dec /= b2;
    }

    printf("%d-base (%d) = %d-base (%d)\n",b1,n1,b2,n2);
}