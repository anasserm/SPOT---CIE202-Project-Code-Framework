#pragma once
#include "Action.h"
#include <utility>
#include <list>
#include <vector>
//Class responsible for adding course action
class ActionAddCourse :
	public Action
{
public:
	ActionAddCourse(Registrar*);
	bool virtual Execute();
	virtual ~ActionAddCourse();
};

