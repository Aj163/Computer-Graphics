/*
 * Compile with the followinng command
 * g++ moon.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600
const double PI = 3.14159265358979323;
using namespace std;

void drawMoon() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        for(int theta=0; theta<360; theta++) {
            double ang = theta * PI / 180;
            double r = 0.50;

            glColor3f(max(cos(ang), sin(ang)) / 1.5, max(cos(ang), sin(ang)) / 1.5, max(cos(ang), sin(ang)) / 1.5);
            glVertex2f(r * cos(ang), r * sin(ang));
        }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Moon");
    glutDisplayFunc(drawMoon);
    glutMainLoop();
}