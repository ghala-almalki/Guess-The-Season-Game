#pragma once
#include "scenes/Scene.h"

// Start screen as a class. The decorative helpers are private
// because only this screen uses them.
class StartScreen : public Scene {
public:
    void draw() override;   

private:
    void drawRedFlower(float x, float y, float size);
    void drawFancyBee(float x, float y, float scale);
};

// One shared Start screen object defined in (StartScreen.cpp)
extern StartScreen startScreen;