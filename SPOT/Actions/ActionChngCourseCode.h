#pragma once
#include "Action.h"
#include "../Registrar.h"

class ActionChngCourseCode
	: public Action
{
public:
	ActionChngCourseCode(Registrar*);
	bool virtual Execute();
	virtual ~ActionChngCourseCode();

};


