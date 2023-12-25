
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Initialize OpenGL Graphics */
void initGL() {
    glLineWidth(4);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 21.34, 0, 16);
}

void line(float r, float g, float b, float ax, float ay, float bx, float by) {
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
    glColor3ub(r, g, b);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glEnd();

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

void cloudRain()
{
    //clouds
    circle(0.53, 3.2, 13.77608, 192, 192, 192); //g3
    circle(0.53, 3.64498, 14.43981, 119, 135, 140); //g7
    circle(0.53, 3.73234, 14.37783, 192, 192, 192); //g1
    circle(0.53, 4.53612, 14.29836, 119, 135, 140); //g6
    circle(0.53, 4.21186, 13.71966, 192, 192, 192); //g4
    circle(0.53, 4.57855, 14.27277, 192, 192, 192); //g5
    circle(0.53, 5, 13.85, 192, 192, 192); //g2

}

void cloud2Rain() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloudRain();
    glPopMatrix();
}

void cloud3Rain() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloud2Rain();
    glPopMatrix();
}

void cloud4Rain() {
    glPushMatrix();
    glTranslatef(12.5f, 0.0f, 0.0f); // Translate the cloud
    cloud3Rain();
    glPopMatrix();
}

float cloudmoveRain = 0.0f;

void cloudupdateRain(int value) {

    cloudmoveRain -= .01;
    if (cloudmoveRain < -24.34)
    {
        cloudmoveRain = 0;
    }


    glutPostRedisplay();
    glutTimerFunc(100, cloudupdateRain, 0);
}

void cloudTranslateRain() {
    glPushMatrix();
    glTranslatef(cloudmoveRain, 0, 0);
    cloudRain();
    cloud2Rain();
    cloud3Rain();
    cloud4Rain();
    glPopMatrix();
}

void water() {
    quad(98, 160, 181, 0, 0, 21.34, 0, 21.34, 7.6, 0, 7.6);
}

void waterRain() {
    quad(81, 133, 147, 0, 0, 21.34, 0, 21.34, 7.6, 0, 7.6);
}

void horizon() {
    quad(80, 127, 69, 0, 7.6, 21.34, 7.6, 21.34, 8, 0, 8);
}

void sky() {
    quad(207, 240, 255, 0, 8, 21.34, 8, 21.34, 16, 0, 16);
}

void skyRain() {
    quad(119, 135, 140, 0, 8, 21.34, 8, 21.34, 16, 0, 16);
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

void buildingsFromFarRain() {
    quad(47, 107, 112, 0, 8, 0, 12, 2.5, 12, 2.5, 8);
    quad(47, 107, 112, 2.5, 8, 2.5, 11, 4.2, 11, 4.2, 8);
    quad(47, 107, 112, 4.2, 8, 4.2, 13.2, 6.8, 13.2, 6.8, 8);
    quad(47, 107, 112, 6.8, 8, 6.8, 12, 8.5, 12, 8.5, 8);
    quad(47, 107, 112, 9.6, 8, 9.6, 11.5, 11.4, 11.5, 11.4, 8);
    quad(47, 107, 112, 11.4, 8, 11.4, 13.2, 13.9, 13.2, 13.9, 8);
    quad(47, 107, 112, 13.9, 8, 13.9, 11.5, 16.3, 11.5, 16.3, 8);
    quad(47, 107, 112, 16.3, 8, 16.3, 9.8, 18.1, 9.8, 18.1, 8);
    quad(47, 107, 112, 18.1, 8, 18.1, 13.2, 20.7, 13.2, 20.7, 8);
    quad(47, 107, 112, 20.7, 8, 20.7, 10.6, 21.34, 10.6, 21.34, 8);
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

void watertaxi() {

    //inner side
    quad(119, 3, 3, 7.56165, 5.13393, 14.33911, 5.14831, 14.37163, 4.44657, 10.5595, 4.35327);

    //bars
    line(104, 104, 104, 9.28911, 5.32142, 9.28478, 4.90991);
    line(104, 104, 104, 10.02445, 5.23365, 10.02458, 4.83431);
    line(104, 104, 104, 11, 5.2, 11, 4.8);
    line(104, 104, 104, 12.12676, 5.21572, 12.12341, 4.82426);
    line(104, 104, 104, 13.12082, 5.60798, 13.11157, 4.85086);

    line(255, 255, 255, 9.03328, 5.3226, 9.03723, 4.97094);
    line(255, 255, 255, 9.92229, 5.21987, 9.92229, 4.86821);
    line(255, 255, 255, 10.85081, 5.20011, 10.85477, 4.805);
    line(255, 255, 255, 11.8, 5.2, 11.7865, 4.82751);
    line(255, 255, 255, 12.72743, 5.24251, 12.73565, 4.85627);
    line(255, 255, 255, 12.73565, 5.03295, 11.79598, 5.01671);
    line(255, 255, 255, 11.79598, 5.01671, 10.85035, 5.01592);
    line(255, 255, 255, 10.85035, 5.01592, 9.92661, 5.05793);
    line(255, 255, 255, 9.92661, 5.05793, 9.03641, 5.13291);

    //shadow
    quad(65, 116, 130, 7.49835, 4.37348, 7.5087, 4.5432, 14.75213, 4.53918, 14.81733, 4.33729);

    //engine
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(14.38008, 4.73248);
    glVertex2f(14.37745, 5.09154);
    glVertex2f(14.55106, 5.20334);
    glVertex2f(15.03376, 5.00473);
    glVertex2f(14.96668, 4.71012);
    glVertex2f(14.73257, 4.67592);
    glEnd();
    quad(0, 0, 0, 14.46522, 4.40527, 14.38008, 4.73248, 14.73257, 4.67592, 14.76669, 4.40417);


    //outer side
    quad(255, 0, 0, 7.5087, 4.5432, 8.05091, 5.08055, 10.53342, 4.81296, 10.5595, 4.35327);
    triangle(255, 0, 0, 7.65505, 4.64911, 8.05091, 5.08055, 7.56165, 5.13393);
    quad(255, 0, 0, 10.53342, 4.81296, 10.5595, 4.35327, 14.37163, 4.44657, 13.25005, 4.87383);
    triangle(255, 0, 0, 14.37163, 4.44657, 13.25005, 4.87383, 14.33911, 5.14831);
    quad(255, 0, 0, 14.37163, 4.44657, 14.3558, 4.7393, 14.62288, 4.71696, 14.76118, 4.44331);

    //shade
    glBegin(GL_POLYGON);
    glColor3ub(87, 116, 156);
    glVertex2f(8.70091, 5.4919);
    glVertex2f(9.10622, 5.70956);
    glVertex2f(13.12082, 5.60798);
    glVertex2f(13.00242, 5.38194);
    glVertex2f(10.47601, 5.33053);
    glEnd();

    //sides
    quad(132, 30, 77, 8.70091, 5.4919, 8.75345, 5.34929, 9.56031, 5.25172, 9.6, 5.42);
    quad(132, 30, 77, 10.47601, 5.33053, 10.52479, 5.18416, 11.34667, 5.20293, 11.34667, 5.3568);
    quad(132, 30, 77, 12.23288, 5.37206, 12.26744, 5.20286, 13.00029, 5.24236, 13.00242, 5.38194);

    quad(246, 229, 2, 9.6, 5.4, 9.63162, 5.2367, 10.45724, 5.18416, 10.47601, 5.33053);
    quad(246, 229, 2, 11.34667, 5.3568, 11.4, 5.2, 12.2, 5.2, 12.23288, 5.37206);

    triangle(225, 236, 239, 7.73681, 4.31673, 7.53524, 4.48183, 8.41638, 4.39544);
    triangle(225, 236, 239, 13.90208, 4.22356, 13.68142, 4.37876, 14.58835, 4.37876);
    triangle(225, 236, 239, 14.90104, 4.39809, 14.87649, 4.56258, 16.12609, 4.56503);


}

void land() {
    quad(140, 198, 63, 0, 6.47, 3.85052, 7.20632, 1.77069, 8.71743, 0, 8.71743);
    quad(140, 198, 63, 21.33779, 6.73928, 17.24857, 7.54775, 19.00612, 8.74288, 21.31436, 8.74288);
}

void landRain() {
    quad(124, 163, 62, 0, 6.47, 3.85052, 7.20632, 1.77069, 8.71743, 0, 8.71743);
    quad(124, 163, 62, 21.33779, 6.73928, 17.24857, 7.54775, 19.00612, 8.74288, 21.31436, 8.74288);
}

float carmove = 0;

void car1() {

    glPushMatrix();
    glTranslatef(carmove, -0.2, 0);
    //body
    glBegin(GL_POLYGON);
    glColor3ub(0, 89, 186);
    glVertex2f(9.03829, 8.58235);
    glVertex2f(8.95, 8.8);
    glVertex2f(8.94442, 8.97557);
    glVertex2f(9.26679, 9.05882);
    glVertex2f(9.76628, 9.09778);
    glVertex2f(9.75742, 8.53098);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 89, 186);
    glVertex2f(9.75742, 8.53098);
    glVertex2f(9.76628, 9.09778);
    glVertex2f(10.21618, 9.43786);
    glVertex2f(11.20277, 9.43786);
    glVertex2f(11.80999, 9.04595);
    glVertex2f(11.79702, 8.69327);
    glVertex2f(11.71663, 8.60769);
    glVertex2f(11.03719, 8.53248);
    glEnd();

    //window
    quad(135, 206, 250, 9.86083, 9.09817, 10.24829, 9.39654, 10.70205, 9.38825, 10.67512, 9.10024);
    quad(135, 206, 250, 10.74142, 9.10646, 10.74971, 9.39446, 11.15582, 9.40068, 11.48588, 9.14506);

    //wheel1
    circle(0.22360679775, 9.35814, 8.56342, 50, 50, 50);
    circle(0.12360679775, 9.35814, 8.56342, 150, 150, 150);

    //wheel2
    circle(0.22360679775, 11.31459, 8.56342, 50, 50, 50);
    circle(0.12360679775, 11.31459, 8.56342, 150, 150, 150);

    //bumper
    quad(112, 128, 144, 8.90596, 8.73523, 8.90596, 8.80354, 9.05624, 8.80081, 9.0535, 8.7325);
    quad(112, 128, 144, 11.60954, 8.73377, 11.60856, 8.79962, 11.86787, 8.80081, 11.86241, 8.72704);

    glPopMatrix();
}

void car1update(int value) {
    carmove -= 0.02;
    if (carmove < -20) {
        carmove = 15;
    }
    glutPostRedisplay();
    glutTimerFunc(5, car1update, 0);
}

float carmove2 = 0;

void car2() {
    glPushMatrix();
    glTranslatef(carmove2, -0.2, 0); // Adjusted the translation with the negative of carmove
    // body
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(-9.03829, 8.58235);
    glVertex2f(-8.95, 8.8);
    glVertex2f(-8.94442, 8.97557);
    glVertex2f(-9.26679, 9.05882);
    glVertex2f(-9.76628, 9.09778);
    glVertex2f(-9.75742, 8.53098);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(-9.75742, 8.53098);
    glVertex2f(-9.76628, 9.09778);
    glVertex2f(-10.21618, 9.43786);
    glVertex2f(-11.20277, 9.43786);
    glVertex2f(-11.80999, 9.04595);
    glVertex2f(-11.79702, 8.69327);
    glVertex2f(-11.71663, 8.60769);
    glVertex2f(-11.03719, 8.53248);
    glEnd();

    // window
    quad(135, 206, 250, -9.86083, 9.09817, -10.24829, 9.39654, -10.70205, 9.38825, -10.67512, 9.10024);
    quad(135, 206, 250, -10.74142, 9.10646, -10.74971, 9.39446, -11.15582, 9.40068, -11.48588, 9.14506);

    // wheel1
    circle(0.22360679775, -9.35814, 8.56342, 50, 50, 50);
    circle(0.12360679775, -9.35814, 8.56342, 150, 150, 150);

    // wheel2
    circle(0.22360679775, -11.31459, 8.56342, 50, 50, 50);
    circle(0.12360679775, -11.31459, 8.56342, 150, 150, 150);

    // bumper
    quad(112, 128, 144, -8.90596, 8.73523, -8.90596, 8.80354, -9.05624, 8.80081, -9.0535, 8.7325);
    quad(112, 128, 144, -11.60954, 8.73377, -11.60856, 8.79962, -11.86787, 8.80081, -11.86241, 8.72704);

    glPopMatrix();

}

void car2update(int value) {
    carmove2 += 0.05;
    if (carmove2 > 35) {
        carmove2 = -5;
    }
    glutPostRedisplay();
    glutTimerFunc(5, car2update, 0);
}



void bridge() {
    quad(211, 211, 211, 3, 7.8, 2.42487, 8.14993, 4.10807, 10.56884, 4.11434, 9.91399);
    quad(211, 211, 211, 4.10807, 10.56884, 4.11434, 9.91399, 6.8, 7.6, 6.5853, 8.6698);
    quad(211, 211, 211, 6.8, 7.6, 6.5853, 8.6698, 10.33136, 11.1882, 10.29139, 10.73854);
    quad(211, 211, 211, 10.33136, 11.1882, 10.29139, 10.73854, 14.06479, 7.44043, 14.13994, 8.69514);
    quad(211, 211, 211, 14.06479, 7.44043, 14.13994, 8.69514, 16.57562, 10.56147, 16.6262, 9.8211);
    quad(211, 211, 211, 16.57562, 10.56147, 16.6262, 9.8211, 17.66542, 7.81826, 18.3807, 8.26837);
    car1();
    car2();

    quad(132, 132, 132, 18.12696, 8.03385, 17.89094, 8.48198, 2.87956, 8.48198, 2.63322, 8.03385);

    quad(132, 132, 132, 6.22474, 7.3, 6.80971, 7.3, 6.81321, 7.77361, 6.22474, 7.64751);
    quad(132, 132, 132, 14.05998, 7.309, 14.64194, 7.309, 14.64194, 7.72607, 14.06322, 7.70021);

    quad(247, 247, 247, 2.5105, 7.794, 1.77585, 8.27196, 3.71427, 10.70605, 3.78508, 10.17497);
    quad(247, 247, 247, 3.71427, 10.70605, 3.78508, 10.17497, 6.43159, 7.41339, 6.44929, 8.58175);
    quad(247, 247, 247, 6.43159, 7.41339, 6.44929, 8.58175, 10.33311, 11.34995, 10.35043, 10.90912);
    quad(247, 247, 247, 10.33311, 11.34995, 10.35043, 10.90912, 14.3437, 7.44354, 14.31084, 8.57718);
    quad(247, 247, 247, 14.3437, 7.44354, 14.31084, 8.57718, 17.06238, 10.7129, 17, 10.2);
    quad(247, 247, 247, 17.06238, 10.7129, 17, 10.2, 18.25133, 7.8003, 18.99551, 8.27387);

}

void bridgeshadow() {
    quad(82, 133, 145, 19.23567, 7.14246, 18.4, 7.3, 3.71048, 7.30619, 3.52152, 7.14188);
}

float wavemove = 0;
float wavemove1 = 0.1;

float pos = 0;
float moveboat = 0;

void waveTranslate() {
    glPushMatrix();
    glTranslatef(0, wavemove1, 0);
    wave1();
    wave2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, wavemove, 0);
    wave();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(moveboat, wavemove, 0);
    watertaxi(); //WATER TAXI <------------------------------------------------------------------- OVER HERE!!!
    glPopMatrix();


}

bool isMoving = false;

void moveupdate1(int value) {
    if (moveboat >= pos) {
        moveboat -= 0.07;
        glutPostRedisplay();
        glutTimerFunc(50, moveupdate1, 0);
    }
    else {
        isMoving = false;
    }
}

void moveupdate2(int value) {
    if (moveboat <= pos) {
        moveboat += 0.07;
        glutPostRedisplay();
        glutTimerFunc(50, moveupdate2, 0);
    }
    else {
        isMoving = false;
    }
}

void display1Rain();
void display1();
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        if (!isMoving) {
            pos -= 1.0f;
            glutTimerFunc(0, moveupdate1, 0);
            isMoving = true;
        }
        break;
    case 'd':
        if (!isMoving) {
            pos += 1.0f;
            glutTimerFunc(0, moveupdate2, 0);
            isMoving = true;
        }
        break;
    case 'A':
        if (!isMoving) {
            pos -= 1.0f;
            glutTimerFunc(0, moveupdate1, 0);
            isMoving = true;
        }
        break;
    case 'D':
        if (!isMoving) {
            pos += 1.0f;
            glutTimerFunc(0, moveupdate2, 0);
            isMoving = true;
        }
        break;
    case 'r':
        glutDisplayFunc(display1Rain);
        break;

    case 'R':
        glutDisplayFunc(display1Rain);
        break;

    case 's':
        glutDisplayFunc(display1);
        break;

    case 'S':
        glutDisplayFunc(display1);
        break;
    }
}

float waveIncrement = 0.01;
float waveIncrement1 = 0.01;
void waveupdate(int value) {
    if (wavemove <= -0.15 || wavemove >= 0.15) {
        waveIncrement = -waveIncrement; //Change direction
    }
    if (wavemove1 <= -0.15 || wavemove1 >= 0.15) {
        waveIncrement1 = -waveIncrement1;
    }

    wavemove += waveIncrement; //Increment decrement based on direction
    wavemove1 += waveIncrement1;
    glutPostRedisplay();
    glutTimerFunc(80, waveupdate, 0);
}

float breeze = 0;

void leaf() {
    glPushMatrix();
    glTranslatef(breeze, 0, 0);
    triangle(57, 181, 74, 18.34513, 10.17111, 19.29811, 10.16576, 18.82698, 9.3493);
    triangle(57, 181, 74, 18.97421, 10.07207, 19.91916, 10.07474, 19.44802, 9.25293);
    triangle(57, 181, 74, 18.65426, 9.77189, 19.60626, 9.77467, 19.12191, 8.95351);
    triangle(0, 104, 55, 19.41141, 8.84216, 19.89019, 9.68003, 18.92427, 9.6689);
    triangle(0, 104, 55, 18.16156, 9.73014, 19.12191, 9.72735, 18.64313, 8.91454);
    triangle(0, 146, 69, 17.9862, 9.67168, 18.46776, 8.84216, 18.95371, 9.67309);
    triangle(0, 146, 69, 18.15873, 9.95785, 18.64086, 9.12999, 19.11594, 9.95785);
    triangle(0, 146, 69, 19.89891, 8.83756, 19.41894, 9.67041, 20.37618, 9.67121);
    triangle(0, 146, 69, 19.15393, 9.88976, 20.12121, 9.89179, 19.63555, 9.06414);
    glPopMatrix();
}

float breezeIncrement = 0.01;
void breezeupdate(int value) {
    if (breeze <= -0.01 || breeze >= 0.01) {
        breezeIncrement = -breezeIncrement;
    }

    breeze += breezeIncrement;
    glutPostRedisplay();
    glutTimerFunc(170, breezeupdate, 0);
}



void tree() {
    leaf();

    quad(117, 76, 36, 19.04714, 8.53238, 19.25545, 8.52643, 19.25435, 9.14741, 19.05155, 9.15622);
    quad(117, 76, 36, 18.92643, 7.94738, 19.15377, 9.14756, 19.19607, 9.16077, 19.22515, 7.95003);
    triangle(117, 76, 36, 19.21536, 8.97311, 19.80087, 9.45137, 19.19607, 9.16077);
    quad(140, 98, 57, 19.22515, 7.95003, 19.42277, 7.94447, 19.25545, 8.52643, 19.19607, 9.16077);
    triangle(140, 98, 57, 19.03964, 8.35912, 19.15377, 9.14756, 19.06874, 8.99927);
    triangle(140, 98, 57, 19.06874, 8.99927, 19.15377, 9.14756, 18.50618, 9.44786);
}

void tree2() {
    glPushMatrix();
    glTranslatef(1.5, .5, 0);

    tree();
    glPopMatrix();
}

void tree3() {
    glPushMatrix();
    glTranslatef(-17.5, -0.5, 0);

    tree();
    glPopMatrix();
}

void tree4() {
    glPushMatrix();
    glTranslatef(-18.5, 0.5, 0);

    tree();
    glPopMatrix();
}

void tree5() {
    glPushMatrix();
    glTranslatef(0.7, 2.5, 0);
    glScalef(0.7, 0.7, 0);

    tree();
    glPopMatrix();
}

void tree6() {
    glPushMatrix();
    glTranslatef(-7, 2.4, 0);
    glScalef(0.7, 0.7, 0);

    tree();
    glPopMatrix();
}
//building window
void window(float r, float g, float b, float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
    quad(r, g, b, ax, ay, bx, by, cx, cy, dx, dy);
    quad(r, g, b, ax, ay + 0.58257, bx, by + 0.58257, cx, cy + 0.58257, dx, dy + 0.58257);
    quad(r, g, b, ax, ay + 0.58257 * 2, bx, by + 0.58257 * 2, cx, cy + 0.58257 * 2, dx, dy + 0.58257 * 2);
    quad(r, g, b, ax, ay + 0.58257 * 3, bx, by + 0.58257 * 3, cx, cy + 0.58257 * 3, dx, dy + 0.58257 * 3);
    quad(r, g, b, ax, ay + 0.58257 * 4, bx, by + 0.58257 * 4, cx, cy + 0.58257 * 4, dx, dy + 0.58257 * 4);
    quad(r, g, b, ax, ay + 0.58257 * 5, bx, by + 0.58257 * 5, cx, cy + 0.58257 * 5, dx, dy + 0.58257 * 5);
}

void buildings() {

    //from left to right
    //1
    quad(221, 221, 221, 0.1, 8, 0.1, 11.717, 3.69032, 11.717, 3.69032, 8);
    quad(179, 179, 179, 0.10076, 8, 0.10076, 11.32798, 0.82575, 11.32798, 0.80806, 8);
    quad(179, 179, 179, 0.10076 + 0.9, 8, 0.10076 + 0.9, 11.32798, 0.82575 + 0.9, 11.32798, 0.80806 + 0.9, 8);
    quad(179, 179, 179, 0.10076 + 1.8, 8, 0.10076 + 1.8, 11.32798, 0.82575 + 1.8, 11.32798, 0.80806 + 1.8, 8);
    quad(179, 179, 179, 0.10076 + 2.7, 8, 0.10076 + 2.7, 11.32798, 0.82575 + 2.7, 11.32798, 0.80806 + 2.7, 8);

    //windows
    window(255, 255, 255, 0.11416, 8.12395, 0.47867, 8.12395, 0.47837, 8.24887, 0.11271, 8.24605);
    window(255, 255, 255, 1.2, 8.11761, 1.5, 8.12069, 1.5, 8.25043, 1.2, 8.25043);
    window(255, 255, 255, 2.2, 8.09628, 2.5, 8.09628, 2.5, 8.23374, 2.2, 8.23013);
    window(255, 255, 255, 3.2, 8.08904, 3.5, 8.08542, 3.5, 8.23013, 3.2, 8.22289);


    //2
    quad(86, 34, 38, 5, 8, 5, 12.56388, 8, 12.56388, 8, 8);
    quad(147, 147, 147, 5, 8, 5, 12.56388, 6.67417, 12.56388, 6.67417, 8);
    quad(147, 147, 147, 7.21912, 8, 7.21912, 12.23485, 8, 12.23485, 8, 8);

    //windows
    window(255, 255, 0, 5.20016, 9.04032, 6.54435, 9.04032, 6.55099, 9.18636, 5.20229, 9.18492);
    window(255, 255, 255, 7.36958, 9.07138, 7.88251, 9.07387, 7.88251, 9.1884, 7.37207, 9.19338);

    //3
    quad(221, 221, 221, 8.47693, 8, 8.47693, 12.97489, 13.21478, 12.97489, 13.17688, 8);
    quad(155, 121, 121, 8.47693, 8, 8.5, 12.5, 9.28442, 12.5, 9.28626, 8);
    quad(155, 121, 121, 8.47693 + 1.26809, 8, 8.5 + 1.26809, 12.5, 9.28442 + 1.26809, 12.5, 9.28626 + 1.26809, 8);
    quad(155, 121, 121, 8.47693 + 2.53618, 8, 8.5 + 2.53618, 12.5, 9.28442 + 2.53618, 12.5, 9.28626 + 2.53618, 8);
    quad(155, 121, 121, 8.47693 + 3.80427, 8, 8.5 + 3.80427, 12.5, 9.28442 + 3.80427, 12.5, 9.28626 + 3.80427, 8);

    //window
    window(255, 255, 255, 8.49005, 8.9992, 8.9678, 9.01325, 8.9678, 9.18655, 8.49942, 9.18655);
    window(255, 255, 0, 9.97164, 9.00575, 10.45593, 9.00575, 10.45593, 9.18792, 9.97164, 9.18792);
    window(255, 255, 255, 11.31114, 8.98325, 11.79936, 8.98325, 11.79936, 9.16078, 11.31114, 9.16078);
    window(255, 255, 0, 12.57497, 8.99856, 12.97126, 8.99856, 12.97126, 9.17898, 12.57497, 9.17898);

    //4
    quad(114, 115, 117, 13.5, 8, 13.50127, 10.05494, 17.88258, 10.05494, 17.87601, 8);
    quad(170, 171, 173, 13.72461, 8.29454, 13.73118, 8.99082, 17.6461, 8.99082, 17.63954, 8.29454);
    quad(170, 171, 173, 13.71804, 9.18788, 13.71804, 9.87102, 17.63297, 9.87102, 17.6264, 9.18788);

    //window
    quad(255, 255, 0, 14.13338, 8.72311, 15.50519, 8.72311, 15.50519, 8.83191, 14.13338, 8.83191);
    quad(255, 255, 0, 15.94341, 8.72692, 17.31639, 8.72692, 17.31639, 8.82888, 15.94341, 8.83361);
    quad(255, 255, 0, 14.14005, 9.37251, 17.38691, 9.37251, 17.39489, 9.47622, 14.14005, 9.47622);
    quad(255, 255, 0, 14.13606, 9.64773, 17.38691, 9.64773, 17.3909, 9.76341, 14.14005, 9.75942);


}

float windmove = 0;

void wind() {

    glPushMatrix();
    glTranslatef(windmove, 0, 0);
    line(255, 255, 255, 27.80164, 8.51415, 23.76857, 8.51415);
    line(255, 255, 255, 23.76857, 8.51415, 23.56892, 8.44427);
    line(255, 255, 255, 23.83845, 8.81364, 23.5789, 8.93343);
    line(255, 255, 255, 27.21265, 8.81364, 24.35756, 8.79367);
    line(255, 255, 255, 24.08802, 8.92345, 24.35756, 8.79367);
    line(255, 255, 255, 27.81162, 9.13309, 25.17615, 9.10314);


    line(255, 255, 255, 27.80164 + 6, 8.51415 - 5, 23.76857 + 6, 8.51415 - 5);
    line(255, 255, 255, 23.76857 + 6, 8.51415 - 5, 23.56892 + 6, 8.44427 - 5);
    line(255, 255, 255, 23.83845 + 6, 8.81364 - 5, 23.5789 + 6, 8.93343 - 5);
    line(255, 255, 255, 27.21265 + 6, 8.81364 - 5, 24.35756 + 6, 8.79367 - 5);
    line(255, 255, 255, 24.08802 + 6, 8.92345 - 5, 24.35756 + 6, 8.79367 - 5);
    line(255, 255, 255, 27.81162 + 6, 9.13309 - 5, 25.17615 + 6, 9.10314 - 5);

    glPopMatrix();
}

void windupdate(int value) {
    windmove -= 0.05;
    if (windmove < -40) {
        windmove = 30;
    }
    glutPostRedisplay();
    glutTimerFunc(1, windupdate, 0);
}

float rainmove = 0;
float rainmove1 = 0;
void rain1() {
    glPushMatrix();
    glTranslatef(0, rainmove, 0);
    line(255, 255, 255, 1.98253, 1.01455, 2, 2); //QR
    line(255, 255, 255, 8, 4, 8.00509, 4.99962); // OP
    line(255, 255, 255, 14, 4, 13.95382, 5.02719); // IJ
    line(255, 255, 255, 18, 2, 17.95279, 1.01455); // ST
    line(255, 255, 255, 20, 6, 19.99027, 5.02958); // CD
    line(255, 255, 255, 18, 10, 17.97637, 8.90184); // KL
    line(255, 255, 255, 10.79164, 9.94351, 10.79164, 9.01466); // UV
    line(255, 255, 255, 4.01578, 7.03846, 4, 6); // GH
    line(255, 255, 255, 0.57427, 7.93599, 0.57427, 7.00714); // AB
    line(255, 255, 255, 2, 12, 2.0045, 11.03142); // MN
    line(255, 255, 255, 8, 14, 7.97916, 12.92439); // CD
    line(255, 255, 255, 14.01298, 14.81735, 13.9834, 13.54551); // EF
    line(255, 255, 255, 3.9862, 14.93566, 4, 16); // BA
    line(255, 255, 255, 19.03146, 14.97728, 19.03146, 15.99603); // WZ
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, rainmove1, 0);
    line(255, 255, 255, 6.98253, 6.01455, 7, 7); // QR
    line(255, 255, 255, 13, 9, 13.00509, 9.99962); // OP
    line(255, 255, 255, 19, 9, 18.95382, 10.02719); // IJ
    line(255, 255, 255, 23, 7, 22.95279, 6.01455); // ST
    line(255, 255, 255, 25, 11, 24.99027, 10.02958); // CD
    line(255, 255, 255, 23, 15, 22.97637, 13.90184); // KL
    line(255, 255, 255, 15.79164, 14.94351, 15.79164, 14.01466); // UV
    line(255, 255, 255, 9.01578, 12.03846, 9, 11); // GH
    line(255, 255, 255, 5.57427, 12.93599, 5.57427, 12.00714); // AB
    line(255, 255, 255, 7, 17, 7.0045, 16.03142); // MN
    line(255, 255, 255, 13, 19, 12.97916, 17.92439); // CD
    line(255, 255, 255, 19.01298, 19.81735, 18.9834, 18.54551); // EF
    line(255, 255, 255, 8.9862, 19.93566, 9, 21); // BA
    line(255, 255, 255, 24.03146, 19.97728, 24.03146, 20.99603); // WZ
    glPopMatrix();
}

void rainupdate(int value) {
    rainmove -= 0.01;
    if (rainmove < -10) {
        rainmove = 30;
    }
    rainmove1 -= 0.02;
    if (rainmove1 < -10) {
        rainmove1 = 30;
    }
    glutPostRedisplay();
    glutTimerFunc(0.1, rainupdate, 0);
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
    buildings();
    cloudTranslate();
    waveTranslate();

}



void background1Rain() {
    //water
    waterRain();
    //horizon
    horizon();
    //sky
    skyRain();
    //buildings from far
    buildingsFromFarRain();
    buildings();
    cloudTranslateRain();
    waveTranslate();

}

void display1() {
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    background();
    tree5();
    tree6();
    tree2();
    tree4();

    bridgeshadow();
    bridge();
    land();
    tree();
    tree3();

    wind();


    glFlush();
}

void display1Rain() {
    glClear(GL_COLOR_BUFFER_BIT);

    background1Rain();
    tree5();
    tree6();
    tree2();
    tree4();

    bridgeshadow();
    bridge();
    landRain();
    tree();
    tree3();

    wind();
    rain1();

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
    glutTimerFunc(0, cloudupdateRain, 0);
    glutTimerFunc(0, waveupdate, 0);
    glutTimerFunc(0, moveupdate1, 0);
    glutTimerFunc(0, moveupdate2, 0);
    glutTimerFunc(0, breezeupdate, 0);
    glutTimerFunc(0, car1update, 0);
    glutTimerFunc(0, car2update, 0);
    glutTimerFunc(0, windupdate, 0);
    glutTimerFunc(0, rainupdate, 0);
    initGL();                       // Our own OpenGL initialization
    glutKeyboardFunc(handleKeypress);
    glutFullScreen();                // Enter full screen mode
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}