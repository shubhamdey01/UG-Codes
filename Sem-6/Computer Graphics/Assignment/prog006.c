/********************************************************************
Name : Shubham Dey
Program : Write a program in C to implement two-dimensional rotation 
	with respect to a pivot point. Output depends upon user’s choice. 
	[Use OpenGL Library]
Program No. : 06
Date : 10.04.2023
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "ddaLine.h"

#define N 3

void myInit(void);
void draw(void);
void polygon(int*, int*, float[]);
void rotation(double);

int *a, *b, xr, yr;
// int *x, *y, n;
int x[] = {50,150,250}, y[] = {50,200,200};
double theta;

int main(int argc, char** argv) {
	// printf("Enter no. of vertices :\t");
	// scanf("%d", &n);
	
	// x = (int*)calloc(n, sizeof(int));
	// y = (int*)calloc(n, sizeof(int));
	// printf("Enter the coordinates of the polygon in clockwise direction [rotating vertex = (x1, y1)]\n");
	// for(int i=0; i<n; i++) {
	// 	printf("Enter x%d & y%d :\n", i+1, i+1);
	// 	scanf("%d %d", x+i, y+i);
	// }

	printf("\nEnter Theta(in degree) for rotation :\n");
	scanf("%lf", &theta);
	printf("\nEnter pivot point (x,y) for rotation :\n");
	scanf("%d %d", &xr, &yr);
	theta *= M_PI / 180;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotation");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void draw(void){
	ddaLine(0,-350,0,350);
	ddaLine(-530,0,530,0);
	float color[] = {1, 0, 0};
	polygon(x, y, color);
	rotation(theta);
}

void polygon(int *x, int *y, float color[]) {
	glColor3f(color[0], color[1], color[2]);
	for(int i=0; i<N; i++) {
		if(i < N-1) {
			ddaLine(x[i], y[i], x[i+1], y[i+1]);
			continue;
		}
		ddaLine(x[i], y[i], x[0], y[0]);
	}
}

void rotation(double t) {
	a = (int*)calloc(N, sizeof(int));
	b = (int*)calloc(N, sizeof(int));
	for(int i=0; i<N; i++) {
		a[i] = xr + (x[i]-xr)*cos(t) - (y[i]-yr)*sin(t);
		b[i] = yr + (x[i]-xr)*sin(t) + (y[i]-yr)*cos(t);
	}
	float color[] = {0, 0, 1};
	polygon(a, b, color);
}