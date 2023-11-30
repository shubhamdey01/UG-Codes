/********************************************************************
Name : Shubham Dey
Program : Write a program in C to implement Cohen-Sutherland algorithm.
Program No. : 12
Date : 29.04.2023
********************************************************************/

#include <GL/glut.h>
#include <stdio.h>

#define Xmin -100
#define Xmax 100
#define Ymin -100
#define Ymax 100

#define TOP 8
#define BOTTOM 4
#define RIGHT 2
#define LEFT 1

#define INSIDE(a) (!a)
#define REJECT(a,b) (a&b)
#define ACCEPT(a,b) (!(a|b))

void myInit(void);
void display(void);
void myKey(unsigned char,int,int);
int endCode(int, int);
void cohenSutherland(int, int, int, int);

int xd1, yd1, xd2, yd2, flag;

int main(int argc, char** argv) {
    printf("Enter coordinates of the point1 :\n");
    scanf("%d %d", &xd1, &yd1);
    printf("\nEnter coordinates of the point2 :\n");
    scanf("%d %d", &xd2, &yd2);
    flag = 1;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Point Clipping");
    myInit();
    glutDisplayFunc(display);

    printf("\nPress key 'C' for clipping.\n");
    glutKeyboardFunc(myKey);
    glutMainLoop();
    return 0;
}

void myInit() {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2.0);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(Xmin,Ymin);
    glVertex2i(Xmin,Ymax);
    glVertex2i(Xmax,Ymax);
    glVertex2i(Xmax,Ymin);
    glEnd();
    glFlush();

    if(flag) {
        glPointSize(2.0);
        glColor3f(1,0,0);
        glBegin(GL_LINES);
        glVertex2i(xd1,yd1);
        glVertex2i(xd2,yd2);
        glEnd();
        glFlush();
    }
}

void myKey(unsigned char key,int x,int y) {
    if(key=='c') {
        cohenSutherland(xd1, yd1, xd2, yd2);
        glFlush();
    }
}

int endCode(int x, int y) {
    int c = 0;
    if(x < Xmin)
        c |= LEFT;
    if(x > Xmax)
        c |= RIGHT;
    if(y < Ymin)
        c |= BOTTOM;
    if(y > Ymax)
        c |= TOP;
    return c;
}

void cohenSutherland(int x1, int y1, int x2, int y2) {
    int code1 = endCode(x1, y1);
    int code2 = endCode(x2, y2);
    float m = (y2-y1)/(float)(x2-x1);
    int x, y, code;

    while(1) {
        if(ACCEPT(code1, code2)) {
            flag = 1;
            break;
        }
        else if(REJECT(code1, code2)) {
            flag = 0;
            break;
        }
    
        x = x1; y = y1; code = code1;
        if(INSIDE(code1)) {
            x = x2;
            y = y2;
            code = code2;
        }

        if(code & LEFT) {
            y += (Xmin - x) * m;
            x = Xmin;
        }
        else if(code & RIGHT) {
            y += (Xmax - x) * m;
            x = Xmax;
        }
        else if(code & BOTTOM) {
            x += 1/m*(Ymin - y);
            y = Ymin;
        }
        else if(code & TOP) {
            x += 1/m*(Ymax - y);
            y = Ymax;
        }

        if(code == code1) {
            xd1 = x;
            yd1 = y;
            code1 = endCode(xd1, yd1);
        }
        else {
            xd2 = x;
            yd2 = y;
            code2 = endCode(xd2, yd2);
        }        
    }
    display();
}