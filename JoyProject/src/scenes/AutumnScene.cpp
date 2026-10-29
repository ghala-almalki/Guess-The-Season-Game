#include "scenes/AutumnScene.h"
#include "scenes/Environment.h"
#include "core/Shapes.h"
#include "character/Character.h"

AutumnScene autumnScene;

// Autumn tree
void AutumnScene::drawAutumnTree(float x, float y, float scale) {
    glColor3f(0.38f, 0.20f, 0.06f);
    glBegin(GL_QUADS);
    glVertex2f(x - 5 * scale, y); glVertex2f(x + 5 * scale, y); glVertex2f(x + 5 * scale, y + 40 * scale);  glVertex2f(x - 5 * scale, y + 40 * scale);
    glEnd();

    glColor3f(0.76f, 0.45f, 0.17f);
    drawCircle(x, y + 52 * scale, 25 * scale);

    glColor3f(0.85f, 0.32f, 0.05f);
    drawCircle(x - 15 * scale, y + 40 * scale, 20 * scale);

    glColor3f(0.60f, 0.22f, 0.05f);
    drawCircle(x + 15 * scale, y + 40 * scale, 20 * scale);

    glColor3f(0.92f, 0.60f, 0.12f);
    drawCircle(x, y + 32 * scale, 18 * scale);
}

// Autumn leaf
void AutumnScene::drawAutumnLeaf(float x, float y, float size, float r, float g, float b, float angle) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(30, 0, 0, 1);

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(0, size * 1.8f); glVertex2f(size * 1.2f, size * 0.4f); glVertex2f(size * 0.7f, -size * 1.5f); glVertex2f(0, -size * 2.0f); glVertex2f(-size * 0.7f, -size * 1.5f); glVertex2f(-size * 1.2f, size * 0.4f);
    glEnd();

    glColor3f(0.35f, 0.15f, 0.03f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glVertex2f(0, size * 1.8f); glVertex2f(0, -size * 2.0f);
    glEnd();

    glPopMatrix();
}

// Autumn Scene
void AutumnScene::draw()
{// Sky
    glBegin(GL_QUADS);
    glColor3f(0.78f, 0.86f, 0.92f); glVertex2f(0, 0);
    glColor3f(0.76f, 0.84f, 0.90f); glVertex2f(windowWidth, 0);
    glColor3f(0.88f, 0.92f, 0.95f); glVertex2f(windowWidth, 600);
    glColor3f(0.84f, 0.90f, 0.94f); glVertex2f(0, 600);
    glEnd();
    // Sun
    drawAttractiveSun(150, 480, 45);
    // Clouds
    drawCloud(50, 530, 25); drawCloud(150, 500, 30); drawCloud(80, 460, 20); drawCloud(700, 520, 35); drawCloud(850, 500, 25); drawCloud(650, 470, 20); drawCloud(450, 510, 15); drawCloud(550, 490, 20);
    // Hills
    drawHills();
    // Autumn trees
    drawAutumnTree(50, 210, 0.9f); drawAutumnTree(250, 230, 0.8f); drawAutumnTree(540, 220, 1.0f); drawAutumnTree(800, 230, 0.85f); drawAutumnTree(990, 180, 0.95f); drawAutumnTree(150, 140, 2.0f);
    drawAutumnTree(450, 110, 2.4f); drawAutumnTree(700, 125, 2.2f); drawAutumnTree(900, 100, 2.5f);
    // Autumn leaves in different colors and rotations
    // Yellow
    drawAutumnLeaf(80, 190, 4, 0.90f, 0.70f, 0.10f, 30); drawAutumnLeaf(220, 210, 3, 0.90f, 0.70f, 0.10f, -45); drawAutumnLeaf(380, 185, 4, 0.90f, 0.70f, 0.10f, 15); drawAutumnLeaf(500, 225, 3, 0.90f, 0.70f, 0.10f, 60); drawAutumnLeaf(620, 200, 4, 0.90f, 0.70f, 0.10f, -10); drawAutumnLeaf(880, 215, 4, 0.90f, 0.70f, 0.10f, 25);
    // Red
    drawAutumnLeaf(30, 160, 4, 0.70f, 0.10f, 0.00f, -20); drawAutumnLeaf(180, 145, 5, 0.70f, 0.10f, 0.00f, 40); drawAutumnLeaf(440, 155, 4, 0.70f, 0.10f, 0.00f, 90); drawAutumnLeaf(580, 135, 5, 0.70f, 0.10f, 0.00f, -15); drawAutumnLeaf(730, 170, 4, 0.70f, 0.10f, 0.00f, 55); drawAutumnLeaf(920, 150, 4, 0.70f, 0.10f, 0.00f, -60);
    // Orange
    drawAutumnLeaf(130, 80, 5, 0.85f, 0.30f, 0.05f, 110); drawAutumnLeaf(170, 90, 4, 0.85f, 0.30f, 0.05f, -10); drawAutumnLeaf(430, 75, 5, 0.85f, 0.30f, 0.05f, 20); drawAutumnLeaf(470, 85, 4, 0.85f, 0.30f, 0.05f, 150); drawAutumnLeaf(680, 90, 5, 0.85f, 0.30f, 0.05f, -35); drawAutumnLeaf(720, 80, 4, 0.85f, 0.30f, 0.05f, 45);
    drawAutumnLeaf(100, 25, 7, 0.85f, 0.30f, 0.05f, 0); drawAutumnLeaf(300, 15, 6, 0.85f, 0.30f, 0.05f, 80); drawAutumnLeaf(550, 30, 7, 0.85f, 0.30f, 0.05f, -25); drawAutumnLeaf(800, 20, 6, 0.85f, 0.30f, 0.05f, 15); drawAutumnLeaf(950, 35, 7, 0.85f, 0.30f, 0.05f, -50);
    // Yellow
    drawAutumnLeaf(50, 50, 5, 0.90f, 0.70f, 0.10f, 45); drawAutumnLeaf(200, 40, 6, 0.90f, 0.70f, 0.10f, -15); drawAutumnLeaf(400, 55, 5, 0.90f, 0.70f, 0.10f, 120); drawAutumnLeaf(650, 45, 6, 0.90f, 0.70f, 0.10f, 30); drawAutumnLeaf(850, 60, 5, 0.90f, 0.70f, 0.10f, -10); drawAutumnLeaf(1010, 50, 6, 0.90f, 0.70f, 0.10f, 20);
    // Red
    drawAutumnLeaf(150, 15, 5, 0.70f, 0.10f, 0.00f, -90); drawAutumnLeaf(350, 30, 4, 0.70f, 0.10f, 0.00f, 15); drawAutumnLeaf(600, 25, 5, 0.70f, 0.10f, 0.00f, 45); drawAutumnLeaf(750, 10, 6, 0.70f, 0.10f, 0.00f, -110); drawAutumnLeaf(900, 45, 5, 0.70f, 0.10f, 0.00f, 30);
    // Character
    character.MyMainObj();
}