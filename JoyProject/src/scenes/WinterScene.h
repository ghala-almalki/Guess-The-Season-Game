#pragma once
#include "scenes/Scene.h"

// Winter scene as a class
class WinterScene : public Scene {
public:
    void draw() override;   

private:
    void drawMountain(float x, float y, float scale);
    void drawSnowman(float x, float y, float scale);
    void drawWinterTree(float x, float y, float scale);
};

extern WinterScene winterScene;