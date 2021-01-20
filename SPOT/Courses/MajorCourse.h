#pragma once
#include "Course.h"
class MajorCourse :
	public Course
{
	vector<string> MajorCommonComplsoryCrs;
	vector<string> MajorCommonElectiveCrs;
public:
	MajorCourse();
	vector<string> getMajorCommonComplsoryCrs()const;
	vector<string> getMajorCommonElectiveCrs()const;
	virtual ~MajorCourse();
};

