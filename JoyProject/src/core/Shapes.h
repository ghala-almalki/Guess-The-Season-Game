#pragma once
  //////////
//Libraries//
 //////////
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif

// Shared values (defined in Shapes.cpp)
extern int windowWidth;
extern int windowHeight;
extern GLdouble PI;
extern int triangleAmount;
extern float twicePi;

// Helper functions to reduce type-conversion warnings in OpenGL calls
void V2(double x, double y);
void C3(double r, double g, double b);
void C4(double r, double g, double b, double a);
void T2(double u, double v);
void Translate(double x, double y, double z);
void Scale(double x, double y, double z);
void Rotate(double angle, double x, double y, double z);

// Function to write text
void drawText(float x, float y, const char* text);

// Circle
void drawCircle(GLfloat x, GLfloat y, GLfloat radius);

// Ellipse helper used for clouds, flowers, butterfly wings
void drawEllipse(double x, double y, double rx, double ry);