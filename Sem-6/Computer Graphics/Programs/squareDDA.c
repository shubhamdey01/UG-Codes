// Square Drawing

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void draw(void);
void myInit(void);
void ddaLine(int, int, int, int);

int a, b, c, d;

int main(int argc, char** argv) {

	
	printf("Enter diagonal point P1 :\n");
	scanf("%d %d", &a, &b);
	printf("Enter diagonal point P2 :\n");
	scanf("%d %d", &c, &d);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square using DDA Line");
    myInit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void draw(void){
	ddaLine(-540, 0, 540, 0);
	ddaLine(0, -360, 0, 360);

	glColor3f(1,0,0);
	ddaLine(a, b, c, b);
	ddaLine(c, b, c, d);
	ddaLine(c, d, a, d);
	ddaLine(a, d, a, b);
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