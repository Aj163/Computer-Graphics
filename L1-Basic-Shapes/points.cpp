/*
 * Compile with the followinng command
 * g++ points.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>

void drawPoints() {

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glBegin(GL_POINTS);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.5, 0.5);
        
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 0.0);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.2, -0.6);
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