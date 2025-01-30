#include "texture.h"
#include <iostream>
#include "../include/GLFW/glfw3.h"


namespace UB
{


Texture::Texture() : data(nullptr), pathToFile(nullptr), width(0), height(0), nrChannels(0)
{}


Texture::Texture(const char* const pathToFile, int width, int height, int nrChannels, bool alpha)
    : pathToFile(pathToFile)
    , nrChannels(0)
    , formatTexture(0)
    , formatImage(0)
    , width(width)
    , height(height)
{
    loadTextureFromFile(pathToFile, nrChannels, alpha);
}


void Texture::loadTextureFromFile(const char* const pathToFile, int nrChannels, bool alpha)
{
    data = stbi_load(pathToFile, &width, &height, &nrChannels, 0);

    stbi_set_flip_vertically_on_load(true);

    if (data)
    {
        alpha ? formatTexture = formatImage = GL_RGBA : formatTexture = formatImage = GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, formatTexture, width, height, 0, formatImage, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);
}


void Texture::setFormat(int format)
{
    format = format;
}


void Texture::setNrChannels(int nrChannels)
{
    nrChannels = nrChannels;
}


void Texture::setSize(int width, int height)
{
    width  = width;
    height = height;
}

}
