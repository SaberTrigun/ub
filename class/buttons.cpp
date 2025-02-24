#include "buttons.h"


namespace UB
{


void ButtonW::execute(GameActor& actor, float deltaTime)
{
	actor.moveForward(deltaTime);
}


void ButtonA::execute(GameActor& actor, float deltaTime)
{
	actor.moveForward(deltaTime);
}


void ButtonS::execute(GameActor& actor, float deltaTime)
{
	actor.moveForward(deltaTime);
}


void ButtonD::execute(GameActor& actor, float deltaTime)
{
	actor.moveForward(deltaTime);
}


}