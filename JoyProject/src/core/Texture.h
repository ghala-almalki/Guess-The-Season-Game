#pragma once
#include "core/Shapes.h"

// Function to load BMP images and convert them to OpenGL textures
GLuint LoadTexture(const char* filename, int width, int height);