#pragma once
#include "scenes/Scene.h"

// End screen as a class. It draws the rainbow background and the
// rotating 3D trophy, switching between 2D and 3D projections internally.
class EndScreen : public Scene {
public:
void draw() override;
};

// One shared End screen object defined in (EndScreen.cpp)
extern EndScreen endScreen;