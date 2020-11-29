#include "ActionRedo.h"

ActionRedo::ActionRedo(Registrar*p) :Action(p)
{
}

bool ActionRedo::Execute()
{
	return false;
}

ActionRedo::~ActionRedo()
{
}
