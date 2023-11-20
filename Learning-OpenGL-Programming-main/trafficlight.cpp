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
        glColor3f(r, g, b);
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

    quad(0, 0, 2.2, 0, 2.2, 1.1, 0, 1.1, 50, 50, 50);

    //building
    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(0, 1.1);
    glVertex2f(0.2, 1.1);
    glVertex2f(0.2, 1.4);
    glVertex2f(0, 1.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(0.2, 1.1);
    glVertex2f(0.4, 1.1);
    glVertex2f(0.4, 1.8);
    glVertex2f(0.2, 1.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(0.4, 1.1);
    glVertex2f(0.8, 1.1);
    glVertex2f(0.8, 1.4);
    glVertex2f(0.4, 1.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(0.8, 1.1);
    glVertex2f(1.2, 1.1);
    glVertex2f(1.2, 1.6);
    glVertex2f(0.8, 1.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(1.2, 1.1);
    glVertex2f(1.4, 1.1);
    glVertex2f(1.4, 1.4);
    glVertex2f(1.2, 1.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(1.4, 1.1);
    glVertex2f(1.8, 1.1);
    glVertex2f(1.8, 2.0);
    glVertex2f(1.4, 2.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(1.8, 1.1);
    glVertex2f(2.0, 1.1);
    glVertex2f(2.0, 1.4);
    glVertex2f(1.8, 1.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 79, 79);
    glVertex2f(2.0, 1.1);
    glVertex2f(2.2, 1.1);
    glVertex2f(2.2, 1.8);
    glVertex2f(2.0, 1.8);
    glEnd();

    //street
    quad(0, 0, 0.46, 0, 0.7, 0.7, 0, 0.7, 186, 178, 171);
    quad(0, 0.9, 0.78, 0.9, 0.87, 1.1, 0, 1.1, 186, 178, 171);
    quad(1.6, 0, 2.2, 0, 2.2, 0.7, 1.4, 0.7, 186, 178, 171);
    quad(1.2, 1.1, 1.3, 0.9, 2.2, 0.9, 2.2, 1.1, 186, 178, 171);

    //trafficlight
    quad(0.58, 1.2, 0.76, 1.2, 0.76, 1.5, 0.58, 1.5, 128, 128, 128);
    circle(0.04, 0.67, 1.44, 1.0, 0.0, 0.0);
    circle(0.04, 0.67, 1.34, 1.0, 1.0, 0.0);
    circle(0.04, 0.67, 1.25, 0.0, 1.0, 0.0);
    quad(0.64, 0.7, 0.7, 0.7, 0.7, 1.2, 0.64, 1.2, 128, 128, 128);

    //stripes
    quad(0.925, 0, 1.145, 0, 1.105, 0.3, 0.966, 0.3, 255, 255, 255);
    quad(0.977, 0.4, 1.1, 0.4, 1.077, 0.65, 1, 0.65, 255, 255, 255);
    quad(1.017, 1, 1.079, 1, 1.079, 1.1, 1.017, 1.1, 255, 255, 255);

    //car
    glBegin(GL_POLYGON);
    glColor3ub(65, 105, 225);
    glVertex2f(1.2, 0.8);
    glVertex2f(2.2, 0.8);
    glVertex2f(2.324, 0.969);
    glVertex2f(2.047, 1.192);
    glVertex2f(1.528, 1.192);
    glVertex2f(1.373, 1.018);
    glVertex2f(1.154, 0.985);
    glVertex2f(1.106, 0.873);
    glEnd();

    circle(0.09, 1.441, 0.779, 0, 0, 0);
    circle(0.06, 1.441, 0.779, 1, 1, 1);
    circle(0.09, 2, 0.779, 0, 0, 0);
    circle(0.06, 2, 0.779, 1, 1, 1);

    quad(1.373, 1.018, 1.495, 1.03, 1.647, 1.163, 1.5, 1.163, 176, 196, 222);
    quad(1.564, 1.038, 1.933, 1.035, 1.92, 1.163, 1.678, 1.163, 176, 196, 222);
    quad(1.958, 1.038, 2.173, 1.03, 2.044, 1.163, 1.95, 1.163, 176, 196, 222);

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(500, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0.0, 2.2, 0.0, 2.2);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}