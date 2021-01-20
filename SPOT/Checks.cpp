#include "Checks.h"
#include "Registrar.h"
#include "StudyPlan/StudyPlan.h"
#include <algorithm>

int Checks::numOfCourses = 0;
using namespace std;

vector<AcademicYear*> Checks::getPlan() const
{
	return plan;
}

bool Checks::CheckCourse(Course* pC, int year, SEMESTER sem)
{
	//TODO: add all requried checks to add the course 

	plan[year - 1]->AddCourse(pC, sem);
	TotalCredits += pC->getCredits();
	numOfCourses++;
	return true;
}

bool Checks::checkPre(Course* pCourse, SEMESTER sem, int year, vector <pair<Course_Code, double>> Myvector)
{
	//Myvector contains the codes of all registered courses and the years and semesters they are registered in

	//TODO:
	vector<string> pre_reqs = pCourse->getPreReq(); //in this step I define a list (pre_reqs) equivalent to PreReq which is list <course_code> 

	double course_year_code = year;

	//this step is used to be able to compare between the course under check and the courses in Myvector
	if (sem == FALL) course_year_code += 0.1;
	else if (sem == SPRING) course_year_code += 0.2;
	else course_year_code += 0.3;  //for example if a course is in the summer of year 2, its decimal will be 2.3
	int j = 0;
	for (auto i = pre_reqs.begin(); i != pre_reqs.end(); i++, j++)
	{

		string PreReq = pre_reqs[j];

		for (int i = 0; i < Myvector.size() - 1; i++)
		{
			//case 1: the prerequisite of course_under_check  is in the plan but it is in a semester after which is an issue
			if (Myvector[i].first == PreReq && course_year_code < Myvector[i].second) return false;

			//case 2: the prerequisite of course_under_check  is in the plan and it is in a semester before hence there is no problem, break and return true
			if (Myvector[i].first == PreReq && course_year_code > Myvector[i].second) break;

			//case 3: the prerequisite of course_under_check  is not in the plan at all which is also an issue
			if (i == Myvector.size() - 1) return false;
		}

	}
	return true;
}

bool Checks::checkCo(Course* pCourse, SEMESTER sem, int year)
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

Checks::Checks(Registrar* p)
{
	pReg = p;
}

bool Checks::checkcredits()
{
	bool check_credits = true;
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();

	for (int yr = 0; yr < years.size(); yr++)
	{

		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			int credit = 0;
			list<Course*> listCourses = years[yr]->getYearCourses((SEMESTER)sem);
			list<Course*>::iterator it;

			for (it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				credit += (*it)->getCredits();
			}

			if (credit > 18 || credit < 12)
			{
				check_credits = false;
			}
		}
	}
	return check_credits;
}

//int checkProgReq() 
//{
//
//}


//int FullCheck(bool checkCo(Course* pCourse, SEMESTER sem, int year), bool check_Pre(Course* pCourse, SEMESTER sem, int year, vector <pair<Course_Code, double>> Myvector), bool checkcredits(), int check_ProgReq)
//{
//	bool check_credits = checkcredits();
//	bool check_Co = checkCo(pCourse, sem, year);
//
//	if (check_Co && check_Pre && check_credits == 0 && check_ProgReq == 0) return 0;
//	else if (!check_Co || !check_Pre && check_credits == 0 && check_ProgReq == 0) return 1;
//	else if (!check_Co || !check_Pre && check_credits == 0 && check_ProgReq == 0) return 2;
//	else if (!check_Co || !check_Pre && check_credits == 0 && check_ProgReq == 1) return 3;
//	else if (check_Co && check_Pre && check_credits == 1 && check_ProgReq == 0) return 4;
//}



