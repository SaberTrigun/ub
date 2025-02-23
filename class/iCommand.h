#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__


#include "gameActor.h"


namespace UB
{


class ICommand
{
public:
	virtual ~ICommand(){};

	virtual void execute(GameActor& actor, float deltaTime) = 0;
};
}


#endif
