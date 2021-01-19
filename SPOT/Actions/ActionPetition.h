#pragma once
#include "Action.h"

class ActionPetition :public Action
{
public:
	ActionPetition(Registrar* r);
	bool virtual Execute();
	virtual ~ActionPetition();
};
