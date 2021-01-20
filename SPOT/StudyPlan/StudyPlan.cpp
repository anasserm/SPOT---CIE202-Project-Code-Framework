#include "StudyPlan.h"
#include <iostream>
#include <algorithm>
int StudyPlan::numOfCourses = 0;
using namespace std;


using namespace std;

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

vector<AcademicYear*> StudyPlan::getPlan() 
{
	return plan;
}

int StudyPlan::getYearCourses(int year, SEMESTER sem) const
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

int StudyPlan::getUniCredit() const
{
	return TotalUnivCredits;
}

int StudyPlan::getTrackCredit() const
{
	return TotalTrackCredits;
}

int StudyPlan::getMajorCredit() const
{
	return TotalMajorCredits;
}

int StudyPlan::getMinorCredit() const
{
	return TotalMinorCredits;
}

int StudyPlan::getConcentrationCredit() const
{
	return TotalConcentrationCredits;
}

bool StudyPlan::checkPre(Course* pCourse, SEMESTER sem, int year, vector <pair<Course_Code, double>> Myvector)
{
	//Myvector contains the codes of the prerequisite courses and the year and semester they are registered in

	//TODO:
	vector<string> pre_reqs = pCourse->getPreReq(); //in this step I define a list (pre_reqs) equivalent to PreReq which is list <course_code> 

	double course_year_code = year;

	//this step is used to be able to compare between the course under check and the courses in Myvector
	if (sem == FALL) course_year_code += 0.1;
	else if (sem == SPRING) course_year_code += 0.2;
	else course_year_code += 0.3;  //for example if a course is in the summer of year 2, its decimal will be 2.3
	int j = 0;
	for (auto i = pre_reqs.begin(); i != pre_reqs.end(); i++,j++)
	{

		string course_under_check = pre_reqs[j];

		for (int i = 0; i < Myvector.size(); i++)
		{
			//case 1: the prerequisite of course_under_check  is in the plan but it is in a semester after which is an issue
			if (Myvector[i].first == course_under_check && course_year_code < Myvector[i].second) return false;

			//case 2: the prerequisite of course_under_check  is in the plan and it is in a semester before hence there is no problem, break and return true
			if (Myvector[i].first == course_under_check && course_year_code > Myvector[i].second) break;

			//case 3: the prerequisite of course_under_check  is not in the plan at all which is also an issue
			if (i == Myvector.size() - 1) return false;
		}

	}
	return true;
}


bool StudyPlan::checkCo(Course* pCourse, SEMESTER sem, int year)
{
	list<string> yearCourses;
	for (int j = 0; j < getPlan()[year]->getYearCourses(sem).size(); j++)
	{
		//std::list<Course*>::const_iterator it = getPlan()[year]->getYearCourses(sem).begin();
		//std::advance(it, j);
		auto it = next(getPlan()[year]->getYearCourses(sem).begin(), j);
		Course* temp = *it;
		yearCourses.push_back(temp->getCode());
	}

	bool is_subset = includes(pCourse->getCoReq().begin(), pCourse->getCoReq().end(), yearCourses.begin(), yearCourses.end());
	return is_subset;
}

