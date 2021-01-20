#include "StudyPlan.h"

int StudyPlan::numOfCourses = 0;

StudyPlan::StudyPlan()
{
	//By default, the study plan starts with 5 years
	//More year can be added
	for (int i = 0; i < 5; i++)
		plan.push_back(new AcademicYear);
}

//adds a course to the study plan in certain year, semester
//year idetifies year number to add course to 1=first, 2 = 2nd,....
bool StudyPlan::AddCourse(Course* pC, int year, SEMESTER sem)
{
	//TODO: add all requried checks to add the course 

	plan[year - 1]->AddCourse(pC, sem);
	TotalCredits += pC->getCredits();
	numOfCourses++;
	return true;
}

void StudyPlan::DrawMe(GUI* pGUI) const
{
	//Plan draws all year inside it.
	for (int i = 0; i < plan.size(); i++)
		plan[i]->DrawMe(pGUI);
}

vector<AcademicYear*> StudyPlan::getPlan() //const
{
	return plan;
}

int StudyPlan::getYearCourses(int year, SEMESTER sem) //const
{
	return  plan[year - 1]->getYearCourses(sem).size();
}

StudyPlan::~StudyPlan()
{
}

void StudyPlan::setNotes(string s)
{
	this->PlanNotes = s;
}

int StudyPlan::getCredits() const
{
	return this->TotalCredits;
}

string StudyPlan::getNotes()
{
	return PlanNotes;
}

int StudyPlan::getNumOfCourses() const
{
	return this->numOfCourses;
}