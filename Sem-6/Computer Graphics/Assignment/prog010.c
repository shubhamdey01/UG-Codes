/********************************************************************
Name : Shubham Dey
Program : Write a program in C to implement point visibility algorithm.
Program No. : 10
Date : 29.04.2023
********************************************************************/

#include <GL/glut.h>
#include <stdio.h>

#define Xmin -100
#define Xmax 100
#define Ymin -100
#define Ymax 100

void myInit(void);
void display(void);
void myKey(unsigned char, int, int);
void pointClipping(int, int);

int xd, yd, flag;

int main(int argc, char** argv) {
    printf("Window(%d, %d, %d, %d)\n", Xmin, Xmax, Ymin, Ymax);
    printf("\nEnter coordinates of the point :\n");
    scanf("%d %d", &xd, &yd);
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
        glPointSize(8.0);
        glColor3f(1,0,0);
        glBegin(GL_POINTS);
        glVertex2i(xd,yd);
        glEnd();
        glFlush();
    }  
}

void myKey(unsigned char key,int x,int y) {
    if(key=='c') {
        pointClipping(xd, yd);
        glFlush();
    }
}

void pointClipping(int x, int y) {
    if(x < Xmin || x > Xmax || y < Ymin || y > Ymax) {
        flag = 0;
        display();
        printf("\nPoint is OUTSIDE the window.\nClipping done.\n");
    }
    else
        printf("\nPoint is INSIDE the window.\nClipping not required\n");
}