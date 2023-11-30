#include<stdlib.h>
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<unistd.h>

float x1, x2, y10, y2;

void display1(void) {
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y10;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } 
  else
    step = abs(dy);

  Xin = dx / step;
  Yin = dy / step;
  x = x1;
  y = y10;

  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  glFlush();

  for (k = 1; k <= step; k++) {
    x = x + Xin;
    y = y + Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    sleep(0.9);
    glFlush();
  }
}

void display2(void) {
  float dy, dx, step, x, y, k, Xin, Yin;
  dx = x2 - x1;
  dy = y2 - y10;
  if (abs(dx) > abs(dy)) {
    step = abs(dx);
  } 
  else
    step = abs(dy);
    
  Xin = dx / step;
  Yin = dy / step;
  x = x2;
  y = y2;

  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
  glFlush();

  for (k = 1; k <= step; k++) {
    x = x - Xin;
    y = y - Yin;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    sleep(0.9);
    glFlush();
  }
}

void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

int main(int argc, char ** argv) {

  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y10);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

  
  int ch;
  printf("\n(1)1st to 2nd point\t(2)2nd to 1st point\nEnter choice:");
  scanf("%d",&ch);
  glutInit( & argc, argv);
  glutInitWindowSize(1080, 720);
  glutInitWindowPosition(0 , 0);
  glutCreateWindow("DDA Line Drawing");
  myInit();

  if(ch == 1)
    glutDisplayFunc(display1);
  else if(ch == 2)
    glutDisplayFunc(display2);
  glutMainLoop();
}