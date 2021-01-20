#include "MajorCourse.h"



MajorCourse::MajorCourse()
{
}

vector<string> MajorCourse::getMajorCommonComplsoryCrs() const
{
	return vector<string>(MajorCommonComplsoryCrs);
}

vector<string> MajorCourse::getMajorCommonElectiveCrs() const
{
	return vector<string>(MajorCommonElectiveCrs);
}


MajorCourse::~MajorCourse()
{
}
