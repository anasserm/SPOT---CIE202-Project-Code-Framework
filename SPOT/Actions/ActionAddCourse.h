#pragma once
#include "Action.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <utility>
#include <list>
#include <vector>
//Class responsible for adding course action
class ActionAddCourse:
	public Action
{
public:
	ActionAddCourse(Registrar*);
	bool virtual Execute();
	int getnCourses(int year, SEMESTER sem) const;
	int semToX(int count, SEMESTER sem) const;
	int yearToY(int year, int count) const;
	int searchCourse(Course_Code code);
	virtual ~ActionAddCourse();
};

