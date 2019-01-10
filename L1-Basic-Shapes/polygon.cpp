/*
 * Compile with the followinng command
 * g++ polygon.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

const double PI = 3.14159265358979323;

void drawPolygon() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        for(int theta=0; theta<3600; theta++) {
            double ang = theta * 1.0 / 20 / PI;
            double r = 0.5 + 0.3 * sin(ang*10);

            glColor3f(abs(sin(4*ang)), 0.0,  0.0);
            glVertex2f(r * cos(ang), r * sin(ang));
        }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Polygon");
    glutDisplayFunc(drawPolygon);
    glutMainLoop();
}