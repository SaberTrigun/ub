#ifndef UB_TEXTURE_H
#define UB_TEXTURE_H


#include "../stb_image/stb_image.h"
#include "../include/glad/glad.h"


namespace UB
{


class Texture
{

public:
    Texture();
    Texture(const char* const pathToFile, int width, int height, const int nrChannels, bool alpha);

    void setFormat(int format);
    void setNrChannels(int nrChannels);
    void setSize(int width, int height);

private:
    void loadTextureFromFile(const char* const  pathToFile, int nrChannels, bool alpha);

    unsigned char*    data;
    const char* const pathToFile;
    unsigned int      nrChannels;
    unsigned int      formatTexture; // RGB or RGBA
    unsigned int      formatImage;   // RGB or RGBA
    int               width;
    int               height;
};
}
#endif // UB_TEXTURE_H
