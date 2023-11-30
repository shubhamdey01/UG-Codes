#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int x0, y0, xn, yn;

void display(void) {
  int x, y, dx, dy, pk, k;
  glBegin(GL_POINTS);
  glVertex2i(x0, y0);
  glEnd();
  dx = xn - x0;
  dy = yn - y0;
  pk = 2 * dy - dx;
  x = x0;
  y = y0;
  for (k = 0; k < dx - 1; ++k) {
    if (pk < 0) {
      pk = pk + 2 * dy;
    } else {
      pk = pk + 2 * dy - 2 * dx;
      ++y;
    }
    ++x;
    printf("k=%d, pk=%d, x%d=%d, y%d=%d\n",k,pk,k,x,k,y);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
  printf("Value of x0 : ");
  scanf("%d", &x0);
  printf("Value of y0 : ");
  scanf("%d", &y0);
  printf("Value of xn : ");
  scanf("%d", &xn);
  printf("Value of yn : ");
  scanf("%d", &yn);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Mid Point Line");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}
