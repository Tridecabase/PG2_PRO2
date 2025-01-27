#ifndef ACTION_MOVE_H
#define ACTION_MOVE_H

#include "action.h"
#include "Characters/actor.h"
#include "action_result.h"

class ActionMove : public Action
{
public:
	ActionMove(float distance, int direction);

private:
	float dis;
	int dir;
	int factor_ver;
	int factor_hor;
};


#endif // !ACTION_MOVE_H