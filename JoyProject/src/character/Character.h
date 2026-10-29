#pragma once
#include "core/Shapes.h"

class Character {
public:
//Face
void DrawFace();
void DrawBackHair();
void DrawTopHairSimple();
void DrawBangs();
void DrawEarLeft();
void DrawEarRight();
void DrawEyes();
void DrawEyebrows();
void DrawCheeks();
void DrawSmile();

// Body
void drawNeck();
void drawTorso();
void drawAutumnTorso();
void drawSummerTorso();
void drawScarf();
void drawLegs();
void drawSkirt();
void drawSummerSkirt();
void drawFeet();
void drawArms();
void drawSunglasses();
void drawIceCream();

// Spring clothes
void drawTexturedTorsoSpring();
void drawTexturedSkirtSpring();
void drawSpringArms();

// Assemble all parts
void MyMainObj();
void MySpringObj();
};

// One shared character object defined in (Character.cpp)
extern Character character;