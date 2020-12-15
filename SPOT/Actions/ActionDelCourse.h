#pragma once
#include "Action.h"
#include "../Registrar.h"

class ActionDelCourse :
	public Action
{
public:
	ActionDelCourse(Registrar*);
	bool virtual Execute();
	virtual ~ActionDelCourse();

};

