/*******************************************************************
Name : Shubham Dey
Program : Find binary equivalent of a decimal number and vice-versa.
Program No. : 037
Date : 10.01.2021
********************************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
    int bin,dec,r,n,i,ch;
step1:
    printf("\n1. Binary to Decimal\n2. Decimal to Binary\n3. Exit\n");
    printf("Enter your choice :\t");
    scanf("%d",&ch);

    if(ch==1)
    {
        printf("\nEnter any binary number :\t");
        scanf("%d",&bin);
        n = bin;
        dec = i = 0;
        while(n>=1)
        {
            r = n%10;
            dec += r*pow(2,i);
            i++;
            n /= 10;
        }
        printf("binary(%d) = decimal(%d)\n",bin,dec);
        goto step1;
    }
    else if(ch==2)
    {
        printf("\nEnter any decimal number :\t");
        scanf("%d",&dec);
        n = dec;
        bin = 0;
        i = 1;
        while(n>=1)
        {
            r = n%2;
            bin += r*i;
            i *= 10;
            n /= 2;
        }
        printf("decimal(%d) = binary(%d)\n",dec,bin);
        goto step1;
    }
    else if(ch==3)
        printf("Thank You...\n");
    else
    {
        printf("\n!! INVALID CHOICE !!\n");
        goto step1;
    }
}