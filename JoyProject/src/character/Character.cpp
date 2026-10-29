#include "character/Character.h"
#include "core/GameState.h"

// Variables that live in JoyProject.cpp
extern int gameState;
extern float charX;
extern float charY;
extern GLuint autumnTexture, spring1Texture, spring2Texture;

Character character;


//Face
void Character::DrawFace()
{
    glColor3f(1.0, 0.9, 0.8);
    drawCircle(0.0, 0.0, 0.5);
}

//Back hair  
void Character::DrawBackHair() 
{
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75f, -0.25f);

    glVertex2f(-0.73f, 0.05f); glVertex2f(-0.70f, 0.25f); glVertex2f(-0.65f, 0.35f); glVertex2f(-0.60f, 0.45f); glVertex2f(-0.50f, 0.55f); glVertex2f(-0.45f, 0.60f); glVertex2f(-0.35f, 0.65f); glVertex2f(-0.25f, 0.70f);
    glVertex2f(0.0f, 0.75f);     // Middle of the head 
    glVertex2f(0.25f, 0.70f); glVertex2f(0.35f, 0.65f); glVertex2f(0.45f, 0.60f); glVertex2f(0.50f, 0.55f); glVertex2f(0.60f, 0.45f); glVertex2f(0.65f, 0.35f); glVertex2f(0.70f, 0.25f); glVertex2f(0.73f, 0.05f);

    glVertex2f(0.75f, -0.25f);
    glEnd();
}

// Top hair
void Character::DrawTopHairSimple() 
{
    glColor3f(0.1f, 0.1f, 0.1f);
    // Middle circle  
    drawCircle(0.0f, 0.47f, 0.22f); // x, y, radius
    // Left circle 
    drawCircle(-0.28f, 0.47f, 0.20f);
    // Right circle
    drawCircle(0.28f, 0.47f, 0.20f);
}

// Bangs
void Character::DrawBangs() 
{
    glColor3f(0.1f, 0.1f, 0.1f);
    // Triangles for bangs
    glBegin(GL_TRIANGLES);
    // left
    glVertex2f(-0.50f, 0.32f); glVertex2f(-0.30f, 0.32f); glVertex2f(-0.40f, 0.12f);
    // mid left
    glVertex2f(-0.30f, 0.32f); glVertex2f(-0.08f, 0.32f); glVertex2f(-0.19f, 0.08f);
    // middle
    glVertex2f(-0.12f, 0.34f); glVertex2f(0.12f, 0.34f); glVertex2f(0.0f, 0.05f);
    // mid right
    glVertex2f(0.08f, 0.32f); glVertex2f(0.30f, 0.32f); glVertex2f(0.19f, 0.08f);
    // right
    glVertex2f(0.30f, 0.32f); glVertex2f(0.50f, 0.32f); glVertex2f(0.40f, 0.12f);

    glEnd();
}

//Ear
void Character::DrawEarLeft() 
{
    glColor3f(1.0f, 0.9f, 0.8f);
    drawCircle(-0.52f, -0.07f, 0.09f);
}

//Ear
void Character::DrawEarRight() 
{
    glColor3f(1.0f, 0.9f, 0.8f);
    drawCircle(0.52f, -0.07f, 0.09f);
}

//Eye
void Character::DrawEyes() 
{
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(-0.15f, -0.04f, 0.07f);// Left eye
    drawCircle(0.15f, -0.04f, 0.07f);// Right eye
    // Eye shine
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-0.13f, -0.01f, 0.025f);// left
    drawCircle(0.17f, -0.01f, 0.025f);// right
}

// Eyebrow
void Character::DrawEyebrows() 
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(0.1f);
    // Left eyebrow
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.30f, 0.05f); glVertex2f(-0.27f, 0.07f); glVertex2f(-0.24f, 0.08f); glVertex2f(-0.20f, 0.09f); glVertex2f(-0.16f, 0.08f); glVertex2f(-0.12f, 0.07f); glVertex2f(-0.10f, 0.05f);
    glEnd();
    // Right eyebrow
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.10f, 0.05f); glVertex2f(0.12f, 0.07f); glVertex2f(0.16f, 0.08f); glVertex2f(0.20f, 0.09f); glVertex2f(0.24f, 0.08f); glVertex2f(0.27f, 0.07f); glVertex2f(0.30f, 0.05f);
    glEnd();
}

// Cheeks
void Character::DrawCheeks() 
{
    glColor3f(1.0f, 0.6f, 0.6f);
    // Left cheek
    drawCircle(-0.30f, -0.31f, 0.07f);
    // Right cheek
    drawCircle(0.30f, -0.31f, 0.07f);
}

// Smile
void Character::DrawSmile() 
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(0.1f);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.08f, -0.28f); glVertex2f(-0.05f, -0.30f); glVertex2f(0.0f, -0.31f); glVertex2f(0.05f, -0.30f); glVertex2f(0.08f, -0.28f);
    glEnd();
}

// Neck
void Character::drawNeck() 
{
    glColor3f(1.0, 0.9, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, -0.50f); glVertex2f(0.05f, -0.50f); glVertex2f(0.05f, -0.60f); glVertex2f(-0.05f, -0.60f);
    glEnd();
}

// Torso (Shirt)
void Character::drawTorso() {
    // This function is for start/end screens and winter only
    if (gameState != Start_Screen && gameState != End_Screen && gameState != Winter)
        return;
    // For Winter
    if (gameState == Winter) {
        glColor3f(1.0f, 1.0f, 0.6f);
    }
    else {
        glColor3f(1.0f, 1.0f, 1.0f); // Start and End screens
    }
    glBegin(GL_POLYGON);
    glVertex2f(-0.35f, -0.60f); glVertex2f(0.35f, -0.60f); glVertex2f(0.30f, -1.25f); glVertex2f(-0.30f, -1.25f);
    glEnd();

    // Suspender straps
    glColor3f(1.0f, 0.0f, 0.0f);
    // left
    glBegin(GL_POLYGON);
    glVertex2f(-0.20f, -0.60f); glVertex2f(-0.12f, -0.60f); glVertex2f(-0.12f, -1.25f); glVertex2f(-0.20f, -1.25f);
    glEnd();
    // right
    glBegin(GL_POLYGON);
    glVertex2f(0.12f, -0.60f); glVertex2f(0.20f, -0.60f); glVertex2f(0.20f, -1.25f); glVertex2f(0.12f, -1.25f);
    glEnd();
}

// Torso (Autumn shirt)
void Character::drawAutumnTorso()
{
    if (gameState == Autumn) {
        // Base brown shirt
        glColor3f(0.72f, 0.45f, 0.20f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.38f, -0.60f); glVertex2f(0.38f, -0.60f); glVertex2f(0.32f, -1.28f); glVertex2f(-0.32f, -1.28f);
        glEnd();
        // Collar 
        glColor3f(0.90f, 0.55f, 0.08f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.18f, -0.60f); glVertex2f(0.18f, -0.60f); glVertex2f(0.08f, -0.78f); glVertex2f(-0.08f, -0.78f);
        glEnd();
        // Left pocket
        glColor3f(0.80f, 0.30f, 0.02f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.14f, -0.78f); glVertex2f(-0.04f, -0.78f); glVertex2f(-0.05f, -1.32f); glVertex2f(-0.15f, -1.32f);
        glEnd();
        // Right pocket
        glBegin(GL_POLYGON);
        glVertex2f(0.04f, -0.78f); glVertex2f(0.14f, -0.78f); glVertex2f(0.15f, -1.32f); glVertex2f(0.05f, -1.32f);
        glEnd();
        // Line details on the shirt
        glColor3f(0.55f, 0.30f, 0.12f);
        glLineWidth(1.3f);
        glBegin(GL_LINES);
        glVertex2f(-0.20f, -0.65f); glVertex2f(-0.22f, -1.25f); glVertex2f(0.0f, -0.62f);   glVertex2f(0.0f, -1.25f); glVertex2f(0.20f, -0.65f);  glVertex2f(0.22f, -1.25f);
        glEnd();
    }
}

// Torso (Summer shirt)
void Character::drawSummerTorso()
{
    if (gameState == Summer) {
        //Pink Top
        glColor3f(1.0f, 0.7f, 0.8f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.35f, -0.60f); glVertex2f(0.35f, -0.60f); glVertex2f(0.30f, -1.25f); glVertex2f(-0.30f, -1.25f);
        glEnd();
        //Yellow Dots
        glColor3f(1.0f, 1.0f, 0.0f);
        drawCircle(-0.15f, -0.80f, 0.04f); drawCircle(0.15f, -0.95f, 0.04f); drawCircle(-0.05f, -1.10f, 0.04f); drawCircle(0.10f, -0.75f, 0.04f);
    }
}

// Scarf
void Character::drawScarf()
{
    if (gameState == Winter) {
        glColor3f(0.9f, 0.0f, 0.0f);
        // Scarf wrapped around neck
        glBegin(GL_POLYGON);
        glVertex2f(-0.15f, -0.50f); glVertex2f(0.15f, -0.50f); glVertex2f(0.20f, -0.65f); glVertex2f(-0.20f, -0.65f);
        glEnd();
        // Hanging part
        glBegin(GL_POLYGON);
        glVertex2f(0.10f, -0.65f); glVertex2f(0.18f, -0.65f); glVertex2f(0.18f, -0.90f); glVertex2f(0.10f, -0.90f);
        glEnd();
    }
}

// Legs
void Character::drawLegs() {
    // Like long socks
    if (gameState == Winter) {
        glColor3f(0.5, 0.5, 0.5);
    }
    else {
        glColor3f(1.0, 0.9, 0.8);
    }
    // left
    glBegin(GL_POLYGON);
    glVertex2f(-0.20f, -1.75f); glVertex2f(-0.05f, -1.75f); glVertex2f(-0.05f, -2.45f); glVertex2f(-0.20f, -2.45f);
    glEnd();
    // right
    glBegin(GL_POLYGON);
    glVertex2f(0.05f, -1.75f); glVertex2f(0.20f, -1.75f); glVertex2f(0.20f, -2.45f); glVertex2f(0.05f, -2.45f);
    glEnd();
}

// Skirt
void Character::drawSkirt() {
    if (gameState == Autumn) {
        // Autumn = textured skirt
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, autumnTexture);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0); glVertex2f(-0.35f, -1.25f); glTexCoord2f(1.0, 0.0); glVertex2f(0.35f, -1.25f); glTexCoord2f(1.0, 1.0); glVertex2f(0.55f, -1.95f); glTexCoord2f(0.0, 1.0); glVertex2f(-0.55f, -1.95f);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else {
        glColor3f(0.9f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.35f, -1.25f); glVertex2f(0.35f, -1.25f); glVertex2f(0.55f, -1.95f); glVertex2f(-0.55f, -1.95f);
        glEnd();
        // Draw pleats on the skirt  
        glColor3f(0.05f, 0.05f, 0.05f);
        glLineWidth(1.2);
        glBegin(GL_LINES);
        glVertex2f(-0.15f, -1.25f); glVertex2f(-0.25f, -1.95f); glVertex2f(0.0f, -1.25f); glVertex2f(0.0f, -1.95f); glVertex2f(0.15f, -1.25f);  glVertex2f(0.25f, -1.95f);
        glEnd();
    }
}

// Summer skirt
void Character::drawSummerSkirt()
{
    if (gameState == Summer) {
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(-0.35f, -1.25f); glVertex2f(0.35f, -1.25f); glVertex2f(0.55f, -1.95f); glVertex2f(-0.55f, -1.95f);
        glEnd();
    }
}

// Socks and shoes
void Character::drawFeet() {
    glColor3f(1.0f, 1.0f, 1.0f);
    // Left sock (small rectangle above shoe)
    glBegin(GL_POLYGON);
    glVertex2f(-0.20f, -2.35f); glVertex2f(-0.05f, -2.35f); glVertex2f(-0.05f, -2.50f); glVertex2f(-0.20f, -2.50f);
    glEnd();
    // Right sock
    glBegin(GL_POLYGON);
    glVertex2f(0.05f, -2.35f); glVertex2f(0.20f, -2.35f); glVertex2f(0.20f, -2.50f); glVertex2f(0.05f, -2.50f);
    glEnd();

    // Left shoe
    if (gameState == Autumn) {
        glColor3f(0.72f, 0.43f, 0.16f);
    }
    else if (gameState == Summer) {
        glColor3f(1.0f, 0.7f, 0.8f);
    }
    // Spring case
    else if (gameState == Spring) {
        glColor3f(1.0f, 0.45f, 0.65f);
    }
    else {
        glColor3f(0.8f, 0.0f, 0.0f);
    }
    glBegin(GL_POLYGON);
    glVertex2f(-0.28f, -2.50f); glVertex2f(-0.07f, -2.50f); glVertex2f(-0.05f, -2.70f); glVertex2f(-0.30f, -2.70f);
    glEnd();

    // Right shoe
    if (gameState == Autumn) {
        glColor3f(0.72f, 0.43f, 0.16f);
    }
    else if (gameState == Summer) {
        glColor3f(1.0f, 0.7f, 0.8f);
    }
    // Spring case
    else if (gameState == Spring) {
        glColor3f(1.0f, 0.45f, 0.65f);
    }
    else {
        glColor3f(0.8f, 0.0f, 0.0f);
    }
    glBegin(GL_POLYGON);
    glVertex2f(0.07f, -2.50f); glVertex2f(0.28f, -2.50f); glVertex2f(0.30f, -2.70f); glVertex2f(0.05f, -2.70f);
    glEnd();
}

// Sleeves and hands
void Character::drawArms() {
    glColor3f(1.0f, 1.0f, 1.0f);
    // Left sleeve (covers shoulder area)
     // Winter case
    if (gameState == Winter) {
        glColor3f(1.0f, 1.0f, 0.6f);
    }
    // Other seasons
    else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glBegin(GL_POLYGON);
    glVertex2f(-0.35f, -0.60f); glVertex2f(-0.52f, -0.70f); glVertex2f(-0.52f, -1.05f); glVertex2f(-0.30f, -1.05f);
    glEnd();
    // Right sleeve
    // Winter case
    if (gameState == Winter) {
        glColor3f(1.0f, 1.0f, 0.6f);
    }
    // Other seasons
    else {
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glBegin(GL_POLYGON);
    glVertex2f(0.35f, -0.60f); glVertex2f(0.52f, -0.70f); glVertex2f(0.52f, -1.05f); glVertex2f(0.30f, -1.05f);
    glEnd();

    // Hands
    glColor3f(1.0, 0.9, 0.8);
    // Left hand
    glBegin(GL_POLYGON);
    glVertex2f(-0.35f, -1.05f); glVertex2f(-0.48f, -1.05f); glVertex2f(-0.48f, -1.50f); glVertex2f(-0.35f, -1.50f);
    glEnd();
    // Right hand
    glBegin(GL_POLYGON);
    glVertex2f(0.35f, -1.05f); glVertex2f(0.48f, -1.05f); glVertex2f(0.48f, -1.50f); glVertex2f(0.35f, -1.50f);
    glEnd();
}

// Summer sunglasses
void Character::drawSunglasses() {
    if (gameState == Summer) {
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(-0.16f, -0.04f, 0.11f); // Left Lens
        drawCircle(0.16f, -0.04f, 0.11f);  // Right Lens
        glLineWidth(2.5f);
        glBegin(GL_LINES);
        glVertex2f(-0.05f, -0.04f); glVertex2f(0.05f, -0.04f); // Bridge
        glVertex2f(-0.27f, -0.04f); glVertex2f(-0.52f, -0.08f); // Left temple
        glVertex2f(0.27f, -0.04f); glVertex2f(0.52f, -0.08f);  // Right temple
        glEnd();
    }
}

// Ice Cream 
void Character::drawIceCream() {
    // Summer case
    if (gameState == Summer) {
        // Cone
        glColor3f(0.8f, 0.5f, 0.2f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.38f, -0.90f); glVertex2f(0.50f, -0.90f); glVertex2f(0.44f, -1.35f);
        glEnd();
        // Scoop
        glColor3f(1.0f, 0.5f, 0.7f);
        drawCircle(0.44f, -0.85f, 0.13f);
    }
}

// Function to assemble all character parts
void Character::MyMainObj()
{
    glPushMatrix();
    glTranslatef(300.0f + charX, 350.0f + charY, 0.0f); // Character position
    glScalef(80, 80, 1);       // Character size

    DrawBackHair(); DrawEarLeft(); DrawEarRight(); DrawFace(); DrawTopHairSimple(); DrawBangs(); DrawEyes(); DrawEyebrows(); DrawCheeks(); DrawSmile(); drawSunglasses();
    drawNeck(); drawScarf(); drawTorso(); drawAutumnTorso(); drawSummerTorso(); drawArms(); drawLegs(); drawSkirt(); drawSummerSkirt(); drawFeet(); drawIceCream();
    glPopMatrix();
}

// Spring outfit uses two textures: floral shirt and pink skirt
// ############## Spring Clothes ##############
void Character::drawTexturedTorsoSpring() {
    if (spring1Texture != 0) {
        glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, spring1Texture); C3(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); T2(0.0, 1.0); V2(-0.35, -0.60); T2(1.0, 1.0); V2(0.35, -0.60); T2(1.0, 0.0); V2(0.30, -1.25); T2(0.0, 0.0); V2(-0.30, -1.25); glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else { C3(1.0, 0.92, 0.88); glBegin(GL_POLYGON); V2(-0.35, -0.60); V2(0.35, -0.60); V2(0.30, -1.25); V2(-0.30, -1.25); glEnd(); }
}

void Character::drawTexturedSkirtSpring() {
    if (spring2Texture != 0) {
        glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, spring2Texture); C3(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); T2(0.0, 1.0); V2(-0.35, -1.25); T2(1.0, 1.0); V2(0.35, -1.25); T2(1.0, 0.0); V2(0.55, -1.95); T2(0.0, 0.0); V2(-0.55, -1.95); glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else { C3(1.0, 0.45, 0.65); glBegin(GL_POLYGON); V2(-0.35, -1.25); V2(0.35, -1.25); V2(0.55, -1.95); V2(-0.55, -1.95); glEnd(); }

    C3(0.05, 0.05, 0.05); glLineWidth(1.2f);
    glBegin(GL_LINES); V2(-0.15, -1.25); V2(-0.25, -1.95); V2(0.0, -1.25); V2(0.0, -1.95); V2(0.15, -1.25); V2(0.25, -1.95); glEnd();
}

void Character::drawSpringArms() {
    if (spring1Texture != 0) {
        glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, spring1Texture); C3(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); T2(0.0, 1.0); V2(-0.35, -0.60); T2(1.0, 1.0); V2(-0.52, -0.70); T2(1.0, 0.0); V2(-0.52, -1.05); T2(0.0, 0.0); V2(-0.30, -1.05); glEnd();
        glBegin(GL_POLYGON); T2(0.0, 1.0); V2(0.35, -0.60); T2(1.0, 1.0); V2(0.52, -0.70); T2(1.0, 0.0); V2(0.52, -1.05); T2(0.0, 0.0); V2(0.30, -1.05); glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    else {
        C3(1.0, 0.92, 0.88); glBegin(GL_POLYGON); V2(-0.35, -0.60); V2(-0.52, -0.70); V2(-0.52, -1.05); V2(-0.30, -1.05); glEnd();
        glBegin(GL_POLYGON); V2(0.35, -0.60); V2(0.52, -0.70); V2(0.52, -1.05); V2(0.30, -1.05); glEnd();
    }

    C3(1.0, 0.9, 0.8);
    glBegin(GL_POLYGON); V2(-0.35, -1.05); V2(-0.48, -1.05); V2(-0.48, -1.50); V2(-0.35, -1.50); glEnd();
    glBegin(GL_POLYGON); V2(0.35, -1.05); V2(0.48, -1.05); V2(0.48, -1.50); V2(0.35, -1.50); glEnd();
}

// Spring version of the character with textured clothes
void Character::MySpringObj() {
    glPushMatrix(); Translate(345.0 + charX, 300.0 + charY, 0.0); Scale(65.0, 65.0, 1.0);
    DrawBackHair(); DrawEarLeft(); DrawEarRight(); DrawFace(); DrawTopHairSimple(); DrawBangs(); DrawEyes(); DrawEyebrows(); DrawCheeks(); DrawSmile();
    drawNeck(); drawTexturedTorsoSpring(); drawSpringArms(); drawLegs(); drawTexturedSkirtSpring(); drawFeet();
    glPopMatrix();
}

