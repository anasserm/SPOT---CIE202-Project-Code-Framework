#include "ActionDelCourse.h"
#include <iostream>
using namespace std;
ActionDelCourse::ActionDelCourse(Registrar*p) :Action(p)
{
}


bool ActionDelCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("Enter Course Code to Delete: ");
	string code = pGUI->GetSrting();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();
	int idx = 0, year_del = 0, sem_del = 0;
	bool found = false;

	for ( int year = 0; year < years.size(); year++) // loop over years
	{
		sem_del = 0;
		for (int sem = FALL; sem < SEM_CNT; sem++) // loop over semesters
		{
			list<Course*> listCourses = years[year]->getYearCourses((SEMESTER)sem);
			idx = 0;
			for (list<Course*>::iterator it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				if (code == (*it)->getCode())
				{
					years[year_del]->delCourse(idx, (SEMESTER)sem_del);
					found = true;
					break;
				}
				idx++;
			}

			if (found)
				break;

			sem_del++;
		}
		if (found)
			break;

		year_del++;
	}

	if (!found)
	{
		pGUI->PrintMsg("ERROR. Couldn't find course code");
	}

	return true;
}


ActionDelCourse::~ActionDelCourse()
{
}
