#pragma once
#include "scenes/Scene.h"

// Summer scene as a class. All helpers are private because
// no other scene uses them
class SummerScene : public Scene {
public:
    void draw() override;   

private:
    // Sea and sky
    void drawWaves();
    void drawBird(float x, float y, float size);

    // Beach items
    void drawShell(float x, float y, float size);
    void drawStarfish(float x, float y, float radius);
    void drawSandToy(float x, float y, float scale);
};

// One shared Summer scene object defined in (SummerScene.cpp)
extern SummerScene summerScene;