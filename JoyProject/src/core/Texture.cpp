#include "core/Texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Function to load BMP images and convert them to OpenGL textures
GLuint LoadTexture(const char* filename, int width, int height)
{
    GLuint texture;
    unsigned char* data;
    FILE* file;

    //The following code will read in our RAW file
    //file = fopen(filename, "rb");
    fopen_s(&file, filename, "rb");

    if (file == NULL)
    {
        cout << "Warning: Texture not found -> " << filename << endl;
        return 0;
    }

    data = (unsigned char*)malloc(width * height * 3);
    fseek(file, 54, SEEK_SET); // Skip BMP header (54 bytes)
    fread(data, width * height * 3, 1, file);
    fclose(file);

    // reorder the image colors to RGB not BGR
    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;

    }

    glGenTextures(1, &texture);            //generate the texture with the loaded data
    glBindTexture(GL_TEXTURE_2D, texture); //bind the texture to it's array

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);  //set texture environment parameters

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    free(data); //free the texture array

    if (glGetError() != GL_NO_ERROR)
        printf("GLError in genTexture()\n");

    return texture; //return whether it was successfull 
}