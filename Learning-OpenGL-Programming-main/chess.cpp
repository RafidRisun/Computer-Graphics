#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 0.0f); // black
    glVertex2f(0.2f, 0.2f);    // x, y
    glVertex2f(1.0f, 0.2f);    // x, y
    glVertex2f(1.0f, 0.2f);    // x, y
    glVertex2f(1.0f, 1.0f);    // x, y
    glVertex2f(1.0f, 1.0f);    // x, y
    glVertex2f(0.2f, 1.0f);    // x, y
    glVertex2f(0.2f, 1.0f);    // x, y
    glVertex2f(0.2f, 0.2f);    // x, y

    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.2f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.8f, 0.2f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.6f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.6f, 0.4f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.8f, 0.4f);
    glVertex2f(1.0f, 0.4f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(0.8f, 0.6f);
    glEnd();



    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glVertex2f(0.4f, 0.8f);
    glVertex2f(0.2f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.8f, 0.6f);
    glVertex2f(0.8f, 0.8f);
    glVertex2f(0.6f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.4f, 0.8f);
    glVertex2f(0.6f, 0.8f);
    glVertex2f(0.6f, 1.0f);
    glVertex2f(0.4f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);            // These vertices form a closed polygon
    glColor3f(0.0f, 0.0f, 0.0f); // 
    glVertex2f(0.8f, 0.8f);
    glVertex2f(1.0f, 0.8f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.8f, 1.0f);
    glEnd();


    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    glutInitWindowSize(600, 600);   // Set the window's initial width & height
    glutInitWindowPosition(120, 60); // Position the window's initial top-left corner
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    gluOrtho2D(0, 1.2, 0, 1.2);
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}