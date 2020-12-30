#pragma once
#include "Action.h"
class ActionGPA :public Action
{
public:
	ActionGPA(Registrar* r);
	bool virtual Execute();
	virtual ~ActionGPA();
};

