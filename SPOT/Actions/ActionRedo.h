#pragma once
#include "Action.h"


class ActionRedo
	:
	public Action
{
public:
	ActionRedo(Registrar*);
	bool virtual Execute();
	virtual ~ActionRedo();
};

