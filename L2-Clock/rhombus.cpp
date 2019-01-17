/*
 * Compile with the followinng command
 * g++ rhombus.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

const double PI = 3.14159265358979323;

void drawRhombus() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.3);
        glVertex2f(0.7, 0.0);
        glVertex2f(0.0, -0.3);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, -0.3);
        glVertex2f(-0.7, 0.0);
        glVertex2f(0.0, 0.3);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rhombus");
    glutDisplayFunc(drawRhombus);
    glutMainLoop();
}