/*************************************
Name : Shubham Dey
Program : Write a robust program to find all prime nos. from 1 to n
Program No. : 003
Date : 14.03.2022
*************************************/

#include <stdio.h>
#include <stdlib.h>

void prime(int n);
void new(int a);
void display();

struct node
{
	int num;
	struct node *next;
} *P = NULL;

int main()
{
	int n;

	printf("Enter n :\t");
	scanf("%d",&n);
	prime(n);
	printf("Prine nos. between 1 to %d :\n",n);
	display(P);

	return 0;
}

void prime(int n)
{
	int i;
	if(n>1)
		new(2);
	struct node *j;
	for(i=3;i<=n;i+=2)
	{
		j = P;
		while(j != NULL)
		{
			if(i % j->num == 0)
				break;
			j = j->next;
		}
		if(j == NULL)
			new(i);
	}
}

void new(int a)
{
	struct node *x = (struct node*)calloc(1,sizeof(struct node));
	x->num = a;
	x->next = NULL;
	if(P == NULL)
	{
		P = x;
		return;
	}

	struct node *i = P;
	while(i->next != NULL)
		i = i->next;
	i->next = x;
}

void display()
{
	struct node *i = P;
	while(i != NULL)
	{
		printf("%d  ",i->num);
		i = i->next;
	}
	printf("\n");
}