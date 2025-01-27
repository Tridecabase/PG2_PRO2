#ifndef ACTION_RESULT_H
#define ACTION_RESULT_H

class Action;
class ActionResult {
public:
		Action* alternate = nullptr;
		bool succeeded = false;

		ActionResult(bool s);
		ActionResult(Action* a);
};

#endif // !ACTION_RESULT_H
