/******************************************************************************
Name : Shubham Dey
Program : Write a program in C to implement end point code generation algorithm.
Program No. : 11
Date : 29.04.2023
*******************************************************************************/

#include <stdio.h>

#define Xmin -100
#define Xmax 100
#define Ymin -100
#define Ymax 100

#define TOP 8
#define BOTTOM 4
#define RIGHT 2
#define LEFT 1

int endCode(int, int);
void decToBinary(int);

int main() {
	int xd, yd, code;

	printf("Window(%d, %d, %d, %d)\n", Xmin, Xmax, Ymin, Ymax);
    printf("\nEnter coordinates of the point :\n");
    scanf("%d %d", &xd, &yd);

    code = endCode(xd, yd);
    printf("\nEnd point code for (%d, %d) = ", xd, yd);
    decToBinary(code);
    printf("\n");
	return 0;
}

int endCode(int x, int y) {
	int c = 0;
	if(x < Xmin)
		c |= LEFT;
	if(x > Xmax)
		c |= RIGHT;
	if(y < Ymin)
		c |= BOTTOM;
	if(y > Ymax)
		c |= TOP;
	return c;
}

void decToBinary(int n) {
    int num[] = {0,0,0,0};
    int i = 0;
    while (n > 0) {
        num[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (i=3; i>=0; i--)
        printf("%d", num[i]);
}