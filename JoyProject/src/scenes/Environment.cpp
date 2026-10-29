#include "scenes/Environment.h"
#include "core/Shapes.h"
#include "core/GameState.h"
#include <cmath>   // needed for cos() and sin()

// Variables that live in JoyProject.cpp
extern int gameState;
extern float sunAngle;


// Sun
void drawAttractiveSun(float cx, float cy, float r) {
    glPushMatrix();
    glTranslatef(cx, cy, 0);       // 1. Move to sun center
    glRotatef(sunAngle, 0, 0, 1);   // 2. Rotate
    glTranslatef(-cx, -cy, 0);     // 3. Move back
    // Back glow
    glBegin(GL_TRIANGLE_FAN);
    // Autumn case
    if (gameState == Autumn) {
        glColor4f(0.95f, 0.70f, 0.20f, 0.18f);
    }
    // Other seasons
    else {
        glColor4f(1.0f, 0.9f, 0.0f, 0.3f);
    }

    glVertex2f(cx, cy);
    // Autumn case
    if (gameState == Autumn) {
        glColor4f(0.95f, 0.70f, 0.20f, 0.0f);
    }
    // Other seasons
    else {
        glColor4f(1.0f, 0.9f, 0.0f, 0.0f);
    }

    // Drawing the glow circle using a triangle fan
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            cx + (r * 1.8f * cos(i * twicePi / triangleAmount)),
            cy + (r * 1.8f * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    // Sun Rays
    // Autumn case
    if (gameState == Autumn) {
        glColor4f(0.90f, 0.60f, 0.18f, 0.55f);
    }
    else {
        glColor4f(1.0f, 0.8f, 0.0f, 0.8f);
    }

    // Draw rays by rotating triangles around the center
    for (int i = 0; i < 360; i += 30) {
        glPushMatrix();
        glTranslatef(cx, cy, 0);
        glRotatef(i, 0, 0, 1);

        glBegin(GL_TRIANGLES);
        glVertex2f(r * 0.9f, -8); glVertex2f(r * 0.9f, 8); glVertex2f(r * 1.5f, 0);
        glEnd();
        glPopMatrix();
    }

    // Sun Disk
    // Autumn case
    if (gameState == Autumn) {
        glColor3f(0.93f, 0.74f, 0.25f);
    }
    // Other seasons
    else {
        glColor3f(1.0f, 0.95f, 0.2f);
    }

    drawCircle(cx, cy, r);
    // Summer case details
    if (gameState == Summer) {
        // Sunglasses
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(cx - r * 0.35f, cy + r * 0.1f, r * 0.25f); // Left
        drawCircle(cx + r * 0.35f, cy + r * 0.1f, r * 0.25f); // Right
        glLineWidth(3.0f);
        glBegin(GL_LINES);
        glVertex2f(cx - r * 0.1f, cy + r * 0.1f); glVertex2f(cx + r * 0.1f, cy + r * 0.1f);
        glEnd();
        // Cute Smile
        glBegin(GL_LINE_STRIP);
        glVertex2f(cx - r * 0.3f, cy - r * 0.25f); glVertex2f(cx - r * 0.15f, cy - r * 0.4f); glVertex2f(cx, cy - r * 0.45f); glVertex2f(cx + r * 0.15f, cy - r * 0.4f); glVertex2f(cx + r * 0.3f, cy - r * 0.25f);
        glEnd();
    }
    glPopMatrix(); // End of full sun rotation
}

// Clouds
void drawCloud(float x, float y, float size) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, size * 0.7f); drawCircle(x + size * 0.6f, y + size * 0.3f, size); drawCircle(x + size * 1.2f, y + size * 0.1f, size * 0.8f); drawCircle(x + size * 1.7f, y - size * 0.1f, size * 0.6f);
    // Rectangle to merge the circles
    glBegin(GL_QUADS);
    glVertex2f(x - size * 0.2f, y - size * 0.3f); glVertex2f(x + size * 2.0f, y - size * 0.3f); glVertex2f(x + size * 2.0f, y + size * 0.1f); glVertex2f(x - size * 0.2f, y + size * 0.1f);
    glEnd();
}

// Hills
void drawHills() {
    // Autumn case
    if (gameState == Autumn) {
        glColor3f(0.45f, 0.28f, 0.10f);
    }
    // Winter case
    else if (gameState == Winter) {
        // Far hill
        glColor3f(0.85f, 0.9f, 0.95f);
    }
    // Other seasons
    else {
        glColor3f(0.2, 0.5, 0.2);
    }

    glBegin(GL_POLYGON);
    // Creating hill using a circular polygon
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        glVertex2f(200 + cos(angle) * 300,
            100 + sin(angle) * 150);
    }
    glEnd();

    // Near hill
    // Autumn case
    if (gameState == Autumn) {
        glColor3f(0.62f, 0.38f, 0.14f);
    }
    // Winter case
    else if (gameState == Winter) {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    // Other seasons
    else {
        glColor3f(0.3, 0.7, 0.3);
    }

    glBegin(GL_POLYGON);
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        glVertex2f(700 + cos(angle) * 400,
            50 + sin(angle) * 200);
    }
    glEnd();
}