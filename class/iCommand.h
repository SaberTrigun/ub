#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__


#include "gameActor.h"


namespase UB
{


class ICommand
{
public:
	virtual ~ICommand(){};
	
	virtual void execute(GameActor& actor) = 0;
};
}


#endif