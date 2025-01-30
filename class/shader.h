#ifndef UB_SHADER_H
#define UB_SHADER_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "../include/glad/glad.h"
#include "../include/glm/glm/glm.hpp"


namespace UB
{

struct Log{
    char    infoLog[512];
    int     success;
};


class Shader
{
public:
    Shader();
    Shader(const char* shaderSrc, GLenum shaderType);
    Shader(const std::string& shaderFilePath, GLenum shaderType);

    void compileShader(const char* shaderSrc, GLenum shaderType);

    void deleteShader() const;

    unsigned int getShaderId() const;

    void srcShaderTracking() const;

private:
    std::string     shaderSrc;
    GLuint          shaderType;
    unsigned int    shaderId;
    Log             log;

};



class ShaderProgram
{
public:
    ShaderProgram();
    ShaderProgram(const Shader& vShader, const Shader& fShader);

    void createProgram(const Shader& vShader, const Shader& fShader);

    unsigned int getID();

    ShaderProgram& useProgram();

    void setInt(const std::string& name, const int value);

    void setVec3(const std::string& name, const glm::vec3 &value);

    void setVec3(const std::string& uniVar, float x, float y, float z);

    void setVec4(const std::string& uniVar, float x, float y, float z, float w);

    void setMat2(const std::string& uniVar, const glm::mat2 &mat);

    void setMat3(const std::string& uniVar, const glm::mat3 &mat);

    void setMat4(const std::string& uniVar, const glm::mat4 &mat);

    void setFloat(const std::string& uniVar, const float fVar);

    void del();

    ~ShaderProgram();

private:
    Shader vShader;
    Shader fShader;
    GLuint shaderProgramId;
    Log    log;

};


}



#endif // UB_SHADER_H
