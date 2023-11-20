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

    //ship
    glBegin(GL_POLYGON);
    glColor3ub(102, 0, 0);
    glVertex2f(0.22, 0.44);
    glVertex2f(0.219396, 0.416745);
    glVertex2f(0.236667, 0.386003);
    glVertex2f(0.301949, 0.382549);
    glVertex2f(1.39, 0.382549);
    glVertex2f(1.5, 0.4);
    glVertex2f(1.530333, 0.44);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96, 96, 96);
    glVertex2f(0.22, 0.44);//e
    glVertex2f(0.241803, 0.475009);//d
    glVertex2f(0.209381, 0.490572);//c
    glVertex2f(0.205491, 0.504405);//q
    glVertex2f(0.380265, 0.505235);//p
    glVertex2f(0.390504, 0.49346);//o
    glVertex2f(0.390504, 0.475009);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(96, 96, 96);
    glVertex2f(0.390504, 0.475009);
    glVertex2f(0.390504, 0.49346);//o
    glVertex2f(1.33342, 0.495622);//n
    glVertex2f(1.33342, 0.475009);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(96, 96, 96);
    glVertex2f(1.33342, 0.475009);
    glVertex2f(1.33342, 0.495622);//n
    glVertex2f(1.340003, 0.507833);//m
    glVertex2f(1.5328, 0.506438);
    glVertex2f(1.530333, 0.446419);//k
    glVertex2f(1.530333, 0.44);

    glEnd();

    quad(0.46, 0.494, 0.46, 0.52, 0.53, 0.52, 0.53, 0.494, 255, 204, 204);//1
    quad(0.53, 0.494, 0.53, 0.54, 0.55, 0.54, 0.55, 0.494, 255, 204, 204);//2
    quad(0.55, 0.494, 0.55, 0.55, 0.56, 0.55, 0.56, 0.494, 255, 204, 204);//3
    quad(0.56, 0.494, 0.56, 0.57, 0.58, 0.57, 0.58, 0.494, 255, 204, 204);//4
    quad(0.58, 0.494, 0.58, 0.55, 0.59, 0.55, 0.59, 0.494, 255, 204, 204);//5
    quad(0.59, 0.494, 0.59, 0.54, 0.62, 0.54, 0.62, 0.494, 255, 204, 204);//6
    quad(0.62, 0.494, 0.62, 0.55, 0.7, 0.55, 0.7, 0.494, 255, 204, 204);//7
    quad(0.7, 0.494, 0.7, 0.53, 0.75, 0.53, 0.75, 0.494, 255, 204, 204);//8
    quad(0.75, 0.494, 0.75, 0.56, 0.78, 0.56, 0.78, 0.494, 255, 204, 204);//9
    quad(0.78, 0.494, 0.78, 0.53, 0.795, 0.53, 0.795, 0.494, 255, 204, 204);//10
    quad(0.795, 0.494, 0.795, 0.55, 0.86, 0.55, 0.86, 0.494, 255, 204, 204);//11
    quad(0.86, 0.494, 0.86, 0.54, 0.96, 0.54, 0.96, 0.494, 255, 204, 204);//12
    quad(0.96, 0.494, 0.96, 0.55, 1.245, 0.55, 1.18, 0.494, 255, 204, 204);//13

    glBegin(GL_POLYGON);
    glColor3ub(255, 204, 204);
    glVertex2f(1.18, 0.494);
    glVertex2f(1.18, 0.55);
    glVertex2f(1.245, 0.55);
    glVertex2f(1.245, 0.535);
    glVertex2f(1.24, 0.52);
    glVertex2f(1.27, 0.495);
    glEnd();


    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0.0, 1.6, 0.0, 0.8);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}