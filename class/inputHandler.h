#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__


#include "iCommand.h"
#include "../include/GLFW/glfw3.h"


namespace UB
{


class InputHandler
{
public:
    InputHandler();
	ICommand* handleInput(GLFWwindow* window);

private:
    ICommand* iButtonW;
    ICommand* iButtonA;
    ICommand* iButtonS;
    ICommand* iButtonD;

};
}







#endif
