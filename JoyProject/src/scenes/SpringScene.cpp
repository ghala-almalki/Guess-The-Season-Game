#include "scenes/SpringScene.h"
#include "scenes/Environment.h"
#include "core/Shapes.h"
#include "core/GameState.h"
#include "character/Character.h"
#include <cmath>

// Variables that live in JoyProject.cpp
extern GLuint spring3Texture;
extern float butterflyTime;
extern float windmillAngle;

SpringScene springScene;

// Alias for cloud drawing used in Spring scene
void SpringScene::drawStylizedCloud(float x, float y, float size) {
    drawCloud(x, y, size);
}

void SpringScene::drawSimpleTree(double x, double y, double scale) {

    // trunk
    C3(0.45, 0.26, 0.08);
    glBegin(GL_QUADS);
    V2(x - 5.0 * scale, y);
    V2(x + 5.0 * scale, y);
    V2(x + 5.0 * scale, y + 40.0 * scale);
    V2(x - 5.0 * scale, y + 40.0 * scale);
    glEnd();

    // base shadow (Very dark)
    C3(0.04, 0.28, 0.18);
    drawCircle(x, y + 48.0 * scale, 26.0 * scale);
    drawCircle(x - 18.0 * scale, y + 38.0 * scale, 20.0 * scale);
    drawCircle(x + 18.0 * scale, y + 38.0 * scale, 20.0 * scale);

    // main leaves
    C3(0.10, 0.45, 0.25);
    drawCircle(x, y + 55.0 * scale, 23.0 * scale);
    drawCircle(x - 14.0 * scale, y + 48.0 * scale, 18.0 * scale);
    drawCircle(x + 14.0 * scale, y + 48.0 * scale, 18.0 * scale);

    // light highlights
    C3(0.30, 0.70, 0.30);
    drawCircle(x - 6.0 * scale, y + 60.0 * scale, 10.0 * scale);
    drawCircle(x + 10.0 * scale, y + 62.0 * scale, 11.0 * scale);
    drawCircle(x + 5.0 * scale, y + 45.0 * scale, 9.0 * scale);

    // white daisies on tree
    drawDaisy(x - 10.0 * scale, y + 60.0 * scale, 0.30 * scale);
    drawDaisy(x + 12.0 * scale, y + 55.0 * scale, 0.28 * scale);
}

void SpringScene::drawFlower(double x, double y, double size) {
    C3(0.0, 0.8, 0.0); glLineWidth(2.0f); glBegin(GL_LINES); V2(x, y); V2(x, y + size * 2.0); glEnd();
    C3(1.0, 0.0, 0.0); double petalDist = size * 0.8;
    drawCircle(x - petalDist, y + size * 2.0, size * 0.8); drawCircle(x + petalDist, y + size * 2.0, size * 0.8);
    drawCircle(x, y + size * 2.0 + petalDist, size * 0.8); drawCircle(x, y + size * 2.0 - petalDist, size * 0.8);
    C3(1.0, 1.0, 0.0); drawCircle(x, y + size * 2.0, size * 0.5);
}

// White daisy flower used on hills, bushes, and trees
void SpringScene::drawDaisy(double x, double y, double s) {
    C3(0.18, 0.55, 0.18); glLineWidth(1.5f); glBegin(GL_LINES); V2(x, y); V2(x, y + 12.0 * s); glEnd();
    C3(1.0, 1.0, 1.0);
    for (int a = 0; a < 360; a += 45) {
        double rad = a * PI / 180.0;
        drawEllipse(x + cos(rad) * 5.5 * s, y + 12.0 * s + sin(rad) * 5.5 * s, 3.8 * s, 2.0 * s);
    }
    C3(1.0, 0.85, 0.1); drawCircle(x, y + 12.0 * s, 2.5 * s);
}

// Tree variation with daisies
void SpringScene::drawFruitTree(double x, double y, double scale) {
    drawSimpleTree(x, y, scale);

    drawDaisy(x - 12.0 * scale, y + 53.0 * scale, 0.35 * scale);
    drawDaisy(x + 15.0 * scale, y + 48.0 * scale, 0.35 * scale);
    drawDaisy(x + 1.0 * scale, y + 65.0 * scale, 0.32 * scale);
}


// Drawing spring hills and placing daisies on them
void SpringScene::drawBaseHills() {
    C3(0.34, 0.76, 0.28);
    glBegin(GL_POLYGON);
    V2(0.0, 135.0); V2(0.0, 0.0); V2(450.0, 0.0); V2(500.0, 110.0);
    for (int i = 0; i <= triangleAmount; i++) {
        double angle = PI * static_cast<double>(i) / triangleAmount;
        V2(230.0 + cos(angle) * 330.0, 140.0 + sin(angle) * 92.0);
    }
    glEnd();

    C3(0.30, 0.70, 0.25);
    glBegin(GL_POLYGON);
    V2(560.0, 95.0); V2(1040.0, 95.0); V2(1040.0, 0.0); V2(520.0, 0.0);
    for (int i = 0; i <= triangleAmount; i++) {
        double angle = PI * static_cast<double>(i) / triangleAmount;
        V2(790.0 + cos(angle) * 315.0, 128.0 + sin(angle) * 88.0);
    }
    glEnd();

    drawDaisy(80.0, 150.0, 0.85);
    drawDaisy(125.0, 190.0, 0.75);
    drawDaisy(210.0, 165.0, 0.90);
    drawDaisy(355.0, 185.0, 0.80);
    drawDaisy(430.0, 145.0, 0.80);
    drawDaisy(35.0, 35.0, 0.80);
    drawDaisy(200.0, 40.0, 0.80);
    drawDaisy(800.0, 40.0, 0.80);
    drawDaisy(700.0, 20.0, 0.80);
    drawFruitTree(20.0, 70.0, 1.50);
    drawFruitTree(90.0, 30.0, 1.40);

}

// Drawing left side mountains with green peaks and snow tops
void SpringScene::drawLeftMountainWithTrees() {

    // First Mountain
    C3(0.20, 0.50, 0.28);
    glBegin(GL_TRIANGLES);
    V2(0.0, 200.0); V2(120.0, 420.0); V2(250.0, 200.0);
    glEnd();

    // Second Mountain
    C3(0.16, 0.38, 0.22);
    glBegin(GL_TRIANGLES);
    V2(200.0, 195.0); V2(280.0, 320.0); V2(360.0, 195.0);
    glEnd();

    // Snow caps
    C3(0.95, 0.98, 1.0);

    // Peak 1
    glBegin(GL_TRIANGLES);
    V2(87.0, 360.0);
    V2(120.0, 420.0);
    V2(156.0, 360.0);
    glEnd();

    // Peak 2
    glBegin(GL_TRIANGLES);
    V2(260.0, 290.0);
    V2(280.0, 320.0);
    V2(300.0, 290.0);
    glEnd();

    drawFruitTree(615.0, 150.0, 1.50);
    drawFruitTree(669.0, 140.0, 1.25);
    drawFruitTree(640.0, 70.0, 1.00);
    drawFruitTree(1000.0, 50.0, 1.10);
    drawFruitTree(950.0, 30.0, 1.00);
    drawFruitTree(100.0, 190.0, 1.40);
    drawFruitTree(150.0, 185.0, 1.20);
    drawFruitTree(200.0, 190.0, 1.40);
    drawFlower(145.0, 150.0, 5.0);
    drawFlower(190.0, 100.0, 5.0);
    drawFlower(260.0, 145.0, 4.8);
    drawFlower(390.0, 155.0, 4.5);
}

// Drawing river with texture
void SpringScene::drawLongRiverBesidePath() {
    if (spring3Texture != 0) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, spring3Texture);
        C3(1.0, 1.0, 1.0);

        glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f); V2(455.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); V2(620.0, 0.0);
        glTexCoord2f(1.0f, 1.0f); V2(570.0, 215.0);
        glTexCoord2f(0.0f, 1.0f); V2(400.0, 230.0);

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
    else {
        C3(0.28, 0.65, 0.95);

        glBegin(GL_POLYGON);
        V2(455.0, 0.0);
        V2(600.0, 0.0);
        V2(585.0, 170.0);
        V2(565.0, 250.0);
        V2(510.0, 270.0);
        V2(455.0, 250.0);
        glEnd();
    }
}

// Drawing the dirt path for the character
void SpringScene::drawDirtPath() {
    C3(0.43, 0.26, 0.12);
    glBegin(GL_POLYGON); V2(250.0, 0.0); V2(455.0, 0.0); V2(405.0, 230.0); V2(315.0, 230.0); glEnd();
    C3(0.78, 0.64, 0.45);
    glBegin(GL_POLYGON); V2(275.0, 0.0); V2(428.0, 0.0); V2(390.0, 230.0); V2(330.0, 230.0); glEnd();
    C3(0.58, 0.40, 0.22); glLineWidth(2.0f);
    glBegin(GL_LINES); V2(300.0, 35.0); V2(415.0, 35.0); V2(292.0, 82.0); V2(410.0, 82.0); V2(315.0, 135.0); V2(398.0, 135.0); glEnd();
}

// Tulip drawing helper
void SpringScene::drawTulip(double x, double y, double size, double r, double g, double b) {
    C3(0.0, 0.55, 0.15); glLineWidth(2.0f);
    glBegin(GL_LINES); V2(x, y); V2(x, y + size * 3.2); glEnd();
    glBegin(GL_TRIANGLES);
    V2(x, y + size * 1.4); V2(x - size * 1.1, y + size * 2.0); V2(x, y + size * 2.1);
    V2(x, y + size * 1.6); V2(x + size * 1.1, y + size * 2.2); V2(x, y + size * 2.2);
    glEnd();
    C3(r, g, b); glBegin(GL_POLYGON);
    V2(x - size * 1.0, y + size * 3.0); V2(x - size * 0.7, y + size * 4.0); V2(x, y + size * 3.6);
    V2(x + size * 0.7, y + size * 4.0); V2(x + size * 1.0, y + size * 3.0); V2(x + size * 0.55, y + size * 2.4); V2(x - size * 0.55, y + size * 2.4);
    glEnd();
    C3(r * 0.85, g * 0.85, b * 0.85); glBegin(GL_TRIANGLES);
    V2(x - size * 0.8, y + size * 3.0); V2(x - size * 0.2, y + size * 4.35); V2(x + size * 0.1, y + size * 3.0);
    V2(x + size * 0.8, y + size * 3.0); V2(x + size * 0.2, y + size * 4.35); V2(x - size * 0.1, y + size * 3.0);
    glEnd();
}

// Garden fence
void SpringScene::drawWhiteFence(double x, double y, double w) {
    C3(1.0, 1.0, 1.0);
    for (double px = x; px <= x + w; px += 30.0) {
        glBegin(GL_QUADS); V2(px, y); V2(px + 8.0, y); V2(px + 8.0, y + 34.0); V2(px, y + 34.0); glEnd();
        glBegin(GL_TRIANGLES); V2(px - 2.0, y + 34.0); V2(px + 10.0, y + 34.0); V2(px + 4.0, y + 43.0); glEnd();
    }
    glBegin(GL_QUADS); V2(x - 12.0, y + 11.0); V2(x + w + 18.0, y + 11.0); V2(x + w + 18.0, y + 18.0); V2(x - 12.0, y + 18.0); glEnd();
    glBegin(GL_QUADS); V2(x - 12.0, y + 27.0); V2(x + w + 18.0, y + 27.0); V2(x + w + 18.0, y + 34.0); V2(x - 12.0, y + 34.0); glEnd();
}

// Creating a field of tulips
void SpringScene::drawTulipGarden() {
    for (int row = 0; row < 4; row++) {
        for (int i = 0; i < 16; i++) {

            double x = 700.0 + i * 20.0 + row * 4.0;
            double y = 80.0 + row * 26.0;

            double s = 8.0;

            if (row % 3 == 0)
                drawTulip(x, y, s, 1.0, 0.10, 0.18);
            else if (row % 3 == 1)
                drawTulip(x, y, s, 1.0, 0.45, 0.10);
            else
                drawTulip(x, y, s, 1.0, 0.75, 0.15);
        }
    }

    drawWhiteFence(585.0, 190.0, 390.0);
}

// Windmill for background decoration
void SpringScene::drawWindmill(double x, double y, double scale) {
    glPushMatrix();
    Translate(x, y, 0.0);
    Scale(scale, scale, 1.0);

    // Mill body
    C3(0.45, 0.28, 0.12); glBegin(GL_POLYGON); V2(-35.0, 0.0); V2(35.0, 0.0); V2(25.0, 95.0); V2(-25.0, 95.0); glEnd();
    C3(0.30, 0.18, 0.08); glBegin(GL_TRIANGLES); V2(-42.0, 95.0); V2(42.0, 95.0); V2(0.0, 135.0); glEnd();
    C3(0.15, 0.10, 0.05); glBegin(GL_POLYGON); V2(-10.0, 0.0); V2(10.0, 0.0); V2(10.0, 35.0); V2(-10.0, 35.0); glEnd();
    C3(0.9, 0.75, 0.45); drawCircle(0.0, 75.0, 6.0);

    // Rotating blades
    C3(0.55, 0.38, 0.18);
    for (int a = 0; a < 360; a += 90) {
        glPushMatrix();
        Translate(0.0, 75.0, 0.0);
        Rotate(static_cast<double>(a) + windmillAngle, 0.0, 0.0, 1.0);
        glBegin(GL_POLYGON); V2(0.0, -3.0); V2(75.0, -8.0); V2(80.0, 8.0); V2(0.0, 3.0); glEnd();
        glPopMatrix();
    }
    glPopMatrix();
}

// Animated butterflies with wing flapping logic
void SpringScene::drawButterfly(double x, double y, double s, double phase, double r, double g, double b) {
    double flap = sin(butterflyTime * 6.0 + phase) * 4.0;
    double bob = sin(butterflyTime * 2.0 + phase) * 8.0;

    glPushMatrix();
    Translate(x + sin(butterflyTime + phase) * 8.0, y + bob, 0.0);
    Scale(s, s, 1.0);

    C3(r, g, b);
    glPushMatrix(); Rotate(-20.0 + flap, 0.0, 0.0, 1.0); drawEllipse(-6.0, 3.0, 7.0, 4.0); glPopMatrix();
    glPushMatrix(); Rotate(20.0 - flap, 0.0, 0.0, 1.0); drawEllipse(6.0, 3.0, 7.0, 4.0); glPopMatrix();
    glPushMatrix(); Rotate(15.0 - flap, 0.0, 0.0, 1.0); drawEllipse(-5.0, -4.0, 5.0, 3.5); glPopMatrix();
    glPushMatrix(); Rotate(-15.0 + flap, 0.0, 0.0, 1.0); drawEllipse(5.0, -4.0, 5.0, 3.5); glPopMatrix();

    C3(0.10, 0.08, 0.05);
    drawEllipse(0.0, 0.0, 1.8, 6.0);
    glLineWidth(1.2f);
    glBegin(GL_LINES); V2(0.0, 5.0); V2(-5.0, 10.0); V2(0.0, 5.0); V2(5.0, 10.0); glEnd();

    glPopMatrix();
}


void SpringScene::drawButterflies() {
    // Three butterflies near the tulips
    drawButterfly(665.0, 290.0, 1.05, 0.0, 1.0, 0.35, 0.75);
    drawButterfly(760.0, 210.0, 0.95, 1.2, 1.0, 0.75, 0.20);
    drawButterfly(900.0, 250.0, 1.00, 2.2, 0.60, 0.45, 1.0);

    // Five butterflies around the trees
    drawButterfly(95.0, 190.0, 0.90, 0.5, 1.0, 0.65, 0.15);
    drawButterfly(150.0, 145.0, 0.85, 1.6, 0.75, 0.40, 1.0);
    drawButterfly(220.0, 80.0, 0.80, 2.6, 1.0, 0.45, 0.55);
    drawButterfly(259.0, 139.0, 0.88, 3.3, 0.30, 0.75, 1.0);
    drawButterfly(200.0, 130.0, 0.82, 4.0, 1.0, 0.85, 0.20);
}

// Drawing bushes with daisies
void SpringScene::drawBush(double x, double y, double s) {

    // Dark base shadow
    C3(0.04, 0.28, 0.18);
    drawCircle(x + 5.0 * s, y - 2.0 * s, 14.0 * s);
    drawCircle(x + 22.0 * s, y - 4.0 * s, 16.0 * s);
    drawCircle(x + 38.0 * s, y - 2.0 * s, 14.0 * s);

    // Main bush body
    C3(0.10, 0.45, 0.25);
    drawCircle(x + 2.0 * s, y + 8.0 * s, 13.0 * s);
    drawCircle(x + 15.0 * s, y + 15.0 * s, 17.0 * s);
    drawCircle(x + 32.0 * s, y + 14.0 * s, 18.0 * s);
    drawCircle(x + 48.0 * s, y + 8.0 * s, 13.0 * s);

    // Medium green patches
    C3(0.24, 0.62, 0.30);
    drawCircle(x + 12.0 * s, y + 20.0 * s, 9.0 * s);
    drawCircle(x + 28.0 * s, y + 23.0 * s, 10.0 * s);
    drawCircle(x + 42.0 * s, y + 17.0 * s, 8.0 * s);
    drawCircle(x + 20.0 * s, y + 7.0 * s, 8.0 * s);

    // Light highlights
    C3(0.55, 0.85, 0.28);
    drawCircle(x + 14.0 * s, y + 25.0 * s, 4.5 * s);
    drawCircle(x + 30.0 * s, y + 27.0 * s, 5.0 * s);
    drawCircle(x + 39.0 * s, y + 21.0 * s, 4.0 * s);
    drawCircle(x + 23.0 * s, y + 13.0 * s, 4.0 * s);

    // Daisies on bush
    drawDaisy(x + 10.0 * s, y + 30.0 * s, 0.28 * s);
    drawDaisy(x + 30.0 * s, y + 32.0 * s, 0.25 * s);
    drawDaisy(x + 43.0 * s, y + 24.0 * s, 0.22 * s);
}


// Spring Scene
void SpringScene::draw() {
    // Sky background
    glBegin(GL_QUADS);
    C3(0.55, 0.82, 1.0); V2(0.0, 0.0);
    C3(0.55, 0.82, 1.0); V2(windowWidth, 0.0);
    C3(0.82, 0.95, 1.0); V2(windowWidth, windowHeight);
    C3(0.82, 0.95, 1.0); V2(0.0, windowHeight);
    glEnd();

    drawAttractiveSun(150.0, 480.0, 45.0);
    drawStylizedCloud(560.0, 525.0, 22.0);
    drawStylizedCloud(825.0, 485.0, 20.0);
    drawStylizedCloud(300.0, 470.0, 25.0);
    drawStylizedCloud(450.0, 430.0, 24.0);

    drawBaseHills();
    drawLongRiverBesidePath();

    drawDirtPath();

    // Bush borders around river and path
    drawBush(400.0, 225.0, 0.85);
    drawBush(403.0, 210.0, 0.85);
    drawBush(404.0, 180.0, 0.85);
    drawBush(405.0, 150.0, 0.85);
    drawBush(410.0, 120.0, 0.85);
    drawBush(415.0, 90.0, 0.85);
    drawBush(420.0, 60.0, 0.85);
    drawBush(425.0, 30.0, 0.85);
    drawBush(430.0, 0.0, 0.85);

    drawBush(530.0, 225.0, 0.85);
    drawBush(540.0, 210.0, 0.85);
    drawBush(550.0, 180.0, 0.85);
    drawBush(560.0, 150.0, 0.85);
    drawBush(570.0, 120.0, 0.85);
    drawBush(580.0, 90.0, 0.85);
    drawBush(590.0, 60.0, 0.85);
    drawBush(600.0, 30.0, 0.85);
    drawBush(610.0, 0.0, 0.85);


    drawTulipGarden();
    drawLeftMountainWithTrees();

    // Small bushes placement
    drawBush(20.0, 70.0, 0.40);
    drawBush(10.0, 70.0, 0.40);
    drawBush(90.0, 30.0, 0.40);
    drawBush(80.0, 30.0, 0.40);
    drawBush(615.0, 150.0, 0.40);
    drawBush(605.0, 150.0, 0.40);
    drawBush(669.0, 140.0, 0.40);
    drawBush(659.0, 140.0, 0.40);
    drawBush(640.0, 70.0, 0.40);
    drawBush(630.0, 70.0, 0.40);
    drawBush(1000.0, 50.0, 0.40);
    drawBush(990.0, 50.0, 0.40);
    drawBush(950.0, 30.0, 0.40);
    drawBush(940.0, 30.0, 0.40);
    drawBush(100.0, 190.0, 0.40);
    drawBush(90.0, 190.0, 0.40);
    drawBush(150.0, 185.0, 0.40);
    drawBush(140.0, 185.0, 0.40);
    drawBush(200.0, 190.0, 0.40);
    drawBush(190.0, 190.0, 0.40);


    drawButterflies();
    drawWindmill(980.0, 190.0, 1.20);

    character.MySpringObj();

    C3(0.05, 0.25, 0.25);
    drawText(455.0, 555.0, "   Spring");
}

