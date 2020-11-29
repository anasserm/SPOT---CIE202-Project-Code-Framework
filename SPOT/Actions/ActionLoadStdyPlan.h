#pragma once
#include "Action.h"

class ActionLoadStdyPlan
	:
	public Action
{
public:
	ActionLoadStdyPlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionLoadStdyPlan();
};

