/*
 * Compile with the followinng command
 * g++ dodecagon.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

const double PI = 3.14159265358979323;

void drawDodecagon() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        for(int theta=0; theta<12; theta++) {
            double ang = (theta / 12.0 * 360.0) * PI / 180;
            double r = 0.5;
            glVertex2f(r * cos(ang), r * sin(ang));
        }
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    for(int i=0; i<12; i++) {
        glBegin(GL_LINES);
            glVertex2f(0.0, 0.0);
            double ang = (i / 12.0 * 360.0) * PI / 180;
            double r = 0.5;
            glVertex2f(r * cos(ang), r * sin(ang));
        glEnd();
    }
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Dodecagon");
    glutDisplayFunc(drawDodecagon);
    glutMainLoop();
}