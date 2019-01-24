/*
 * Compile with the followinng command
 * g++ France-flag.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600

using namespace std;

const double PI = 3.14159265358979323;

void drawCup() {
    
    glClear(GL_COLOR_BUFFER_BIT);

    // Semi-ellipse
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        for(int theta=0; theta<180; theta++) {
            double ang = -theta / 360.0 * 2 * PI;
            glVertex2f(0.5 * cos(ang), 0.5 + sin(ang));
        }
    glEnd();

    // Handle
    glPointSize(5);
    glBegin(GL_POINTS);
        for(int theta=0; theta<360; theta++) {
            double ang = theta / 360.0 * 2 * PI;
            glVertex2f(0.45 + 0.2 * cos(ang), 0.2 + 0.25 * sin(ang));
        }
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cup");
    glutDisplayFunc(drawCup);
    glutMainLoop();
}