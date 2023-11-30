#include<stdio.h>

void input(int *a, int *b);
int sum(int a, int b);
void display(int *c);

int main()
{
	int x,y,z;

	input(&x, &y);

	z = sum(x, y);

	display(&z);
}

void input(int *a, int *b)
{
	printf("X =\t");
	scanf("%d",a);
	printf("Y =\t");
	scanf("%d",b);
}

int sum(int a, int b)
{
	return a + b;
}

void display(int *c)
{
	printf("Z = %d\n",*c);
}