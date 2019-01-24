/*
 * Compile with the followinng command
 * g++ bresenham-line.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600

using namespace std;

const double PI = 3.14159265358979323;
int X1, X2, Y1, Y2;

void putpixel(int x, int y) {

    glVertex2f(x * 2.0 / WIDTH - 1.0, y * 2.0 / HEIGHT - 1.0);
}

void drawLine() {
    
    glClear(GL_COLOR_BUFFER_BIT);

    int delta_x = (X2 - X1);
    int delta_y = (Y2 - Y1);

    glPointSize(3);
    glBegin(GL_POINTS);

        // Axis
        glColor3f(0.0/255, 160.0/255, 152.0/255);
        for(int i=0; i<WIDTH; i++)
            putpixel(i, 0);
        for(int i=0; i<HEIGHT; i++)
            putpixel(0, i);

        glColor3f(255.0/255, 255.0/255, 255.0/255);
        putpixel(X1, Y1);
        if(X1 == X2 && Y1 == Y2)
            return;

        if(delta_x < delta_y) {
            // Slope > 1
            for(int i=0; i<abs(delta_y); i++) {
                int yk = Y1 + i + 1, xk;
                double x = X1 + delta_x * 1.0 * (i+1) / delta_y;
                double d1 = x - floor(x);
                double d2 = ceil(x) - x;
                double decision_parameter = d1 - d2;

                if(decision_parameter < 0)
                    xk = floor(x);
                else
                    xk = ceil(x);

                putpixel(xk, yk);
            }
        }
        else {
            // Slope <= 1
            for(int i=0; i<abs(delta_x); i++) {
                int xk = X1 + i + 1, yk;
                double y = Y1 + delta_y * 1.0 * (i+1) / delta_x;
                double d1 = y - floor(y);
                double d2 = ceil(y) - y;
                double decision_parameter = d1 - d2;

                if(decision_parameter < 0)
                    yk = floor(y);
                else
                    yk = ceil(y);

                putpixel(xk, yk);
            }
        }
        
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {

    printf("All coordinates are between 0 and %d\n", min(WIDTH, HEIGHT));
    printf("Enter the first point (x1, y1)  : ");
    scanf("%d%d", &X1, &Y1);
    printf("Enter the second point (x2, y2) : ");
    scanf("%d%d", &X2, &Y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line");
    glutDisplayFunc(drawLine);
    glutMainLoop();
}