#include "ui/GameUI.h"
#include "core/Shapes.h"

// Variables that live in JoyProject.cpp
extern const char* feedbackMessage;

// 1. Function to draw rounded rectangles for UI elements
void drawRoundedButton(float x, float y, float w, float h, float r, float g, float b, const char* text) {
    float radius = h / 2;
    glColor3f(r, g, b); // Button color
    drawCircle(x + radius, y + radius, radius); drawCircle(x + w - radius, y + radius, radius);
    glBegin(GL_QUADS);
    glVertex2f(x + radius, y); glVertex2f(x + w - radius, y); glVertex2f(x + w - radius, y + h); glVertex2f(x + radius, y + h);
    glEnd();
    // Button text 
    glColor3f(0, 0, 0);
    drawText(x + radius, y + h / 3, text);
}

// 2. Function to assemble the game interface (Question box + 4 choice buttons)
void drawGameUI() {
    // Question box (Light gray at top)
    drawRoundedButton(337, 520, 350, 50, 0.9f, 0.9f, 0.9f, " Look closely.. What season is this?");
    // Four choice buttons at the bottom
    float btnW = 120; float btnH = 40; float spacing = 20;
    float startX = (windowWidth - (4 * btnW + 3 * spacing)) / 2;
    drawRoundedButton(startX, 40, btnW, btnH, 1.0f, 1.0f, 1.0f, "  Winter"); // White
    drawRoundedButton(startX + (btnW + spacing), 40, btnW, btnH, 0.5f, 1.0f, 0.5f, "  Spring"); // Green
    drawRoundedButton(startX + 2 * (btnW + spacing), 40, btnW, btnH, 1.0f, 1.0f, 0.0f, "Summer"); // Yellow
    drawRoundedButton(startX + 3 * (btnW + spacing), 40, btnW, btnH, 1.0f, 0.6f, 0.2f, " Autumn"); // Orange
    // Feedback message (if answer is wrong)
    glColor3f(1, 0, 0);
    drawText(windowWidth / 2 - 80, 100, feedbackMessage);
}