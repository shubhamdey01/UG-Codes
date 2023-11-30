/**************************************************
Name : Shubham Dey
Program : Surface Area & Volume of - Cuboid & Cube.
Program No. : 007
Date : 2020.12.07
***************************************************/

#include<stdio.h>

void main()
{
    int ch;
    float l,b,h,SA,V;

step1:
    printf("\n1. Surface area and Volume of Cuboid.\n2. Surface area and Volume of Cube.\n3. Exit.\n");
    printf("Enter your choice :\n");
    scanf("%d",&ch);

    if (ch==1)  // Surface area and Volume of Cuboid.
    {
        printf("Enter length, breadth and height of the cuboid :\n");
        scanf("%f %f %f",&l,&b,&h);
        SA = 2*(l*b+b*h+h*l);
        V = l*b*h;
        printf("Surface Area = %f\tand\tVolume = %f\n",SA,V);
        goto step1;
    }
    else if (ch==2) // Surface area and Volume of Cube.
    {
        printf("Enter length of a side of the cube :\n");
        scanf("%f",&l);
        SA = 6*l*l;
        V = l*l*l;
        printf("Surface Area = %f\tand\tVolume = %f\n",SA,V);
        goto step1;
    }
    else if (ch==3) // Exit
        printf("Thank You...\n");
    else
    {
        printf("Invalid choice.\n");
        goto step1;
    }
}