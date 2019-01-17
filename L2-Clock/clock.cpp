/*
 * Compile with the followinng command
 * g++ clock.cpp -lglut -lGL
 */

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>
#include <unistd.h>

#define WIDTH 600
#define HEIGHT 600
const double PI = 3.14159265358979323;
using namespace std;

void drawClock(double h, double m, double s) {

    h = 1.0 - fmod((h + m/60.0 + s/3600.0) / 12.0 + 0.75, 1.0);
    m = 1.0 - fmod((m + s/60.0) / 60.0 + 0.75, 1.0);
    s = 1.0 - fmod(s / 60.0 + 0.75, 1.0);

    while(h >= 12.0)
        h -= 12.0;
    while(m >= 60.0)
        m -= 60.0;
    while(s >= 60.0)
        s -= 60.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);

    // Circle
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
        for(int theta=0; theta<3600; theta++) {
            double ang = theta * 1.0 / 20 / PI;
            double r = 0.50;

            glVertex2f(r * cos(ang), r * sin(ang));
        }
    glEnd();
    glPointSize(10);
    glBegin(GL_POINTS);
        
        glColor3f(1.0, 0.0, 1.0);
        for(int i=0; i<12; i++) {
            double ang = i / 12.0 * 2 * PI;
            double r = 0.50;
            glVertex2f(r * cos(ang), r * sin(ang));
        }
    glEnd();

    
    // Hour Hand
    double ang = h * 2 * PI;
    double r = 0.2;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(r * cos(ang), r * sin(ang));
    glEnd();

    // Minute Hand
    ang = m * 2 * PI;
    r = 0.4;
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(r * cos(ang), r * sin(ang));
    glEnd();

    // Hour Hand
    ang = s * 2 * PI;
    r = 0.45;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(r * cos(ang), r * sin(ang));
    glEnd();
    
    glFlush();
}

void runClock() {

    while(1) {
        time_t temp = time(0);
        struct tm *tm_struct = localtime(&temp);

        int hour = tm_struct->tm_hour;
        int minutes = tm_struct->tm_min;
        int seconds = tm_struct->tm_sec;

        // printf("%d %d %d\n", hour, minutes, seconds);
        drawClock(hour, minutes, seconds);
        usleep(100000);
    }
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Clock");
    glutDisplayFunc(runClock);
    glutMainLoop();
}