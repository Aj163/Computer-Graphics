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

void drawFlag() {
    
    glClear(GL_COLOR_BUFFER_BIT);

    // Pole
    glBegin(GL_POLYGON);
        glColor3f(147.0/255, 147.0/255, 147.0/255);
        glVertex2f(-0.6, -0.8);
        glVertex2f(-0.57, -0.8);
        glVertex2f(-0.57, 0.75);
        glVertex2f(-0.6, 0.75);
    glEnd();

    // Left rectangle
    glBegin(GL_POLYGON);
        glColor3f(0.0/255, 51.0/255, 255.0/255);
        glVertex2f(-0.57, 0.7);
        glVertex2f(-0.207, 0.7);
        glVertex2f(-0.207, 0.1);
        glVertex2f(-0.57, 0.1);
    glEnd();

    // Middle rectangle
    glBegin(GL_POLYGON);
        glColor3f(255.0/255, 255.0/255, 255.0/255);
        glVertex2f(-0.207, 0.7);
        glVertex2f(0.167, 0.7);
        glVertex2f(0.167, 0.1);
        glVertex2f(-0.207, 0.1);
    glEnd();

    // Right rectangle
    glBegin(GL_POLYGON);
        glColor3f(226.0/255, 34.0/255, 0.0/255);
        glVertex2f(0.167, 0.7);
        glVertex2f(0.5, 0.7);
        glVertex2f(0.5, 0.1);
        glVertex2f(0.167, 0.1);
    glEnd();

    

    

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