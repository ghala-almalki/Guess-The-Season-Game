#include "scenes/EndScreen.h"
#include "core/Shapes.h"
#include <GL/glu.h>   // needed for gluOrtho2D, gluPerspective and gluLookAt

// Variables that live in JoyProject.cpp
extern float trophyRotation;
extern float transValueX;
extern float transValueY;
extern float transValueZ;

EndScreen endScreen;

// End Screen
void EndScreen::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.85f, 0.95f, 1.0f, 1.0f);

    float centerX = windowWidth / 2;
    // 1. Rainbow background 
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    float rainbowY = 100;
    glColor3f(1.0f, 0.7f, 0.7f);  drawCircle(centerX, rainbowY, 550);
    glColor3f(1.0f, 0.85f, 0.6f); drawCircle(centerX, rainbowY, 525);
    glColor3f(1.0f, 1.0f, 0.7f);  drawCircle(centerX, rainbowY, 500);
    glColor3f(0.7f, 1.0f, 0.7f);  drawCircle(centerX, rainbowY, 475);
    glColor3f(0.7f, 0.9f, 1.0f);  drawCircle(centerX, rainbowY, 450);
    glColor3f(0.8f, 0.7f, 1.0f);  drawCircle(centerX, rainbowY, 425);
    glColor3f(0.85f, 0.95f, 1.0f); drawCircle(centerX, rainbowY, 400);

    // 2. 3D Trophy
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(65, (float)windowWidth / windowHeight, 0.1, 50);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    gluLookAt(transValueX, transValueY, transValueZ, 0, 0, 0, 0, 1, 0);

    // Trophy container for rotation
    glPushMatrix();
    glRotatef(trophyRotation, 0, 1, 0);
    glColor3f(0.9f, 0.8f, 0.3f);
    // Trophy cup (Cone)
    glPushMatrix();
    glTranslatef(0, 0.1f, 0);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(0.75, 0.8, 30, 30);
    glPopMatrix();
    // Trophy stem (Cube)
    glPushMatrix();
    glTranslatef(0, -0.3f, 0);
    glScalef(0.25f, 0.6f, 0.25f);
    glutSolidCube(1.0);
    glPopMatrix();
    // Trophy base
    // Top base
    glPushMatrix();
    glTranslatef(0, -0.7f, 0);
    glScalef(0.9f, 0.2f, 0.9f);
    glutSolidCube(1.0);
    glPopMatrix();
    // Bottom base
    glPushMatrix();
    glTranslatef(0, -0.9f, 0);
    glScalef(1.3f, 0.2f, 1.3f);
    glutSolidCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glDisable(GL_LIGHTING); glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();

    glColor3f(0.3f, 0.0f, 0.5f);
    drawText(centerX - 100, 100, "CONGRATULATIONS!");
    glColor3f(0.1f, 0.5f, 0.1f);
    drawText(centerX - 85, 60, "YOU ARE A HERO");
}