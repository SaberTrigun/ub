#include "buttons.h"


namespace UB
{


void ButtonW::execute(GameActor& actor, float deltaTime)
{
	actor.moveUp(deltaTime);
}


}