#include "scenes/StartScreen.h"
#include "scenes/Environment.h"
#include "ui/GameUI.h"
#include "core/Shapes.h"
#include "character/Character.h"

StartScreen startScreen;

// Red flower
void StartScreen::drawRedFlower(float x, float y, float size) {
    // Stem
    glColor3f(0.0f, 0.8f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(x, y); glVertex2f(x, y + size * 2);
    glEnd();
    // Petals
    glColor3f(1.0f, 0.0f, 0.0f);
    float petalDist = size * 0.8f;
    drawCircle(x - petalDist, y + size * 2, size * 0.8f); drawCircle(x + petalDist, y + size * 2, size * 0.8f); drawCircle(x, y + size * 2 + petalDist, size * 0.8f); drawCircle(x, y + size * 2 - petalDist, size * 0.8f);
    // Flower center
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(x, y + size * 2, size * 0.5f);
}

// Fancy Bee
void StartScreen::drawFancyBee(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1.0f); // Overall scale control
    // 1. Wings
    glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
    drawCircle(-6, 8, 7); // Left wing
    drawCircle(6, 8, 7);  // Right wing
    // 2. Body
    glColor3f(1.0f, 0.9f, 0.1f);
    drawCircle(0, 0, 12);
    // 3. Black stripes
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(-10, 2);  glVertex2f(10, 2); glVertex2f(10, 4);   glVertex2f(-10, 4); glVertex2f(-11, -4); glVertex2f(11, -4); glVertex2f(11, -2);  glVertex2f(-11, -2);
    glEnd();
    // 4. Head
    drawCircle(10, 1, 6);
    // 5. Eye
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(12, 3, 1.5);
    glPopMatrix();
}

// Start Screen
void StartScreen::draw() {
    // 1. Sky Blue background 
    glClearColor(0.85f, 0.95f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 2. Rainbow drawing using overlapping circles
    float centerX = windowWidth / 2;
    float centerY = 50;
    // Draw circles from outer to inner
    glColor3f(1.0f, 0.7f, 0.7f);  drawCircle(centerX, centerY, 550); // Arch 1
    glColor3f(1.0f, 0.85f, 0.6f); drawCircle(centerX, centerY, 525); // Arch 2
    glColor3f(1.0f, 1.0f, 0.7f);  drawCircle(centerX, centerY, 500); // Arch 3
    glColor3f(0.7f, 1.0f, 0.7f);  drawCircle(centerX, centerY, 475); // Arch 4
    glColor3f(0.7f, 0.9f, 1.0f);  drawCircle(centerX, centerY, 450); // Arch 5
    glColor3f(0.8f, 0.7f, 1.0f);  drawCircle(centerX, centerY, 425); // Arch 6

    // Void circle (background color) to create rainbow shape
    glColor3f(0.85f, 0.95f, 1.0f);
    drawCircle(centerX, centerY, 400);

    // 3. Rectangle to hide bottom part
    glBegin(GL_QUADS);
    glVertex2f(0, 0); glVertex2f(windowWidth, 0); glVertex2f(windowWidth, 100); glVertex2f(0, 100);
    glEnd();

    // 4. Clouds
    drawCloud(100, 500, 35); drawCloud(350, 530, 40); drawCloud(650, 520, 38); drawCloud(900, 490, 35); drawCloud(500, 550, 30);

    // 5. Texts
    glColor3f(0.1f, 0.5f, 0.1f);
    drawText(windowWidth / 2 - 160, 440, "THE MAGIC SEASONS ADVENTURE");
    glColor3f(0.5f, 0.0f, 0.7f);
    drawText(windowWidth / 2 - 220, 400, "Move the character with arrows to discover the seasons!");

    // Flowers
    drawRedFlower(50, 35, 8); drawRedFlower(120, 20, 5); drawRedFlower(220, 45, 9); drawRedFlower(320, 15, 6);
    drawRedFlower(420, 50, 7); drawRedFlower(620, 45, 8); drawRedFlower(750, 20, 6); drawRedFlower(880, 55, 9); drawRedFlower(970, 30, 7);

    // Bees
    drawFancyBee(220, 330, 0.7f); drawFancyBee(800, 360, 0.6f); drawFancyBee(480, 480, 0.5f);
    drawFancyBee(180, 310, 0.9f); drawFancyBee(850, 380, 0.85f);

    // 6. Double Start Button (Shadow + Main)
    float bX = windowWidth / 2 - 110;
    float bY = 175;
    float bW = 220;
    float bH = 65;
    drawRoundedButton(bX + 5, bY - 5, bW, bH, 0.7f, 0.7f, 0.8f, "");
    drawRoundedButton(bX, bY, bW, bH, 1.0f, 0.5f, 0.7f, "     PLAY NOW");

    // 7. Instructions text
    glColor3f(0.4f, 0.5f, 0.6f);
    drawText(windowWidth / 2 - 100, 145, "Click the button to start");

    // 8. Character
    character.MyMainObj();
}