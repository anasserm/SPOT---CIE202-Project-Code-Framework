#pragma once
#include "Action.h"


class ActionChngCourseCode
	: public Action
{
public:
	ActionChngCourseCode(Registrar*);
	bool virtual Execute();
	virtual ~ActionChngCourseCode();

};


