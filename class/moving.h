#ifndef __MOVING_H__
#define __MOVING_H__


#include "iCommand.h"


namespace UB
{


class Moving : public ICommand
{
public:
	void execute(GameActor& actor) override;

};
}



#endif
