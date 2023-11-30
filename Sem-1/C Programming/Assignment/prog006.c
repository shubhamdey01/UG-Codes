/**********************************************************
Name : Shubham Dey
Program : Perimeter & Area of - Rectangle, Square & Circle.
Program No. : 006
Date : 2020.12.07
***********************************************************/

#include<stdio.h>

void main()
{
    int ch;
    float l,b,peri,ar;

step1:
    printf("\n1. Perimeter & Area of Rectangle.\n2. Perimeter & Area of Square.\n3. Perimeter & Area of Circle.\n4. Exit.\n");
    printf("Enter your choice :\n");
    scanf("%d",&ch);

    if (ch==1)  // Perimeter & Area of Rectangle.
    {
        printf("Enter length and breadth of the rectangle :\n");
        scanf("%f %f",&l,&b);
        peri = 2*(l+b);
        ar = l*b;
        printf("Perimeter = %f\tand\tArea = %f\n",peri,ar);
        goto step1;
    }
    else if (ch==2) // Perimeter & Area of Square.
    {
        printf("Enter length of a side of the square :\n");
        scanf("%f",&l);
        peri = 4*l;
        ar = l*l;
        printf("Perimeter = %f\tand\tArea = %f\n",peri,ar);
        goto step1;
    }
    else if (ch==3) // Perimeter & Area of Circle.
    {
        printf("Enter radius of the circle :\n");
        scanf("%f",&l);
        peri = 2*(22./7)*l;
        ar = (22./7)*l*l;
        printf("Perimeter = %f\tand\tArea = %f\n",peri,ar);
        goto step1;
    }
    else if (ch==4) // Exit
        printf("Thank You...\n");
    else
    {
        printf("Invalid choice.\n");
        goto step1;
    }
}