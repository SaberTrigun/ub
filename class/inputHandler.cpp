#include "inputHandler.h"


namespace UB
{


InputHandler::InputHandler() : buttonW(&ButtonW())
{
    //buttonW = new ButtonW;
}


ICommand* InputHandler::handleInput(GLFWwindow* window)
{
	// if press any button then we do something
    ICommand* pressedButton = nullptr;

    if (glfwGetKey(window, GLFW_KEY_W)){
        pressedButton = buttonW;
    }
    else if (glfwGetKey(window, GLFW_KEY_S)) {
        pressedButton = buttonS;
    }
    else if (glfwGetKey(window, GLFW_KEY_A)) {
        pressedButton = buttonA;
    }
    else if (glfwGetKey(window, GLFW_KEY_D)) {
        pressedButton = buttonD;
    }

    return pressedButton;
}





}
