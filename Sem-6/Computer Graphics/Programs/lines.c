// DDA line Drawing algorithm

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void);
void myInit(void);
void ddaLine(int, int, int, int, float, float, float);
void point();

int a1, b1, c1, d1, a2, b2, c2, d2;

int main(int argc, char** argv) {
	printf("Enter X1 :\t");
	scanf("%d", &a1);
	printf("Enter Y1 :\t");
	scanf("%d", &b1);
	printf("\nEnter X2 :\t");
	scanf("%d", &c1);
	printf("Enter Y2 :\t");
	scanf("%d", &d1);

	printf("\nEnter X1 :\t");
	scanf("%d", &a2);
	printf("Enter Y1 :\t");
	scanf("%d", &b2);
	printf("\nEnter X2 :\t");
	scanf("%d", &c2);
	printf("Enter Y2 :\t");
	scanf("%d", &d2);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void draw(void){
	ddaLine(0,-300,0,300,1,1,1);
	ddaLine(-300,0,300,0,1,1,1);
	ddaLine(a1, b1, c1, d1,1,0,0);
	ddaLine(a2, b2, c2, d2,0,1,0);
	point();
}

void ddaLine(int x1, int y1, int x2, int y2, float r, float g, float b) {
	float dx, dy, step, x, y, k, xin, yin;

	dx = x2-x1;
	dy = y2-y1;
	step = abs(dx)>abs(dy) ? abs(dx) : abs(dy);

	xin = dx/step;
	yin = dy/step;
	x = x1;
	y = y1;

	glColor3f(r,g,b);
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

void point() {
	int p1, p2, q1, q2, r1, r2, det, x, y;

	p1 = d1 - b1;
	q1 = a1 - c1;
	r1 = p1*a1 + q1*b1;

	p2 = d2 - b2;
	q2 = a2 - c2;
	r2 = p2*a2 + q2*b2;
 
    det = p1*q2 - p2*q1;
 
    if (det != 0){
    	x = (q2*r1 - q1*r2)/det;
        y = (p1*r2 - p2*r1)/det;

		glColor3f(0, 0, 1);
		glPointSize(5.0);
	    glBegin(GL_POINTS);
		glVertex2i(x,y);
		glVertex2i(x-1,y);
		glVertex2i(x+1,y);
		glVertex2i(x,y-1);
		glVertex2i(x,y+1);
		glEnd();
		glFlush();
	}
}