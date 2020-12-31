#pragma once
#include "Action.h"

class ActionStudentLevel :public Action
{
public:
	ActionStudentLevel(Registrar* r);
	bool virtual Execute();
	virtual ~ActionStudentLevel();
};

