// Cyrus-Beck algorithm

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point p1, p2;
    int flag;
} Line;

void myInit(void);
void display(void);
void draw(float, float, Line*, Point);
void myKey(unsigned char,int,int);
void cyrusBeck(Line*, Point*, Point*, int);

// Point p1, p2;
Point *n, *W;
Line *lin;

int N, L;

int main(int argc, char** argv) {
    int i;
    printf("Enter no. of vertices of the clipping window : \t");
    scanf("%d", &N);

    W = (Point*)calloc(N, sizeof(Point));
    n = (Point*)calloc(N, sizeof(Point));

    printf("Enter the vertices in clockwise direction :\n");
    for(i=0; i<N; i++) {
        printf("V%d :\t", i+1);
        scanf("%f %f", &W[i].x, &W[i].y);
    }

    for(i=0; i<N; i++)
        n[i] = (Point){W[(i+1)%N].y-W[i].y, -(W[(i+1)%N].x-W[i].x)};

    printf("\nEnter no. of lines :\t");
    scanf("%d", &L);
    lin = (Line*)calloc(L,sizeof(Line));
    printf("Enter the endpoints of the lines :\n");
    for(i=0; i<L; i++) {
        printf("L%d-S : ", i+1);
        scanf("%f %f", &lin[i].p1.x, &lin[i].p1.y);
        printf("L%d-E : ", i+1);
        scanf("%f %f", &lin[i].p2.x, &lin[i].p2.y);
        printf("\n");
        lin[i].flag = 1;
    }

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
    glLineWidth(2.0); 
    glLoadIdentity();
    gluOrtho2D(-540.0, 540.0, -360.0, 360.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2.0);
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++)
        glVertex2i(W[i].x, W[i].y);
    glEnd();
    glFlush();

    glPointSize(2.0);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    for(int i=0; i<L; i++) {
        if(lin[i].flag) {
            glVertex2f(lin[i].p1.x, lin[i].p1.y);
            glVertex2f(lin[i].p2.x, lin[i].p2.y);
        }
    }
    glEnd();
    glFlush();
}

void draw(float tl, float tu, Line *l, Point D) {
    Point a, b;
    a = (Point){l->p1.x + D.x*tl, l->p1.y + D.y*tl};
    b = (Point){l->p1.x + D.x*tu, l->p1.y + D.y*tu};

    l->p1 = a; l->p2 = b; l->flag = 1;
}

void myKey(unsigned char key,int x,int y) {
    if(key=='c') {
        for(int i=0; i<L; i++) {
            lin[i].flag = 0;
            cyrusBeck(&lin[i], n, W, N);
        }
        display();
        glFlush();
    }
}

float dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

Point sub(Point a, Point b) {
    Point c = {a.x - b.x, a.y - b.y};
    return c;
}

void cyrusBeck(Line *l, Point *n, Point *f, int k) {
    Point D, w;
    float tl = 0, tu = 1, t, num, deno;
    D = sub(l->p2, l->p1);
    for(int i=0; i<k; i++) {
        w = sub(l->p1, f[i]);
        num = dot(w, n[i]);
        deno = dot(D, n[i]);

        if(deno != 0) {
            t = -num/deno;
            if(deno > 0) {
                if(t > 1)
                    l->flag = 0;
                else
                    tl = (t > tl) ? t : tl;
            }
            else {
                if(t < 0)
                    l->flag = 0;
                else
                    tu = (t < tu) ? t : tu;
            }
        }
        else {
            if(num < 0)
                l->flag = 0;
        }
    }
    if(tl <= tu)
        draw(tl, tu, l, D);
}