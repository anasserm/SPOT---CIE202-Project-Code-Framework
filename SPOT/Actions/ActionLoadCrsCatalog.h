#pragma once
#include "Action.h"


class ActionLoadCrsCatalog
	:
	public Action
{
public:
	ActionLoadCrsCatalog(Registrar*);
	bool virtual Execute();
	virtual ~ActionLoadCrsCatalog();
};
