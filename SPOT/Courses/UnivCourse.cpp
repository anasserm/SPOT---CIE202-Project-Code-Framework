#include "UnivCourse.h"



vector<string> UnivCourse::getUniComplsoryCrs() const
{
    return vector<string>(UniComplsoryCrs);
}

vector<string> UnivCourse::getUniElectiveCrs() const
{
    return vector<string>(UniElectiveCrs);
}

UnivCourse::UnivCourse()
{
}


UnivCourse::~UnivCourse()
{
}
