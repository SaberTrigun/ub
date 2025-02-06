#include <iostream>
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include "class/shader.h"
#include "class/texture.h"
#include "include/glm/glm/matrix.hpp"
#include "include/glm/glm/gtc/matrix_transform.hpp"
//#include "class/camera.h"

using namespace UB;

int gHeightScr = 1400;
int gWidthScr  = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{ glViewport(0, 0, width, height); }


void transScale(ShaderProgram& shaderProg){
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    shaderProg.setMat4("transform", trans);

}

void transRotate(ShaderProgram& shaderProg){
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
    shaderProg.setMat4("transform", trans);
}


int main(){
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

GLFWwindow* window = glfwCreateWindow(gHeightScr, gWidthScr, "OpenGL Window", NULL, NULL);
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


Shader vShader(std::string("shaders/seven/vxShader.src"), GL_VERTEX_SHADER);
Shader fShader(std::string("shaders/seven/fgShader.src"), GL_FRAGMENT_SHADER);
ShaderProgram shaderProg(vShader, fShader);
vShader.deleteShader();
fShader.deleteShader();


float vertices[] = {
    // pos            // color          // tex
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
    0.5f,-0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
   -0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
   -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f
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

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
glEnableVertexAttribArray(1);

glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
glEnableVertexAttribArray(2);

glBindBuffer(GL_ARRAY_BUFFER, 0);
glBindVertexArray(0);


unsigned int texBox;
glGenTextures(1, &texBox);
glBindTexture(GL_TEXTURE_2D, texBox);

Texture box("textures/box.jpg", 2550, 180,0, false);

unsigned int texSmile;
glGenTextures(1, &texSmile);
glBindTexture(GL_TEXTURE_2D, texSmile);

Texture smile("textures/smile.png", 2550, 180,0, true);

shaderProg.useProgram();
shaderProg.setInt("texBox", 0);
shaderProg.setInt("texSmile", 1);


while(!glfwWindowShouldClose(window))
{
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 1400.0f / 800.0f, 0.1f, 100.0f);

    shaderProg.setMat4("model", model);
    shaderProg.setMat4("view", view);
    shaderProg.setMat4("projection", projection);


    shaderProg.useProgram();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texBox);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texSmile);

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
