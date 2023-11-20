//Draw Ploygon

/*
* GL02Primitive.cpp: Vertex, Primitive and Color
* Draw Simple 2D colored Shapes: quad, triangle and polygon.
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Black and opaque
}

void window(float r, float g, float b, float blx, float bly, float brx, float bry, float urx, float ury, float ulx, float uly)
{
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(r, g, b);
    glVertex2f(blx, bly);
    glVertex2f(brx, bry);
    glVertex2f(urx, ury);
    glVertex2f(ulx, uly);
    glEnd();
}

void building(float r, float g, float b, float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy, float ex, float ey, float fx, float fy)
{
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glVertex2f(ex, ey);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(255, 255, 255);
    glVertex2f(dx, dy);
    glVertex2f(fx, fy);
    glEnd();

}

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


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    building(255, 255, 0, 0.2, 0.2, 0.7, 0.2, 0.7, 0.7, 0.6, 0.8, 0.2, 0.8, 0.6, 0.2);

    window(0, 0, 1, 0.22, 0.3, 0.58, 0.3, 0.58, 0.38, 0.22, 0.38);

    window(0, 0, 1, 0.22, 0.4, 0.58, 0.4, 0.58, 0.48, 0.22, 0.48);

    window(0, 0, 1, 0.22, 0.5, 0.58, 0.5, 0.58, 0.58, 0.22, 0.58);

    window(0, 0, 1, 0.22, 0.6, 0.58, 0.6, 0.58, 0.68, 0.22, 0.68);

    window(0, 0, 1, 0.22, 0.7, 0.58, 0.7, 0.58, 0.78, 0.22, 0.78);

    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    glVertex2f(0.35, 0.2);
    glVertex2f(0.45, 0.2);
    glVertex2f(0.45, 0.28);
    glVertex2f(0.35, 0.28);
    glEnd();

    //tree

    glBegin(GL_POLYGON);
    glColor3ub(255, 128, 0);
    glVertex2f(0.8, -0.2);
    glVertex2f(0.9, -0.2);
    glVertex2f(0.9, -0.45);
    glVertex2f(0.8, -0.45);
    glEnd();

    circle(0.2, 0.85, 0.0, 0, 255, 0);
    circle(0.175, 1.0, 0.0, 0, 255, 0);
    circle(0.175, 0.7, 0.0, 0, 255, 0);
    circle(0.175, 0.85, 0.2, 0, 255, 0);

    //lampost

    //light
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.2 - 0.3, 0.2 - 0.65);
    glVertex2f(0.7 - 0.3, 0.2 - 0.65);
    glVertex2f(0.5 - 0.3, 0.9 - 0.65);
    glVertex2f(0.4 - 0.3, 0.9 - 0.65);
    glEnd();

    //pole
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.37 - 0.3, 0.9 - 0.65);
    glVertex2f(0.52 - 0.3, 0.9 - 0.65);
    glVertex2f(0.52 - 0.3, 0.92 - 0.65);
    glVertex2f(0.37 - 0.3, 0.92 - 0.65);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.47 - 0.3, 0.92 - 0.65);
    glVertex2f(0.47 - 0.3, 0.97 - 0.65);
    glVertex2f(0.43 - 0.3, 0.97 - 0.65);
    glVertex2f(0.43 - 0.3, 0.92 - 0.65);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.47 - 0.3, 0.93 - 0.65);
    glVertex2f(0.47 - 0.3, 0.97 - 0.65);
    glVertex2f(0.8 - 0.3, 0.97 - 0.65);
    glVertex2f(0.8 - 0.3, 0.93 - 0.65);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.8 - 0.3, 0.25 - 0.65);
    glVertex2f(0.85 - 0.3, 0.25 - 0.65);
    glVertex2f(0.85 - 0.3, 0.97 - 0.65);
    glVertex2f(0.8 - 0.3, 0.97 - 0.65);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(128, 128, 128); // Yellow
    glVertex2f(0.75 - 0.3, 0.25 - 0.65);
    glVertex2f(0.9 - 0.3, 0.25 - 0.65);
    glVertex2f(0.9 - 0.3, 0.2 - 0.65);
    glVertex2f(0.75 - 0.3, 0.2 - 0.65);
    glEnd();

    //bench
    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 75, 0); // Yellow
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 75, 0); // Yellow
    glVertex2f(0.0f, -0.4f);
    glVertex2f(0.05f, -0.4f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 75, 0); // Yellow
    glVertex2f(0.0f, -0.2f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.35f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 75, 0); // Yellow
    glVertex2f(0.3f, -0.4f);
    glVertex2f(0.35f, -0.4f);
    glVertex2f(0.35f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 90, 0); // Yellow
    glVertex2f(0.0f, -0.4f);
    glVertex2f(0.05f, -0.4f);
    glVertex2f(0.05f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3ub(150, 90, 0); // Yellow
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.45f, -0.4f);
    glVertex2f(0.45f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(150, 90, 0);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.35f, 0.0f);
    glVertex2f(0.35f, -0.2f);
    glVertex2f(0.4f, -0.2f);
    glEnd();









    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(520, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(-0.4, 2, -2, 2);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}
