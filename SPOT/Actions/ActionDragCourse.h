#pragma once
#include "Action.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <utility>
#include <list>
#include <vector>
#include "../CrsCatalog.h"
#include "../Courses/Course.h"
#include <string>
#include "../DEFs.h"

struct isFound {
	bool found;
	SEMESTER sem;
	int year;
	int index;
};

class ActionDragCourse :
	public Action
{
public:
	ActionDragCourse(Registrar*);
	bool virtual Execute();
	int getnCourses(int year, SEMESTER sem) const;
	int semToX(int count, SEMESTER sem) const;
	int yearToY(int year, int count) const;
	isFound searchCourse(Course_Code code);
	virtual ~ActionDragCourse();
};