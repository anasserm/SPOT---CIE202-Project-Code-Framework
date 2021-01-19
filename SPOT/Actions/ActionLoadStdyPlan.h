#pragma once
#include "Action.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map> 
#include "../DEFs.h"
class ActionLoadStdyPlan
	:
	public Action
{
public:
	ActionLoadStdyPlan(Registrar*);
	bool virtual Execute();
	int getnCourses(int year, SEMESTER sem) const;
	int semToX(int count, SEMESTER sem) const;
	int yearToY(int year, int count) const;
	virtual ~ActionLoadStdyPlan();
};

