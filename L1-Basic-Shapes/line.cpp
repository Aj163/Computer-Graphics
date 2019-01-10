/*
 * Compile with the followinng command
 * g++ line.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

void drawPoints() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        double x1, y1, x2, y2;
        printf("Enter x1 y1 x2 y2 : ");
        scanf("%lf%lf", &x1, &y1);
        scanf("%lf%lf", &x2, &y2);

        glColor3f(0.0, 0.0, 1.0);
        for(int step=0; step<1000; step++) {
            double X, Y, frac;
            frac = step * 1.0 / 1000;
            X = x1 + frac * (x2 - x1);
            Y = y1 + frac * (y2 - y1);
            glVertex2f(X, Y);
        }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Points");
    glutDisplayFunc(drawPoints);
    glutMainLoop();
}