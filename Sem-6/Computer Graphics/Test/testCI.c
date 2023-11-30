#include <GL/glut.h>
#include <math.h>

// Circle parameters
float cx1 = 0.5, cy1 = 0.0, r1 = 0.3;
float cx2 = 0.5, cy2 = 0.0, r2 = 0.4;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   
   // Draw the circles
   glBegin(GL_LINE_LOOP);
   for (float angle = 0.0; angle <= 360.0; angle += 0.1) {
      float radian = angle * M_PI / 180.0;
      glVertex2f(cx1 + r1 * cos(radian), cy1 + r1 * sin(radian));
   }
   glEnd();
   
   glBegin(GL_LINE_LOOP);
   for (float angle = 0.0; angle <= 360.0; angle += 0.1) {
      float radian = angle * M_PI / 180.0;
      glVertex2f(cx2 + r2 * cos(radian), cy2 + r2 * sin(radian));
   }
   glEnd();
   
   // Find the intersection points
   float d = sqrt(pow(cx1 - cx2, 2) + pow(cy1 - cy2, 2));
   if (d < r1 + r2 && d > fabs(r1 - r2)) {
      float a = (pow(r1, 2) - pow(r2, 2) + pow(d, 2)) / (2 * d);
      float h = sqrt(pow(r1, 2) - pow(a, 2));
      float px = cx1 + a * (cx2 - cx1) / d;
      float py = cy1 + a * (cy2 - cy1) / d;
      glBegin(GL_POINTS);
      glVertex2f(px + h * (cy2 - cy1) / d, py - h * (cx2 - cx1) / d);
      glVertex2f(px - h * (cy2 - cy1) / d, py + h * (cx2 - cx1) / d);
      glEnd();
   }
   
   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("Circle Intersection");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}