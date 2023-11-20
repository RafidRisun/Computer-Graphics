#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void quad(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float r, float g, float b)
{
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(r, g, b); // Yellow
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    //car
    glBegin(GL_POLYGON);
    glColor3ub(176, 196, 222);

    glVertex2f(0.1263, 0.438);//c
    glVertex2f(0.13, 0.3819);//d
    glVertex2f(0.16, 0.3279);//e
    glVertex2f(0.158, 0.304);//f
    glVertex2f(0.38, 0.286);//g
    glVertex2f(0.4127, 0.4828);//n
    glVertex2f(0.236, 0.467742);//o
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(176, 196, 222);
    glVertex2f(0.38, 0.286);//g
    glVertex2f(0.8507, 0.286);
    glVertex2f(1.088, 0.312);
    glVertex2f(1.115, 0.336);
    glVertex2f(1.123, 0.464);
    glVertex2f(0.9112, 0.6);
    glVertex2f(0.57, 0.6);
    glVertex2f(0.4127, 0.4828);//n
    glEnd();

    //wheels
    circle(0.08, 0.26901, 0.298198, 50, 50, 50);
    circle(0.05, 0.26901, 0.298198, 150, 150, 150);

    circle(0.08, 0.9478, 0.298198, 50, 50, 50);
    circle(0.05, 0.9478, 0.298198, 150, 150, 150);

    //window
    quad(0.446349, 0.483631, 0.727461, 0.481701, 0.735247, 0.585981, 0.578623, 0.585981, 135, 206, 250);
    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 250);
    glVertex2f(0.747, 0.48375);
    glVertex2f(0.9966, 0.49266);
    glVertex2f(1, 0.511);
    glVertex2f(0.892654, 0.58592);
    glVertex2f(0.751762, 0.585449);
    glEnd();

    glLineWidth(0.01);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.419466, 0.310659);
    glVertex2f(0.740217, 0.309865);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.740217, 0.309865);
    glVertex2f(0.751332, 0.422604);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.751332, 0.422604);
    glVertex2f(0.747125, 0.483753);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.419466, 0.310659);
    glVertex2f(0.402255, 0.371607);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.402255, 0.371607);
    glVertex2f(0.408303, 0.438996);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.408303, 0.438996);
    glVertex2f(0.430766, 0.482194);
    glEnd();

    quad(0.116249, 0.354982, 0.168596, 0.354982, 0.168596, 0.380437, 0.116249, 0.380437, 112, 128, 144);

    quad(1.049136, 0.354982, 1.139978, 0.354982, 1.14, 0.380437, 1.049387, 0.380437, 112, 128, 144);

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0.0, 1.3, 0.0, 0.8);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}