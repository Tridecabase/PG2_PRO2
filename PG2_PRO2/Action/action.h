#ifndef ACTION_H
#define ACTION_H

#include "Core/xion.h"

class Actor;
class ActionResult;
class Action
{
public:
	virtual ActionResult perform(Actor* actor) = 0;
};

#endif // !ACTION_H