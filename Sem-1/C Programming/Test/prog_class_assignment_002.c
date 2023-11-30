#include<stdio.h>

/*
void main()
{
    int a,b,i,gcd;

    printf("Enter two numbers to find GCD :\n");
    scanf("%d %d",&a,&b);

    for(i=1; i<=a && i<=b; ++i)
    {
        if(a%i==0 && b%i==0)
            gcd = i;
    }
    printf("G.C.D of %d and %d is %d",a,b,gcd);
}
*/
void  main()
{
    int A,B,a,b,c;
    printf("Enter two numbers to find GCD :\n");
    scanf("%d %d",&A,&B);
    
    if (A>B) a=A, b=B;
    else a=B, b=A;
    {
    step1:
        c = a%b;
        if (c==0)
            printf("GCD of %d and %d is %d.",A,B,b);
        else
        {
            a = b, b = c;
            goto step1;
        }
    }   
}