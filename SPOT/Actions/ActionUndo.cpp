#include "ActionUndo.h"

ActionUndo::ActionUndo(Registrar*p) :Action(p)
{
}

bool ActionUndo::Execute()
{
	return false;
}

ActionUndo::~ActionUndo()
{
}
