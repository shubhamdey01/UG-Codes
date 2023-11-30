#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float a, b, c, d;

void init(void) {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void setpixel(GLint xCoordinate, GLint yCoordinate) {
  glBegin(GL_POINTS);
  glVertex2i(xCoordinate, yCoordinate);
  glEnd();
  glFlush();
}

void bresenham(int X1, int Y1, int X2, int Y2) {
  int I;
  float slope, e;
  float X, Y, dx, dy;
  X = X1;
  Y = Y1;
  dx = X2 - X1;
  dy = Y2 - Y1;
  slope = dy / dx;
  printf("%f", slope);
  e = slope - 1 / 2;
  if (slope < 0) {
    for (I = 0; I < dx; I++) {
      setpixel(X, Y);
      while (e < 0) {
        Y = Y - 1;
        e = e + 1;
      }
      X = X + 1;
      e = e + slope;
    }

  } else {
    for (I = 0; I < dx; I++) {
      setpixel(X, Y);
      while (e > 0) {
        Y = Y + 1;
        e = e - 1;
      }
      X = X + 1;
      e = e + slope;
    }
  }
}

void drawmyline() { bresenham(a, b, c, d); }

int main(int argc, char **argv) {
  printf("bresenham\nEnter co-ordinates to draw line(Co-ordinates in between "
         "(0 - 300))\n");
  printf("X1 = ");
  scanf("%f", &a);
  printf("Y1 = ");
  scanf("%f", &b);
  printf("Xend = ");
  scanf("%f", &c);
  printf("Yend = ");
  scanf("%f", &d);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("bresenham line");
  init();
  glutDisplayFunc(drawmyline);
  glutMainLoop();
  return 0;
}