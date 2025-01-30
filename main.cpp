#include <iostream>
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include "class/shader.h"
#include "class/texture.h"
#include "include/glm/glm/matrix.hpp"
#include "include/glm/glm/gtc/matrix_transform.hpp"
//#include "class/camera.h"

using namespace UB;

int gHeight_scr = 1400;
int gWidth_scr  = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{ glViewport(0, 0, width, height); }


int main(){
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

GLFWwindow* window = glfwCreateWindow(gHeight_scr, gWidth_scr, "OpenGL Window", NULL, NULL);
if(window == NULL){
    std::cout << "Failed to create GLFW Window" << std::endl;
    glfwTerminate();
    return -1;
}

glfwMakeContextCurrent(window);
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout << "Failed initialize GLAD" << std::endl;
    return -1;
}


Shader vShader(std::string("shaders/three/vxShader.src"), GL_VERTEX_SHADER);
Shader fShader(std::string("shaders/three/fgShader.src"), GL_FRAGMENT_SHADER);
ShaderProgram shaderProg(vShader, fShader);
vShader.deleteShader();
fShader.deleteShader();


float vertices[] = {
    // pos            // color
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// 1.0f, 1.0f,
    0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// 1.0f, 0.0f,
   -0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f,// 0.0f, 0.0f,
   -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f // 0.0f, 1.0f
};

int indices[] = {
    0, 1, 3,
    1, 2, 3
};

unsigned int VAO, VBO, EBO;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);
glGenBuffers(1, &EBO);

glBindVertexArray(VAO);

glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);

glBindBuffer(GL_ARRAY_BUFFER, 0);
glBindVertexArray(0);

//Texture tex("textures/box.jpg", 2550, 180,0, false);

while(!glfwWindowShouldClose(window))
{
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    shaderProg.useProgram();

    //glActiveTexture(GL_TEXTURE0);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);


    //game.processInput();
    //game.update();
    //game.render();


    glfwSwapBuffers(window);
    glfwPollEvents();
}

glDeleteVertexArrays(1, &VAO);
glDeleteBuffers(1, &VBO);
glDeleteBuffers(1, &EBO);
shaderProg.~ShaderProgram();


glfwTerminate();


return 0;
}
