#include <GL/glut.h>
#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include "ddaLine.h"

#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4
#define R 20

static int WINDOW_WIDTH, WINDOW_HEIGHT;

static float Xspeed = 2, Yspeed = 2;
static float delta = 2;
int flag_pg = 0;

typedef struct 
{
	float x, y;
} CIRCLE;
typedef struct 
{
	float left, top, right, bottom;
}RECTA;

CIRCLE ball = {300,300};
RECTA wall = { 300, 300, 900, 600 };
int x[] = {300,900,900,300}, y[] = {300,300,600,600};

void drawCircle(CIRCLE cir)
{
	float i=0.0f;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cir.x, cir.y);
	for(i=0.0f; i<360; i++)
		glVertex2f(R*cos(M_PI*i/180.0)+cir.x, R*sin(M_PI*i/180.0)+cir.y);
	glEnd();
}

void polygon(int *x, int *y) {
	glPointSize(2.5);
	for(int i=0; i<4; i++) {
		if(i < 3) {
			ddaLine(x[i], y[i], x[i+1], y[i+1]);
			continue;
		}
		ddaLine(x[i], y[i], x[0], y[0]);
	}
}

void Timer(int v)
{
	ball.x += Xspeed;
	ball.y += Yspeed;

	glutTimerFunc(1, Timer, 1);
}

int Test_Ball_Wall(CIRCLE  ball, RECTA wall)
{
	if (ball.x >= wall.right-R)
		return FROM_RIGHT;
	if (ball.x <= wall.left+R)
		return FROM_LEFT;
	if (ball.y <= wall.top+R)
		return FROM_TOP;
	if (ball.y >= wall.bottom-R)
		return FROM_BOTTOM;

	else return 0;
}

// OpenGL Setting
void Setting(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


// OnWindowResize 
void reshape(int w, int h)
{
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	drawCircle(ball);
	polygon(x,y);

	if (Test_Ball_Wall(ball, wall) == FROM_RIGHT)
	{
		glColor3f(1,0,0);
		Xspeed = -delta;
	}

	if (Test_Ball_Wall(ball, wall) == FROM_LEFT){
		glColor3f(1,1,1);
		Xspeed = delta;
	}

	if (Test_Ball_Wall(ball, wall) == FROM_TOP){
		glColor3f(0,1,0);
		Yspeed = delta;
	}

	if (Test_Ball_Wall(ball, wall) == FROM_BOTTOM)
	{
		glColor3f(0,0,1);
		Yspeed = -delta;
	}

	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1400, 1000);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("DX BALL OpenGL game");

	Setting();

	glutDisplayFunc(Render);
	glutIdleFunc(Render);
	glutTimerFunc(1, Timer, 1);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}