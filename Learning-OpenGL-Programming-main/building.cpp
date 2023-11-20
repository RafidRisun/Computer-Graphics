//Draw Ploygon

/*
* GL02Primitive.cpp: Vertex, Primitive and Color
* Draw Simple 2D colored Shapes: quad, triangle and polygon.
*/
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

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




    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    gluOrtho2D(0, 1, 0, 1);
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}