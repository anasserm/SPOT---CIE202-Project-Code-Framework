#include "CrsOffering.h"

string CrsOffering::getYear()
{
    return string(AcademicYear);
}

string CrsOffering::getSem()
{
    return string(Semester);
}

vector<string> CrsOffering::getCourses()
{
    return vector<string>(Crss);
}
