#pragma once
#include "scenes/Scene.h"

// Autumn scene as a class. Both helpers are private because
// no other scene uses them.
class AutumnScene : public Scene {
public:
void draw() override;

private:
void drawAutumnTree(float x, float y, float scale);
void drawAutumnLeaf(float x, float y, float size, float r, float g, float b, float angle);
};

// One shared Autumn scene object defined in (AutumnScene.cpp)
extern AutumnScene autumnScene;