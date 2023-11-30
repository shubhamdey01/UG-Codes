#include <GL/glut.h>
#include <unistd.h>
#include <math.h>


typedef struct 
{
    float x, y;
} CIRCLE;

CIRCLE ball = {300,300};

void drawCircle(CIRCLE cir)
{
    float radius = 0.0f;
    glPointSize(3);
    for (float angle = 0; angle < 1440; angle += 1)
    {
        cir.x = cos(angle * M_PI / 180) * radius;
        cir.y = sin(angle * M_PI / 180) * radius;
        radius += 0.1f;
        glBegin(GL_POINTS);
        glVertex2f(cir.x, cir.y);
        glEnd();
        sleep(0.5);
        glFlush();
    }
}

void displayMe(void)
{
    drawCircle(ball);
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Drawing");
    myInit();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}