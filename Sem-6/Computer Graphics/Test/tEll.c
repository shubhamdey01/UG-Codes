#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
static int rx,ry,xc,yc;


void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glPointSize(3.0);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}


void setPixel(GLint x,GLint y)
{
 glBegin(GL_POINTS);
 x=x+xc;y=y+yc;
 glVertex2f(x,y);
 glEnd();
}

void Ellipse()
{
 int x,y,p;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,0);
 x=0;y=ry;
 p=ry*ry-rx*rx*ry+(rx*rx/4);
 while(y*rx*rx>=x*ry*ry){
    if(p<=0){
        p=p+2*ry*ry*x+3*ry*ry;
        setPixel(x,y);
        x=-1*x;setPixel(x,y);
        y=-1*y;setPixel(x,y);
        x=-1*x;setPixel(x,y);y=-1*y;
        x++;
    }
    else{
        p=p+2*ry*ry*x+rx*rx*(1-2*y)+1+3*ry*ry;
        setPixel(x,y);
        x=-1*x;setPixel(x,y);
        y=-1*y;setPixel(x,y);
        x=-1*x;setPixel(x,y);y=-1*y;
        x++;y--;
    }
 }
 while(y!=0){
    if(p<=0){
        p=p+ry*ry+4*rx*rx-2*rx*rx*y;
        setPixel(x,y);
        x=-1*x;setPixel(x,y);
        y=-1*y;setPixel(x,y);
        x=-1*x;setPixel(x,y);y=-1*y;
        x++;y--;
    }
    else{
        p=p-2*rx*rx*y+3*rx*rx;
        setPixel(x,y);
        x=-1*x;setPixel(x,y);
        y=-1*y;setPixel(x,y);
        x=-1*x;setPixel(x,y);y=-1*y;
        y--;
    }
 }

 glFlush();
}

int main (int argc,char **argv)
{
 printf("Enter rx, ry and centre\n");
 scanf("%d%d%d%d",&rx,&ry,&xc,&yc);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,25);
 glutInitWindowSize(640,480);
 glutCreateWindow("Ellipse Drawing");
 init();
 glutDisplayFunc(Ellipse);
 glutMainLoop();
 return 0;
}