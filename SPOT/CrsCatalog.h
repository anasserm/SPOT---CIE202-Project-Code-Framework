#pragma once
#include "Courses/Course.h"
#include <vector>


class CrsCatalog
{

	vector<Course*> Courses;

public:

	vector<Course*> getCrsCatalog()const;

	void addCrs(Course*);

	

		


};

