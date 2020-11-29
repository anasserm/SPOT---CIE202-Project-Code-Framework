#pragma once
#include "Action.h"

class ActionUndo
	:
	public Action
{
public:
	ActionUndo(Registrar*);
	bool virtual Execute();
	virtual ~ActionUndo();
};

