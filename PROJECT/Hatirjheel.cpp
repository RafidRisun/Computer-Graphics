
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 21.34, 0, 16);
}

void quad(float r, float g, float b, float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
{
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();
}

void triangle(float r, float g, float b, float ax, float ay, float bx, float by, float cx, float cy)
{
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);

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

void cloud()
{
    //clouds
    circle(0.53, 3.2, 13.77608, 255, 255, 255); //g3
    circle(0.53, 3.64498, 14.43981, 207, 240, 255); //g7
    circle(0.53, 3.73234, 14.37783, 255, 255, 255); //g1
    circle(0.53, 4.53612, 14.29836, 207, 240, 255); //g6
    circle(0.53, 4.21186, 13.71966, 255, 255, 255); //g4
    circle(0.53, 4.57855, 14.27277, 255, 255, 255); //g5
    circle(0.53, 5, 13.85, 255, 255, 255); //g2

}

void cloud2() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloud();
    glPopMatrix();
}

void cloud3() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloud2();
    glPopMatrix();
}

void cloud4() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloud3();
    glPopMatrix();
}

float cloudmove = 0.0f;

void cloudupdate(int value) {

    cloudmove -= .01;
    if (cloudmove < -24.34)
    {
        cloudmove = 0;
    }


    glutPostRedisplay();
    glutTimerFunc(20, cloudupdate, 0);
}

void cloudTranslate() {
    glPushMatrix();
    glTranslatef(cloudmove, 0, 0);
    cloud();
    cloud2();
    cloud3();
    cloud4();
    glPopMatrix();
}

void water() {
    quad(98, 160, 181, 0, 0, 21.34, 0, 21.34, 7.6, 0, 7.6);
}

void horizon() {
    quad(80, 127, 69, 0, 7.6, 21.34, 7.6, 21.34, 8, 0, 8);
}

void sky() {
    quad(207, 240, 255, 0, 8, 21.34, 8, 21.34, 16, 0, 16);
}

void buildingsFromFar() {
    quad(167, 196, 206, 0, 8, 0, 12, 2.5, 12, 2.5, 8);
    quad(167, 196, 206, 2.5, 8, 2.5, 11, 4.2, 11, 4.2, 8);
    quad(167, 196, 206, 4.2, 8, 4.2, 13.2, 6.8, 13.2, 6.8, 8);
    quad(167, 196, 206, 6.8, 8, 6.8, 12, 8.5, 12, 8.5, 8);
    quad(167, 196, 206, 9.6, 8, 9.6, 11.5, 11.4, 11.5, 11.4, 8);
    quad(167, 196, 206, 11.4, 8, 11.4, 13.2, 13.9, 13.2, 13.9, 8);
    quad(167, 196, 206, 13.9, 8, 13.9, 11.5, 16.3, 11.5, 16.3, 8);
    quad(167, 196, 206, 16.3, 8, 16.3, 9.8, 18.1, 9.8, 18.1, 8);
    quad(167, 196, 206, 18.1, 8, 18.1, 13.2, 20.7, 13.2, 20.7, 8);
    quad(167, 196, 206, 20.7, 8, 20.7, 10.6, 21.34, 10.6, 21.34, 8);
}

void wave() {
    triangle(124, 197, 216, 5.73174, 2.38493, 7.81204, 2.64988, 5.11353, 2.90501);
    triangle(124, 197, 216, 7.17421, 1.91392, 6.55601, 2.42419, 9.20546, 2.18868);
    triangle(124, 197, 216, 9.68629, 2.02186, 9.09752, 2.54194, 11.75678, 2.28681);
}

void wave1() {
    glPushMatrix();
    glTranslatef(0.5, 4.5, 0);
    glScalef(0.5f, 0.5f, 0.0f);
    wave();
    glPopMatrix();
}

void wave2() {
    glPushMatrix();
    glTranslatef(10, 4.5, 0);
    glScalef(0.5f, 0.5f, 0.0f);
    wave();
    glPopMatrix();
}

float wavemove = 0;

void waveTranslate() {
    glPushMatrix();
    glTranslatef(0, wavemove, 0);
    wave();
    wave1();
    wave2();
    glPopMatrix();
}

float waveIncrement = 0.01; // Define the increment value
void waveupdate(int value) {
    // Check the direction of movement and toggle it when the condition is met
    if (wavemove <= -0.2 || wavemove >= 0.2) {
        waveIncrement = -waveIncrement; // Change direction
    }

    wavemove += waveIncrement; // Increment or decrement based on the direction
    glutPostRedisplay();
    glutTimerFunc(150, waveupdate, 0);
}

void watertaxi() {

    //inner side
    quad(119, 3, 3, 7.56165, 5.13393, 14.33911, 5.14831, 14.37163, 4.44657, 10.5595, 4.35327);
    //outer side
    quad(255, 0, 0, 7.5087, 4.5432, 8.05091, 5.08055, 10.53342, 4.81296, 10.5595, 4.35327);
    triangle(255, 0, 0, 7.65505, 4.64911, 8.05091, 5.08055, 7.56165, 5.13393);
    quad(255, 0, 0, 10.53342, 4.81296, 10.5595, 4.35327, 14.37163, 4.44657, 13.25005, 4.87383);
    triangle(255, 0, 0, 14.37163, 4.44657, 13.25005, 4.87383, 14.33911, 5.14831);
    quad(255, 0, 0, 14.37163, 4.44657, 14.3558, 4.7393, 14.62288, 4.71696, 14.76118, 4.44331);

    glBegin(GL_POLYGON);
    glColor3ub(87, 116, 156);
    glVertex2f(8.70091, 5.4919);
    glVertex2f(9.10622, 5.70956);
    glVertex2f(13.12082, 5.60798);
    glVertex2f(13.00242, 5.38194);
    glVertex2f(10.47601, 5.33053);
    glEnd();


}

void background() {
    //water
    water();
    //horizon
    horizon();
    //sky
    sky();
    //buildings from far
    buildingsFromFar();
    cloudTranslate();
    waveTranslate();

}

void display1() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    background();
    watertaxi();




    glFlush();
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Hatirjheel");  // Create window with the given title
    glutInitWindowSize(1024, 768);   // Set the window's initial width & height
    glutInitWindowPosition(120, 60); // Position the window's initial top-left corner
    gluOrtho2D(0, 21.34, 0, 16);
    glutDisplayFunc(display1);       // Register callback handler for window re-paint event
    glutTimerFunc(0, cloudupdate, 0);
    glutTimerFunc(0, waveupdate, 0);
    initGL();                       // Our own OpenGL initialization
    glutFullScreen();                // Enter full screen mode
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}