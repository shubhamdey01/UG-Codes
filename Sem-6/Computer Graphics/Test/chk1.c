/******************************************************************************************************************
Name: Dhruba Saha
Program: Write a program in C to implement Cohen-Sutherland algorithm.
Program No. 012
Date: 2023-04-28
*******************************************************************************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
#define XMIN 50
#define YMIN 50
#define XMAX 200
#define YMAX 200

char title[] = "Cohen-Sutherland Clipping Algorithm";
int winWidth = 1000;
int winHeight = 1000;
int range_x1 = -500;
int range_x2 = 500;
int range_y1 = -500;
int range_y2 = 500;

typedef struct point
{
    float x, y;
} point;

point a, b;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, winWidth, 0, winHeight);
}

void drawAxes(void)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(range_x1, 0.0);
    glVertex2f(range_x2, 0.0);
    glVertex2f(0.0, range_y1);
    glVertex2f(0.0, range_y2);
    glEnd();

    int num_ticks_x = (int)(range_x2 - range_x1);
    GLfloat tick_size_x = 0.1;
    GLfloat tick_spacing_x = (range_x2 - range_x1) / num_ticks_x;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i <= num_ticks_x; i++)
    {
        glVertex2f(range_x1 + i * tick_spacing_x, -tick_size_x);
        glVertex2f(range_x1 + i * tick_spacing_x, tick_size_x);
    }
    glEnd();

    int num_ticks_y = (int)(range_y2 - range_y1);
    GLfloat tick_size_y = 0.1;
    GLfloat tick_spacing_y = (range_y2 - range_y1) / num_ticks_y;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i = 0; i <= num_ticks_y; i++)
    {
        glVertex2f(-tick_size_y, range_y1 + i * tick_spacing_y);
        glVertex2f(tick_size_y, range_y1 + i * tick_spacing_y);
    }
    glEnd();
}

int code(double x, double y)
{
    int c = INSIDE;
    if (x < XMIN)
        c |= LEFT;
    else if (x > XMAX)
        c |= RIGHT;
    if (y < YMIN)
        c |= BOTTOM;
    else if (y > YMAX)
        c |= TOP;
    return c;
}

void drawLine(double x1, double y1, double x2, double y2, int accept)
{
    glColor3f(1.0, 0.0, 0.0);
    if (accept)
    {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

void CohenSutherland(double x1, double y1, double x2, double y2)
{
    int accept = 0, done = 0;
    int code1, code2;
    double x, y;

    while (!done)
    {
        code1 = code(x1, y1);
        code2 = code(x2, y2);

        if (code1 == 0 && code2 == 0)
        {
            accept = 1;
            done = 1;
        }
        else if (code1 & code2)
        {
            done = 1;
        }
        else
        {
            if (code1 != 0)
            {
                if (code1 & LEFT)
                {
                    x = XMIN;
                    y = y1 + (y2 - y1) * (XMIN - x1) / (x2 - x1);
                }
                else if (code1 & RIGHT)
                {
                    x = XMAX;
                    y = y1 + (y2 - y1) * (XMAX - x1) / (x2 - x1);
                }
                else if (code1 & BOTTOM)
                {
                    y = YMIN;
                    x = x1 + (x2 - x1) * (YMIN - y1) / (y2 - y1);
                }
                else
                {
                    y = YMAX;
                    x = x1 + (x2 - x1) * (YMAX - y1) / (y2 - y1);
                }
                x1 = x;
                y1 = y;
            }
            else
            {
                if (code2 & LEFT)
                {
                    x = XMIN;
                    y = y1 + (y2 - y1) * (XMIN - x1) / (x2 - x1);
                }
                else if (code2 & RIGHT)
                {
                    x = XMAX;
                    y = y1 + (y2 - y1) * (XMAX - x1) / (x2 - x1);
                }
                else if (code2 & BOTTOM)
                {
                    y = YMIN;
                    x = x1 + (x2 - x1) * (YMIN - y1) / (y2 - y1);
                }
                else
                {
                    y = YMAX;
                    x = x1 + (x2 - x1) * (YMAX - y1) / (y2 - y1);
                }
                x2 = x;
                y2 = y;
            }
        }
    }
    drawLine(x1, y1, x2, y2, accept);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(XMIN, YMIN);
    glVertex2f(XMIN, YMAX);
    glVertex2f(XMAX, YMAX);
    glVertex2f(XMAX, YMIN);
    glEnd();

    CohenSutherland(a.x, a.y, b.x, b.y);

    glFlush();
}

void reshape(int width, int height)
{
    float aspect_ratio = (range_x2 - range_x1) / (range_y2 - range_y1);

    float cx = (range_x1 + range_x2) / 2.0;
    float cy = (range_y1 + range_y2) / 2.0;

    int size = width < height ? width : height;
    int x = (width - size) / 2;
    int y = (height - size) / 2;
    glViewport(x, y, size, size);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (aspect_ratio > 1)
    {
        float left = (range_x1 - cx) * aspect_ratio;
        float right = (range_x2 - cx) * aspect_ratio;
        glOrtho(left, right, range_y1 - cy, range_y2 - cy, -1.0, 1.0);
    }
    else
    {
        float bottom = (range_y1 - cy) / aspect_ratio;
        float top = (range_y2 - cy) / aspect_ratio;
        glOrtho(range_x1 - cx, range_x2 - cx, bottom, top, -1.0, 1.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Enter the first point (x, y): ");
    scanf("%f %f", &a.x, &a.y);
    printf("Enter the second point (x, y): ");
    scanf("%f %f", &b.x, &b.y);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow(title);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
