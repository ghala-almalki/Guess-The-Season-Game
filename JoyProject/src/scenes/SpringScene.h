#pragma once
#include "scenes/Scene.h"

// Spring scene as a class. All helpers are private because
// no other scene uses them
class SpringScene : public Scene {
public:
    void draw() override;   

private:
    // Trees, flowers and plants
    void drawSimpleTree(double x, double y, double scale);
    void drawFlower(double x, double y, double size);
    void drawDaisy(double x, double y, double s);
    void drawFruitTree(double x, double y, double scale);
    void drawBush(double x, double y, double s);
    void drawTulip(double x, double y, double size, double r, double g, double b);
    void drawTulipGarden();

    // Landscape
    void drawBaseHills();
    void drawLeftMountainWithTrees();
    void drawLongRiverBesidePath();
    void drawDirtPath();
    void drawWhiteFence(double x, double y, double w);
    void drawWindmill(double x, double y, double scale);

    // Animated and sky elements
    void drawButterfly(double x, double y, double s, double phase, double r, double g, double b);
    void drawButterflies();
    void drawStylizedCloud(float x, float y, float size);
};

// One shared Spring scene object defined in (SpringScene.cpp)
extern SpringScene springScene;