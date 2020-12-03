#include "Course.h"
#include "../GUI/GUI.h"

Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	credits = crd;
}

Course::~Course()
{
}

Course_Code Course::getCode() const
{
	return code;
}

string Course::getTitle() const
{
	return Title;
}

//return course credits
int Course::getCredits() const
{
	return credits;
}

list<string> Course::getPreReq() 
{
	return  PreReq;
}

list<string> Course::getCoReq() 
{
	return CoReq;
}

void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
}