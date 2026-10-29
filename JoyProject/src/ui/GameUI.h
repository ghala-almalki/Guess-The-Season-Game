#pragma once

// In-game interface elements (question box, season buttons, feedback)
// drawRoundedButton is also used by the Start screen (PLAY NOW button)
void drawRoundedButton(float x, float y, float w, float h, float r, float g, float b, const char* text);
void drawGameUI();