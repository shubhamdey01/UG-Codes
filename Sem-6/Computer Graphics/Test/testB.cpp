#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>

#define FROM_RIGHT      1 
#define FROM_LEFT       2 
#define FROM_TOP        3 
#define FROM_BOTTOM     4 

static int WINDOW_WIDTH, WINDOW_HEIGHT;

int playerResult = 0;
static float Xspeed = 2, Yspeed = 2;
static float delta = 2;
int flag_pg = 0;
char string[100];

struct RECTA
{
	float left, top, right, bottom;
};

RECTA ball = { 100, 100, 120, 120 };
RECTA wall = { 200, 200, 800, 400 };
RECTA player_1 = { 0, 790, 80, 800 };

void DrawRectangle(RECTA  rect)
{
	glBegin(GL_QUADS);
	glVertex2f(rect.left, rect.bottom);      //Left - Bottom 
	glVertex2f(rect.right, rect.bottom);
	glVertex2f(rect.right, rect.top);
	glVertex2f(rect.left, rect.top);
	glEnd();
}

void Timer(int v)
{
	ball.left += Xspeed;
	ball.right += Xspeed;
	ball.top += Yspeed;
	ball.bottom += Yspeed;

	glutTimerFunc(1, Timer, 1);
}

int Test_Ball_Wall(RECTA  ball, RECTA wall)
{
	if (ball.right >= wall.right)
		return FROM_RIGHT;
	if (ball.left <= wall.left)
		return FROM_LEFT;
	if (ball.top <= wall.top)
		return FROM_TOP;
	if (ball.bottom >= wall.bottom)
		return FROM_BOTTOM;

	else return 0;
}

bool Test_Ball_Player(RECTA ball, RECTA player)
{

	if (ball.bottom >= player.top && ball.left >= player.left && ball.right <= player.right)
	{
		playerResult++;
		if ((playerResult + 1) % 2 == 0 )
			delta += 1;
		
		return true;
	}
	else if (ball.bottom >= player.bottom && (ball.left < player.left || ball.right > player.right))
	{
		flag_pg = 1;
		glutPostRedisplay();
		
	}
	return false;
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

int pcResult = 0;

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	DrawRectangle(ball);

	if (Test_Ball_Wall(ball, wall) == FROM_RIGHT)
		Xspeed = -delta;

	if (Test_Ball_Wall(ball, wall) == FROM_LEFT)
		Xspeed = delta;

	if (Test_Ball_Wall(ball, wall) == FROM_TOP)
		Yspeed = delta;

	if (Test_Ball_Wall(ball, wall) == FROM_BOTTOM)
	{
		Yspeed = -delta;
		pcResult += 1;
	}

	// DrawRectangle(player_1);
	// player_1.left = mouse_x - 60;
	// player_1.right = mouse_x + 60;


	if (Test_Ball_Player(ball, player_1) == true)
		Yspeed = -delta;

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