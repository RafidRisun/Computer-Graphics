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

    quad(0.1, 0.6, 1.87, 0.6, 1.87, 1.4, 0.1, 1.4, 102, 178, 255);//sky

    //night
    quad(0.1, 0.6, 1.87, 0.6, 1.87, 1.4, 0.1, 1.4, 0, 51, 102);

    quad(0.1, 0, 1.87, 0, 1.87, 0.6, 0.1, 0.6, 153, 255, 255);//water
    //night
    quad(0.1, 0, 1.87, 0, 1.87, 0.6, 0.1, 0.6, 0, 102, 102);

    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 153);
    glVertex2f(0.102339, 0.601766);
    glVertex2f(0.4, 0.720882);
    glVertex2f(0.675943, 0.642676);
    glVertex2f(0.832355, 0.801146);
    glVertex2f(1.07109, 0.677663);
    glVertex2f(1.2, 0.8);
    glVertex2f(1.645286, 0.642676);
    glVertex2f(1.79964, 0.716766);
    glVertex2f(1.877757, 0.597088);
    glEnd();


    //land
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(76, 153, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0.7, 0);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.7, 0.6);
    glVertex2f(0.1, 0.6);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(76, 153, 0);
    glVertex2f(1.45, 0);
    glVertex2f(1.87, 0);
    glVertex2f(1.87, 0.6);
    glVertex2f(1.07, 0.6);
    glVertex2f(0.977, 0.4);
    glEnd();

    //house
    quad(1.181138, 0.494788, 1.381138, 0.494788, 1.381138, 0.694788, 1.181138, 0.694788, 153, 76, 0);
    quad(1.381138, 0.494788, 1.381138, 0.694788, 1.479138, 0.673788, 1.479138, 0.515788, 102, 51, 0);
    quad(1.381138, 0.694788, 1.479138, 0.673788, 1.399833, 0.764659, 1.281138, 0.794788, 96, 96, 96);
    glBegin(GL_POLYGON);
    glColor3ub(128, 128, 128);
    glVertex2f(1.181138, 0.694788);
    glVertex2f(1.281138, 0.794788);
    glVertex2f(1.381138, 0.694788);
    glEnd();

    quad(1.531026, 0.559093, 1.613263, 0.557365, 1.613263, 0.758511, 1.531026, 0.759093, 51, 25, 0);
    circle(0.14607, 1.568823, 0.875456, 0, 153, 0);
    circle(0.14607, 1.68343, 0.875456, 0, 153, 0);
    circle(0.14607, 1.456556, 0.875456, 0, 153, 0);
    circle(0.14607, 1.568823, 0.987724, 0, 153, 0);

    //moon/sun
    circle(0.1, 0.46808, 1.068693, 255, 255, 0);

    //night
    circle(0.1, 0.46808, 1.068693, 255, 255, 153);
    circle(0.16, 0.610086, 1.128376, 0, 51, 102);

    //boat
    quad(0.730624, 0.31535, 0.895692, 0.31535, 0.89928, 0.36798, 0.7282321, 0.364392, 204, 102, 0);
    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(0.730624, 0.31535);
    glVertex2f(0.7282321, 0.364392);
    glVertex2f(0.630147, 0.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(204, 102, 0);
    glVertex2f(0.895692, 0.31535);
    glVertex2f(0.89928, 0.36798);
    glVertex2f(0.977757, 0.4);
    glEnd();


    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(500, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0.1, 1.87, 0.0, 1.4);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}