#ifndef __MOVING_H__
#define __MOVING_H__


#include "iCommand.h"


namespace UB
{


class Moving : public iCommand
{
public:
	virtual void execute(GameActor& actor);

};
}



#endif