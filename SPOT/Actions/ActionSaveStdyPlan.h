#pragma once
#include "Action.h"

class ActionSaveStdyPlan
	:
	public Action
{
public:
	ActionSaveStdyPlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionSaveStdyPlan();
};
