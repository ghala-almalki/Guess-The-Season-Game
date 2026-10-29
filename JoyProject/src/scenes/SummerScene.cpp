#include "scenes/SummerScene.h"
#include "scenes/Environment.h"
#include "core/Shapes.h"
#include "character/Character.h"
#include <cmath>

SummerScene summerScene;

// Sea waves
void SummerScene::drawWaves() {
    float baseY = 235;
    glColor3f(0.0f, 0.55f, 0.75f);
    glBegin(GL_POLYGON);
    glVertex2f(0, baseY); glVertex2f(windowWidth, baseY); glVertex2f(windowWidth, baseY - 60); glVertex2f(0, baseY - 60);
    glEnd();

    glColor4f(1.0f, 1.0f, 1.0f, 0.7f);
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= windowWidth; i += 20) {
        float waveY = baseY + ((i % 40 < 20) ? 8 : 0);
        glVertex2f(i, waveY); glVertex2f(i, waveY - 5);
    }
    glEnd();
}

// Birds in sky
void SummerScene::drawBird(float x, float y, float size) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x - size, y + size / 2); glVertex2f(x, y); glVertex2f(x + size, y + size / 2);
    glEnd();
}

// Sea shells
void SummerScene::drawShell(float x, float y, float size) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    // Shell body using a partial triangle fan
    glColor3f(1.0f, 0.95f, 0.85f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0); // Bottom center
    for (int i = 0; i <= 10; i++) {
        float angle = (i * PI / 10.0f);
        glVertex2f(size * cos(angle), size * sin(angle));
    }
    glEnd();
    // Shell detail lines
    glColor3f(0.85f, 0.75f, 0.65f);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    for (int i = 1; i < 10; i++) {
        float angle = (i * PI / 10.0f);
        glVertex2f(0, 0);
        glVertex2f(size * cos(angle), size * sin(angle));
    }
    glEnd();
    glPopMatrix();
}

// Starfish
void SummerScene::drawStarfish(float x, float y, float radius) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    Rotate(20.0, 0, 0, 1);
    // Star body
    glColor3f(1.0f, 0.5f, 0.3f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= 10; i++) {
        float r = (i % 2 == 0) ? radius : radius * 0.45f;
        float angle = i * 2.0f * PI / 10.0f;
        glVertex2f(r * cos(angle), r * sin(angle));
    }
    glEnd();
    // Detail points
    glColor3f(0.8f, 0.3f, 0.1f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 5; i++) {
        float angle = i * 2.0f * PI / 5.0f;
        glVertex2f(radius * 0.5f * cos(angle), radius * 0.5f * sin(angle));
    }
    glEnd();
    glPopMatrix();
}

// Sand toys
void SummerScene::drawSandToy(float x, float y, float scale) {
    // 1. Bucket
    // Bucket body
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x, y); glVertex2f(x + 40 * scale, y); glVertex2f(x + 50 * scale, y + 50 * scale); glVertex2f(x - 10 * scale, y + 50 * scale);
    glEnd();
    // Bucket rim
    glColor3f(0.0f, 0.3f, 0.7f);
    drawEllipse(x + 20 * scale, y + 50 * scale, 30 * scale, 8 * scale);
    // Handle
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 10; i++) {
        float angle = i * PI / 10.0f;
        glVertex2f(x + 20 * scale + 30 * scale * cos(angle),
            y + 50 * scale + 25 * scale * sin(angle));
    }
    glEnd();
    // 2. Shovel
    float sx = x + 60 * scale;
    glColor3f(1.0f, 0.8f, 0.0f);
    // Shovel handle
    glBegin(GL_QUADS);
    glVertex2f(sx, y); glVertex2f(sx + 8 * scale, y); glVertex2f(sx + 8 * scale, y + 40 * scale); glVertex2f(sx, y + 40 * scale);
    glEnd();
    // Shovel head
    glBegin(GL_POLYGON);
    glVertex2f(sx - 10 * scale, y); glVertex2f(sx + 18 * scale, y); glVertex2f(sx + 15 * scale, y - 15 * scale); glVertex2f(sx - 7 * scale, y - 15 * scale);
    glEnd();
}

// Summer Scene
void SummerScene::draw()
{// Sky gradient
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex2f(0, 0); glVertex2f(windowWidth, 0);
    glColor3f(0.6f, 0.9f, 1.0f);
    glVertex2f(windowWidth, 600); glVertex2f(0, 600);
    glEnd();
    // Birds
    drawBird(200, 500, 15); drawBird(250, 470, 12); drawBird(400, 530, 10);
    // Sun 
    drawAttractiveSun(800, 500, 80);
    // Sand (Beach)
    glColor3f(0.96f, 0.87f, 0.70f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0); glVertex2f(windowWidth, 0); glVertex2f(windowWidth, 230); glVertex2f(0, 230);
    glEnd();

    // Sea
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.8f); // Light blue near shore
    glVertex2f(0, 230); glVertex2f(windowWidth, 230);
    glColor3f(0.0f, 0.3f, 0.5f); // Dark blue at horizon
    glVertex2f(windowWidth, 450); glVertex2f(0, 450);
    glEnd();
    // Waves
    drawWaves();
    // Toys
    drawSandToy(500, 70, 0.9f);
    // Starfish
    drawStarfish(120, 140, 18); drawStarfish(380, 50, 22); drawStarfish(680, 130, 16); drawStarfish(920, 40, 20);
    // Shells
    drawShell(60, 70, 12); drawShell(200, 30, 15); drawShell(280, 160, 10); drawShell(440, 110, 11); drawShell(580, 20, 14); drawShell(630, 80, 12);
    drawShell(780, 140, 13); drawShell(840, 40, 15); drawShell(940, 110, 10); drawShell(970, 170, 9);
    // Small details
    glColor3f(1.0f, 1.0f, 0.9f);
    drawCircle(320, 90, 5); drawCircle(560, 150, 6); drawCircle(720, 60, 5); drawCircle(180, 175, 4);
    // Character
    character.MyMainObj();
}