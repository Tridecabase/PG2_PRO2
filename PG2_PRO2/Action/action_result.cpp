#include "action_result.h"

ActionResult::ActionResult(bool s) : succeeded(s) {}

ActionResult::ActionResult(Action* a) {
    succeeded = false;
    alternate = a;
}
