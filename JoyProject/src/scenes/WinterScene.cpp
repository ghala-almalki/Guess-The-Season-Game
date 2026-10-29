#include "scenes/WinterScene.h"
#include "core/Shapes.h"
#include "character/Character.h"
#include "scenes/Environment.h"  

// Variables that live in JoyProject.cpp
extern GLuint winterTexture;
WinterScene winterScene;

// Mountain for Winter scene
void WinterScene::drawMountain(float x, float y, float scale) {
    // Mountain base
    glColor3f(0.35f, 0.2f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 250 * scale, y); glVertex2f(x + 250 * scale, y); glVertex2f(x + 100 * scale, y + 150 * scale); glVertex2f(x - 100 * scale, y + 150 * scale);
    glEnd();
    // Main mountain body (large triangle)
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 200 * scale, y + 50 * scale); glVertex2f(x + 200 * scale, y + 50 * scale); glVertex2f(x, y + 300 * scale);
    glEnd();
    // Mountain peak (snow cap)
    glColor3f(0.9f, 0.92f, 0.95f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 80 * scale, y + 180 * scale); glVertex2f(x + 80 * scale, y + 180 * scale); glVertex2f(x, y + 300 * scale);
    glEnd();

    // Snow accumulations
    glBegin(GL_POLYGON);
    glVertex2f(x - 80 * scale, y + 180 * scale); glVertex2f(x - 50 * scale, y + 160 * scale); glVertex2f(x, y + 175 * scale); glVertex2f(x + 50 * scale, y + 160 * scale); glVertex2f(x + 80 * scale, y + 180 * scale);
    glEnd();
}

// Snowman
void WinterScene::drawSnowman(float x, float y, float scale) {
    // 1. Body (three snowballs)
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 40 * scale); drawCircle(x, y + 55 * scale, 30 * scale); drawCircle(x, y + 95 * scale, 20 * scale);
    // 2. Eyes and nose
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(x - 7 * scale, y + 100 * scale, 2.5 * scale); // Left eye
    drawCircle(x + 7 * scale, y + 100 * scale, 2.5 * scale); // Right eye
    // Nose
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + 95 * scale); glVertex2f(x, y + 91 * scale); glVertex2f(x + 15 * scale, y + 93 * scale);
    glEnd();
    // 3. Hands (branches)
    glColor3f(0.4f, 0.2f, 0.1f);
    glLineWidth(3);
    glBegin(GL_LINES);
    // Left arm
    glVertex2f(x - 25 * scale, y + 60 * scale); glVertex2f(x - 50 * scale, y + 85 * scale);
    // Right arm
    glVertex2f(x + 25 * scale, y + 60 * scale); glVertex2f(x + 50 * scale, y + 85 * scale);
    glEnd();

    // 4. Buttons
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(x, y + 65 * scale, 2.5 * scale); drawCircle(x, y + 55 * scale, 2.5 * scale); drawCircle(x, y + 45 * scale, 2.5 * scale);
}

// Winter tree
void WinterScene::drawWinterTree(float x, float y, float scale) {
    // 1. Trunk
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x - 5 * scale, y); glVertex2f(x + 5 * scale, y); glVertex2f(x + 5 * scale, y + 35 * scale); glVertex2f(x - 5 * scale, y + 35 * scale);
    glEnd();
    // 2. Green branches
    glColor3f(0.0f, 0.45f, 0.0f);
    // Bottom triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 45 * scale, y + 30 * scale); glVertex2f(x + 45 * scale, y + 30 * scale); glVertex2f(x, y + 80 * scale);
    glEnd();
    // Top triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 35 * scale, y + 60 * scale); glVertex2f(x + 35 * scale, y + 60 * scale); glVertex2f(x, y + 110 * scale);
    glEnd();

    // 3. Snow on tree
    glColor3f(1.0f, 1.0f, 1.0f);
    // Bottom snow
    glBegin(GL_POLYGON);
    glVertex2f(x - 38 * scale, y + 38 * scale); glVertex2f(x + 38 * scale, y + 38 * scale); glVertex2f(x + 10 * scale, y + 65 * scale); glVertex2f(x, y + 78 * scale); glVertex2f(x - 10 * scale, y + 65 * scale);
    glEnd();
    // Top snow
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 25 * scale, y + 75 * scale); glVertex2f(x + 25 * scale, y + 75 * scale); glVertex2f(x, y + 110 * scale);
    glEnd();
}

// Winter Scene
void WinterScene::draw()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, winterTexture);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0); glTexCoord2f(1.0f, 0.0f); glVertex2f(windowWidth, 0); glTexCoord2f(1.0f, 1.0f); glVertex2f(windowWidth, windowHeight); glTexCoord2f(0.0f, 1.0f); glVertex2f(0, windowHeight);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    drawMountain(400, 200, 1.0);
    drawHills();
    drawWinterTree(600, 200, 1.2f); drawWinterTree(850, 180, 1.0f);
    drawSnowman(150, 120, 1.8f);
    character.MyMainObj();
}