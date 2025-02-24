#ifndef __BUTTONS_H__
#define __BUTTONS_H__


#include "iCommand.h"


namespace UB
{


class ButtonW : public ICommand
{
public:
	void execute(GameActor& actor, float deltaTime) override;

private:
};


class ButtonA : public ICommand
{
public:
	void execute(GameActor& actor, float deltaTime) override;

private:
};


class ButtonS : public ICommand
{
public:
	void execute(GameActor& actor, float deltaTime) override;

private:
};


class ButtonD : public ICommand
{
public:
	void execute(GameActor& actor, float deltaTime) override;

private:
};


}



#endif