/*
 * Compile with the followinng command
 * g++ initWindow.cpp -lglut
 */

#include <GL/freeglut.h>

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL");
    glutMainLoop();
}