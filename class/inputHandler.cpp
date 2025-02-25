#include "inputHandler.h"
#include "buttons.h"


namespace UB
{


InputHandler::InputHandler()// : buttonW(new ButtonW)
{
    iButtonW = new ButtonW;
    iButtonA = new ButtonA;
    iButtonS = new ButtonS;
    iButtonD = new ButtonD;
}


ICommand* InputHandler::handleInput(GLFWwindow* window)
{
	// if press any button then we do something
    ICommand* pressedButton = nullptr;

    if (glfwGetKey(window, GLFW_KEY_W)){
        pressedButton = iButtonW;
    }
    else if (glfwGetKey(window, GLFW_KEY_S)) {
        pressedButton = iButtonS;
    }
    else if (glfwGetKey(window, GLFW_KEY_A)) {
        pressedButton = iButtonA;
    }
    else if (glfwGetKey(window, GLFW_KEY_D)) {
        pressedButton = iButtonD;
    }

    return pressedButton;
}





}
