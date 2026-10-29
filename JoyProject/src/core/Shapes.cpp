#include "core/Shapes.h"
#include <cmath>

  //////////
//Variables//
 //////////
int windowWidth = 1024; int windowHeight = 600; GLdouble PI = 3.14159265359; int triangleAmount = 200; float twicePi = 2.0f * PI;

  ///////////////
//Basic functions//
 ////////////////


// Helper functions to reduce type-conversion warnings in OpenGL calls
// Source: OpenGL fixed-function transformation reference https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/
// ############## Safe OpenGL Helpers ##############
void V2(double x, double y) { glVertex2f(static_cast<GLfloat>(x), static_cast<GLfloat>(y)); }
void C3(double r, double g, double b) { glColor3f(static_cast<GLfloat>(r), static_cast<GLfloat>(g), static_cast<GLfloat>(b)); }
void C4(double r, double g, double b, double a) { glColor4f(static_cast<GLfloat>(r), static_cast<GLfloat>(g), static_cast<GLfloat>(b), static_cast<GLfloat>(a)); }
void T2(double u, double v) { glTexCoord2f(static_cast<GLfloat>(u), static_cast<GLfloat>(v)); }
void Translate(double x, double y, double z) { glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z)); }
void Scale(double x, double y, double z) { glScalef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z)); }
void Rotate(double angle, double x, double y, double z) { glRotatef(static_cast<GLfloat>(angle), static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z)); }

// Function to write text
void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

// Circle
void drawCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);

    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }

    glEnd();
}

// Ellipse helper used for clouds, flowers, butterfly wings
void drawEllipse(double x, double y, double rx, double ry) {
    glBegin(GL_TRIANGLE_FAN);
    V2(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        double angle = static_cast<double>(i) * twicePi / static_cast<double>(triangleAmount);
        V2(x + rx * cos(angle), y + ry * sin(angle));
    }
    glEnd();
}