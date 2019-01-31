/*
 * Compile with the followinng command
 * g++ chess_board.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600

using namespace std;

const double PI = 3.14159265358979323;

void drawChessBoard() {

    glClear(GL_COLOR_BUFFER_BIT);

    // Border
    glBegin(GL_POLYGON);
        glColor3f(255.0/255, 170.0/255, 0.0/255);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);
        glVertex2f(-1.0, 1.0);
    glEnd();

    // Squares
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++) {
            glBegin(GL_POLYGON);
                if(((i*8 + j) % 2 && i % 2 == 0) || ((i*8 + j) % 2 == 0 && i % 2))
                    glColor3f(255.0/255, 0.0/255, 0.0/255); // Red
                else
                    glColor3f(0.0/255, 0.0/255, 0.0/255); // Black

                glVertex2f(-0.95 + j*1.9/8,     0.95 - i*1.9/8);
                glVertex2f(-0.95 + (j+1)*1.9/8, 0.95 - i*1.9/8);
                glVertex2f(-0.95 + (j+1)*1.9/8, 0.95 - (i+1)*1.9/8);
                glVertex2f(-0.95 + j*1.9/8,     0.95 - (i+1)*1.9/8);
            glEnd();
        }
    
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(drawChessBoard);
    glutMainLoop();
}