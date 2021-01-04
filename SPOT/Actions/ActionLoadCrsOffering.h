#pragma once
#include "Action.h"

class ActionLoadCrsOffering : public Action
{
public:
	ActionLoadCrsOffering(Registrar*);
	bool virtual Execute();
	virtual ~ActionLoadCrsOffering();

};

