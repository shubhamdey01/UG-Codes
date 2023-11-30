/***************************************************************
Name : Shubham Dey
Program : Convert days to years, months and days and vice-versa.
Program No. : 010
Date : 2020.12.07
****************************************************************/

#include<stdio.h>

int main()
{
   	int ch,days,ndays,yy,mm,dd;

step1:
	printf("\n1. Days to years, months, days.\n2. Years, months, days to days.\n3. Exit.\n");
	printf("Enter your choice :\n");
    scanf("%d",&ch);

	if (ch==1)		// Days to years, months, days.
	{
		printf("Enter number of days :\t");
		scanf("%d",&days);
		ndays = days;
		yy = (int)ndays/365;
		ndays -= (365*yy);
		mm = (int)ndays/30;
		dd = (int)ndays - (mm*30);

		printf("%d  days  =  ",days);

		if (yy==1)  printf("%d year",yy);
		else if (yy>1)  printf("%d years",yy);

		if (mm==1)  printf("  %d month",mm);
		else if (mm>1)  printf("  %d months",mm);

		if (dd==1)  printf("  and  %d day.\n",dd);
		else if (dd>1)  printf("  and  %d days.\n",dd);

		goto step1;
	}
	else if (ch==2)	// Years, months, days to days.
	{
		printf("Enter year(s), month(s) and day(s) :\n");
		scanf("%d %d %d",&yy,&mm,&dd);
		days = yy*365 + mm*30 + dd;

		if (yy==1)  printf("%d year",yy);
		else if (yy>1)  printf("%d years",yy);

		if (mm==1)  printf("  %d month",mm);
		else if (mm>1)  printf("  %d months",mm);

		if (dd==1)  printf("  and  %d day",dd);
		else if (dd>1)  printf("  and  %d days",dd);

		printf("  =  %d  days.\n",days);
		goto step1;
	}
	else if (ch==3)	// Exit
		printf("Thank You...\n");
	else
	{
		printf("\n!!!  Invalid choice  !!!\n");
		goto step1;
	}
}