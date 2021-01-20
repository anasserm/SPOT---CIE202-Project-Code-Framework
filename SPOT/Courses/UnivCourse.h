#pragma once
#include "Course.h"

//Univesrity course class
class UnivCourse : public Course
{
	vector<string> UniComplsoryCrs;
	vector<string> UniElectiveCrs;
public:


	vector<string> getUniComplsoryCrs()const;
	vector<string> getUniElectiveCrs()const;
	UnivCourse();
	virtual ~UnivCourse();
};

