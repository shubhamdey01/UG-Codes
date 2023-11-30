// Rotation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "ddaLine.h"

void myInit(void);
void draw(void);
void rotation();

int a, b, l;
double t;

int main(int argc, char** argv) {
	printf("Enter X1 :\t");
	scanf("%d", &a);
	printf("Enter Y1 :\t");
	scanf("%d", &b);
	printf("\nEnter length :\t");
	scanf("%d", &l);
	printf("\nEnter angle(in degree) :\t");
	scanf("%lf", &t);
	t *= M_PI / 180;

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
	rotation();
}

void rotation() {
	int p, q, x, y;
	p = a + l;
	q = b;
	// printf("%d %d\n",p,q );
	x = a + (p-a)*cos(t) - (q-b)*sin(t);
	y = b + (p-a)*sin(t) + (q-b)*cos(t);
	glColor3f(1,0,0);
	ddaLine(a,b,x,y);
}