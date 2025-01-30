#include <cstring>
#include "shader.h"


namespace UB
{

Shader::Shader() : shaderType(0), shaderId(0)
{}


Shader::Shader(const char* shaderSrc, GLenum shaderType) : shaderSrc(shaderSrc), shaderType(shaderType)
{
    compileShader(shaderSrc, shaderType);
}


Shader::Shader(const std::string& shaderFilePath, GLenum shaderType)
{
    std::ifstream shaderStream(shaderFilePath, std::ios::in);

    if(shaderStream.is_open()){
        std::stringstream sstr;
        sstr << shaderStream.rdbuf();
        shaderSrc = sstr.str().c_str();
        shaderStream.close();
    }

    compileShader(shaderSrc.c_str(), shaderType);
}


void Shader::compileShader(const char* shaderSrc, GLenum shaderType)
{
    shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderSrc, NULL);
    glCompileShader(shaderId);
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &log.success);

    if(!log.success){
        glGetShaderInfoLog(shaderId, 512, NULL, log.infoLog);
        std::cout << "Error " << shaderType << " compile..." << log.infoLog << std::endl;
    }
}


void Shader::deleteShader() const
{ glDeleteShader(shaderId); }


unsigned int Shader::getShaderId() const
{ return shaderId; }




ShaderProgram::ShaderProgram() : shaderProgramId(0)
{}


ShaderProgram::ShaderProgram(const Shader& vShader, const Shader& fShader) : vShader(vShader), fShader(fShader), shaderProgramId(0)
{
    createProgram(vShader, fShader);
}


void ShaderProgram::createProgram(const Shader& vShader, const Shader& fShader)
{
    shaderProgramId = glCreateProgram();
    glAttachShader(shaderProgramId, vShader.getShaderId());
    glAttachShader(shaderProgramId, fShader.getShaderId());
    glLinkProgram(shaderProgramId);
    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &log.success);

    if(!log.success){
        glGetProgramInfoLog(shaderProgramId, 512, NULL, log.infoLog);
        std::cout << "Error shaderProgram compile..." << log.infoLog << std::endl;
    }
}


void Shader::srcShaderTracking() const
{

}


unsigned int ShaderProgram::getID()
{
    return shaderProgramId;
}


ShaderProgram& ShaderProgram::useProgram()
{
    glUseProgram(shaderProgramId);

    return *this;
}


void ShaderProgram::setInt(const std::string& name, const int value)
{
    glUniform1i(glGetUniformLocation(shaderProgramId, name.c_str()), value);
}


void ShaderProgram::setVec3(const std::string& name, const glm::vec3 &value)
{
    glUniform3fv(glGetUniformLocation(shaderProgramId, name.c_str()), 1, &value[0]);
}


void ShaderProgram::setVec3(const std::string& uniVar, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(shaderProgramId, uniVar.c_str()), x, y, z);
}


void ShaderProgram::setVec4(const std::string& uniVar, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(shaderProgramId, uniVar.c_str()), x, y, z, w);
}


void ShaderProgram::setMat2(const std::string& uniVar, const glm::mat2 &mat)
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgramId, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
}


void ShaderProgram::setMat3(const std::string& uniVar, const glm::mat3 &mat)
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgramId, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
}


void ShaderProgram::setMat4(const std::string& uniVar, const glm::mat4 &mat)
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgramId, uniVar.c_str()), 1, GL_FALSE, &mat[0][0]);
}


void ShaderProgram::setFloat(const std::string& uniVar, const float fVar)
{
    glUniform1f(glGetUniformLocation(shaderProgramId, uniVar.c_str()), fVar);
}


void ShaderProgram::del()
{
    glDeleteProgram(shaderProgramId);
}


ShaderProgram::~ShaderProgram()
{
    del();
}


}
