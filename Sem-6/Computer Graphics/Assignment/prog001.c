/********************************************************************
Name : Shubham Dey
Program : Write a program in C to draw a line by using DDA algorithm 
			when two points are given. [Use OpenGL Library]
Program No. : 01
Date : 14.03.2023
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void);
void myInit(void);
void ddaLine(int, int, int, int);
void reshape(int w, int h);

int a, b, c, d;

int main(int argc, char** argv) {
	printf("Enter X1 :\t");
	scanf("%d", &a);
	printf("Enter Y1 :\t");
	scanf("%d", &b);
	printf("\nEnter X2 :\t");
	scanf("%d", &c);
	printf("Enter Y2 :\t");
	scanf("%d", &d);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    myInit();
    glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(2.0);
}

void draw(void){
	ddaLine(a, b, c, d);
}

void ddaLine(int x1, int y1, int x2, int y2) {
	float dx, dy, step, x, y, k, xin, yin;

	dx = x2-x1;
	dy = y2-y1;
	step = abs(dx)>abs(dy) ? abs(dx) : abs(dy);

	xin = dx/step;
	yin = dy/step;
	x = x1;
	y = y1;

	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	for(k=1; k<=step; k++) {
		x += xin;
		y += yin;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}