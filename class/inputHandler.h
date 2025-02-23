#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__


#include "iCommand.h"


namespace UB
{


class InputHandler
{
public:
	ICommand* handleInput();

private:
    ICommand* move;

};
}







#endif
