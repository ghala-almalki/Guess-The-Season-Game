//////////
//Libraries//
//////////
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h> // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h> // handle the window-managing operations
#endif
#include <stdlib.h>
#include <iostream>
#include <string>

#include "core/Shapes.h"
#include "core/Texture.h"
#include "core/Audio.h"
#include "core/GameState.h"
#include "character/Character.h"
#include "scenes/WinterScene.h"
#include "scenes/SpringScene.h"
#include "scenes/SummerScene.h"
#include "scenes/AutumnScene.h"
#include "scenes/StartScreen.h"
#include "scenes/EndScreen.h"
#include "ui/GameUI.h"


using namespace std;


//////////
//Variables//
//////////
int gameState = 0;
// Animation timer for butterfly movement
float butterflyTime = 0.0f;
// Zoom value for 2D viewing/zooming using keyboard (+ / -)
float zoom = 1.0f; float sunAngle = 0.0f; const char* feedbackMessage = "";
float charX = 0.0f; // Horizontal movement
float charY = 0.0f; // Vertical movement
float trophyRotation = 0.0f; // Variable to control trophy rotation
float transValueX = 3.5f;
float transValueY = 2.0f;
float transValueZ = 2.0f;
float nearValue = 0.01f;
float farValue = 50.0f;
float windmillAngle = 0.0f; // Variable to control windmill blades rotation


/////////
//Texture//
////////

GLuint winterTexture, spring1Texture, spring2Texture, spring3Texture, autumnTexture;
char winterPath[] = "assets/textures/winter.bmp"; char spring1Path[] = "assets/textures/FloralTexture.bmp"; char spring2Path[] = "assets/textures/PinkTexture.bmp";
char spring3Path[] = "assets/textures/RiverTexture.bmp"; char autumnPath[] = "assets/textures/autumn.bmp";


////////////////////////
//Interaction and control//
////////////////////////

// Applies 2D zoom/viewing transformation to the whole scene
void applyZoom() {
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
Scale(zoom, zoom, 1.0);
}

// Handling arrow keys for movement and trophy rotation
void specialKeys(int key, int x, int y) {
float step = 10.0f; // Movement speed
switch (key) {
case GLUT_KEY_LEFT:
// Rotate trophy in end screen
if (gameState == End_Screen) {
trophyRotation -= 5.0f;
}
// Original logic: move left if not in Spring and within screen bounds
else if (gameState != Spring && (300.0f + charX - step) > 50.0f) {
charX -= step;
}
break;

case GLUT_KEY_RIGHT:
// Rotate trophy in end screen
if (gameState == End_Screen) {
trophyRotation += 5.0f;
}
// Move right logic
else if (gameState != Spring && (300.0f + charX + step) < (windowWidth - 50.0f)) {
charX += step;
}
break;

case GLUT_KEY_UP:
// Move up in Spring scene only
if (gameState == Spring && (350.0f + charY + step) < (windowHeight - 50.0f)) {
charY += step;
}
break;

case GLUT_KEY_DOWN:
// Move down in Spring scene only
if (gameState == Spring && (350.0f + charY - step) > 120.0f) {
charY -= step;
}
break;
}
glutPostRedisplay();
}


// Keyboard zoom control for 2D viewing (+/- keys)
void keyboard(unsigned char key, int x, int y) {
if (key == '+') zoom += 0.1f;
else if (key == '-' && zoom > 0.3f) zoom -= 0.1f;
glutPostRedisplay();
}

// Mouse click handling for menu buttons and game choices
void mouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
// 1. Correct Y coordinates (OpenGL origin is bottom-left, Mouse is top-left)
y = windowHeight - y;

// 2. Start Screen handling
if (gameState == 0) {
// Check if Start button is clicked
if (x >= (windowWidth / 2 - 110) && x <= (windowWidth / 2 + 110) &&
y >= 175 && y <= 240) {
gameState = Winter; // Start with Winter

// Change music to winter theme
playLoop("assets/audio/winter.wav");
}
}

// 3. Seasonal Screens logic (1 to 4)
else if (gameState >= 1 && gameState <= 4) {
float btnW = 120;
float spacing = 20;
float startX = (windowWidth - (4 * btnW + 3 * spacing)) / 2;

for (int i = 0; i < 4; i++) {
float bx = startX + i * (btnW + spacing);
float by = 40;
float bh = 40;

// Check button click
if (x >= bx && x <= bx + btnW && y >= by && y <= by + bh) {

if (i + 1 == gameState) {
// Correct Answer!
gameState++;
feedbackMessage = "Correct! Well done.";

// Change audio theme for each season
if (gameState == Spring)
playLoop("assets/audio/spring.wav");
else if (gameState == Summer)
playLoop("assets/audio/summer.wav");
else if (gameState == Autumn)
playLoop("assets/audio/autumn.wav");
else if (gameState == End_Screen)
playOnce("assets/audio/end.wav");

if (gameState > 4) {
gameState = 5;
}
}
else {
// Wrong Answer
feedbackMessage = "Ohh Wrong! Try again.";
}
}
}
}
}
glutPostRedisplay();
}


// Timer function updates butterfly and sun animation every frame (16ms)
void update(int value) {
butterflyTime += 0.035f;
sunAngle += 0.4f;

// Mill rotation update
windmillAngle += 2.0f;
if (windmillAngle >= 360.0f)
windmillAngle -= 360.0f;

glutPostRedisplay();
glutTimerFunc(16, update, 0);
}


void init() {
glClearColor(1, 1, 1, 1);

// Enable transparency for clouds and glow
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, windowWidth, 0, windowHeight);

// Load all textures
winterTexture = LoadTexture(winterPath, 880, 586); spring1Texture = LoadTexture(spring1Path, 512, 512); spring2Texture = LoadTexture(spring2Path, 512, 512); spring3Texture = LoadTexture(spring3Path, 512, 512); autumnTexture = LoadTexture(autumnPath, 256, 256);
}

// Main display function to switch between game states
void display() {
glClear(GL_COLOR_BUFFER_BIT);
applyZoom();

// Constant rotation update for sun
sunAngle += 0.1f;
if (sunAngle > 360) sunAngle -= 360;

if (gameState == 0) startScreen.draw();
else if (gameState == 1) { winterScene.draw(); drawGameUI(); }
else if (gameState == 2) { springScene.draw(); drawGameUI(); }
else if (gameState == 3) { summerScene.draw(); drawGameUI(); }
else if (gameState == 4) { autumnScene.draw(); drawGameUI(); }
else if (gameState == 5) endScreen.draw();

glutPostRedisplay();
glFlush();
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(windowWidth, windowHeight);
glutCreateWindow("GUESS THE SEASON GAME");

playLoop("assets/audio/start.wav");

init();
glutDisplayFunc(display);
glutTimerFunc(0, update, 0);
glutSpecialFunc(specialKeys);
glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}