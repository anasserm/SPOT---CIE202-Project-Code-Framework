#pragma once
#include "Courses/Course.h"
#include <vector>


class CrsCatalog 
{
public:

	vector<Course*> Courses;

	vector<Course*> getCrsCatalog()const;

	void addCrs(Course*);
};

