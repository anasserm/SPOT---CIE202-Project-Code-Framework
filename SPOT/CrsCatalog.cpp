#include "CrsCatalog.h"

vector<Course*> CrsCatalog::getCrsCatalog() const
{
    return Courses;
}

void CrsCatalog::addCrs(Course* C)
{
       Courses.push_back(C);
}


