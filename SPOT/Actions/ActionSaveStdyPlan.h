#pragma once
#include "Action.h"
#include <iostream>
#include <fstream>
#include "../StudyPlan/StudyPlan.h"
#include "../Registrar.h"
using namespace std;

class ActionSaveStdyPlan
	:
	public Action
{
public:
	ActionSaveStdyPlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionSaveStdyPlan();
};
