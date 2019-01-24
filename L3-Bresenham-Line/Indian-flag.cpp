/*
 * Compile with the followinng command
 * g++ Indian-flag.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600

using namespace std;

const double PI = 3.14159265358979323;

void drawFlag() {
    
    glClear(GL_COLOR_BUFFER_BIT);

    // Pole
    glBegin(GL_POLYGON);
        glColor3f(184.0/255, 188.0/255, 181.0/255);
        glVertex2f(-0.6, -0.8);
        glVertex2f(-0.57, -0.8);
        glVertex2f(-0.57, 0.75);
        glVertex2f(-0.6, 0.75);
    glEnd();

    // Upper rectangle
    glBegin(GL_POLYGON);
        glColor3f(255.0/255, 153.0/255, 51.0/255);
        glVertex2f(-0.57, 0.7);
        glVertex2f(0.5, 0.7);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.57, 0.5);
    glEnd();

    // Middle rectangle
    glBegin(GL_POLYGON);
        glColor3f(255.0/255, 255.0/255, 255.0/255);
        glVertex2f(-0.57, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, 0.3);
        glVertex2f(-0.57, 0.3);
    glEnd();

    // Lower rectangle
    glBegin(GL_POLYGON);
        glColor3f(18.0/255, 136.0/255, 7.0/255);
        glVertex2f(-0.57, 0.3);
        glVertex2f(0.5, 0.3);
        glVertex2f(0.5, 0.1);
        glVertex2f(-0.57, 0.1);
    glEnd();

    // Circle
    glPointSize(3);
    glBegin(GL_POINTS);
        glColor3f(0.0/255, 0.0/255, 136.0/255);
        for(int theta=0; theta<360; theta++) {
            double ang = theta / 360.0 * 2 * PI;
            glVertex2f(0.085 * cos(ang) - 0.03, 0.085 * sin(ang) + 0.4);
        }
    glEnd();

    // Strokes
    glPointSize(1);
    for(int stroke=0; stroke<24; stroke++) {
        double ang = stroke / 24.0 * 2 * PI;
        glBegin(GL_LINES);
            glVertex2f(-0.03, 0.4);
            glVertex2f(-0.03 + 0.075 * cos(ang), 0.4 + 0.075 * sin(ang));
        glEnd();
    }

    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flag");
    glutDisplayFunc(drawFlag);
    glutMainLoop();
}