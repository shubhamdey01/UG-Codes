/***************************************************************
Name : Shubham Dey
Program : Illustrate the use of typedef declaration in a program.
Program No. : 2.9
*****************************************************************/

#include<stdio.h>

void main()
{
    typedef char name;
    name first[15],last[10];

    printf("Enter your first name :\t");
    scanf("%s",&first);
    printf("Enter your last name :\t");
    scanf("%s",&last);
    printf("Your name is : %s %s",first,last);
}