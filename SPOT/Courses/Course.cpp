#include "Course.h"
#include "../GUI/GUI.h"
#include "../Registrar.h"
 

Course::Course()
{

}

Course::Course(Course_Code r_code, string r_title, int crd)//:code(r_code),Title(r_title)
{
	code = r_code;
	Title = r_title;
	credits = crd;
	status = "Done";
	

}

Course::~Course()
{
}

string Course::getType() const
{
	return string(type);
}

void Course::setType(string t)
{
	type = t;
}

void Course::setStatus(string s)
{
	this->status = s;
}

string Course::getStatus() const
{
	return string(status);
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

vector<string> Course::getPreReq() 
{
	return  PreReq;
}

vector<string> Course::getCoReq() 
{
	return CoReq;
}

void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
}

void Course::setCode(Course_Code crs_code)
{
	code = crs_code;
}

string Course::getGrade() const
{
	return this->grade;
}

void Course::setGrade(string grad)
{
	this->grade = grad;
}

