#ifndef __SIMPLEBOX_H__
#define __SIMPLEBOX_H__


#include "gameActor.h"


namespace UB
{


class SimpleBox : public GameActor
{
public:
	void moveForward(float deltaTime) override;

private:

};
}





#endif
