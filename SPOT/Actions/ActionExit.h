#pragma once
#include "Action.h"

class ActionExit
	:
	public Action
{
public:
	ActionExit(Registrar*);
	virtual bool Execute();
	virtual ~ActionExit();
};


