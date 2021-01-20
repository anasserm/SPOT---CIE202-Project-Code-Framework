
#pragma once
#include "Action.h"
#include "../Registrar.h"

class ActionDisplay :
	public Action
{
public:
	ActionDisplay(Registrar*r);
	bool virtual Execute();
	virtual ~ActionDisplay();

};

