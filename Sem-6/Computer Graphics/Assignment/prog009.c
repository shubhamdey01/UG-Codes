/********************************************************************
Name : Shubham Dey
Program : Write a program in C to implement x-direction shear of an object 
		in two-dimension relative to a line which is parallel to x-axis. 
		Output depends upon user’s choice. [Use OpenGL Library]
Program No. : 08
Date : 15.04.2023
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "ddaLine.h"

#define N 4

void myInit(void);
void draw(void);
void polygon(int*, int*, float[]);
void shearing(int);

int a, yref, *p, *q;
// int *x, *y, n;
int x[] = {0,75,75,0}, y[] = {0,0,75,75};

int main(int argc, char** argv) {
	// printf("Enter no. of vertices :\t");
	// scanf("%d", &n);
	
	// x = (int*)calloc(n, sizeof(int));
	// y = (int*)calloc(n, sizeof(int));
	// for(int i=0; i<n; i++) {
	// 	printf("Enter x%d & y%d :\n", i+1, i+1);
	// 	scanf("%d %d", x+i, y+i);
	// }

	printf("\nEnter SHx for shearing :\n");
	scanf("%d", &a);
	printf("\nEnter Yref :\n");
	scanf("%d", &yref);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Shearing");
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
	glColor3f(0,1,0);
	ddaLine(-530,yref,530,yref);
	shearing(a);
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

void shearing(int shx) {
	for(int i=0; i<N; i++)
		x[i] = x[i] + shx*(y[i]-yref);
	float color[] = {0, 0, 1};
	polygon(x, y, color);
}