#include "ActionChngCourseCode.h"

ActionChngCourseCode::ActionChngCourseCode(Registrar* p) :Action(p)
{
}

bool ActionChngCourseCode::Execute()
{
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("Enter Course Code to Change: ");
	string code = pGUI->GetSrting();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();
	int idx = 0, year_del = 0, sem_del = 0;
	bool found = false;
	for (int year = 0; year < years.size(); year++) // loop over years
	{
		sem_del = 0;
		for (int sem = FALL; sem < SEM_CNT; sem++) // loop over semesters
		{
			list<Course*> listCourses = years[year]->getYearCourses((SEMESTER)sem);
			idx = 0;
			for (list<Course*>::iterator it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				if ((*it)->getCode() == code)
				{

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

	if (found)
	{
		pGUI->PrintMsg("Enter NEW Course Code to Change: ");
		string new_code = pGUI->GetSrting();
		StudyPlan* sp = pReg->getStudyPlay();
		vector<AcademicYear*> years = sp->getPlan();
		list<Course*> listCourses = years[year_del]->getYearCourses((SEMESTER)sem_del);


		list<Course*>::iterator it2 = listCourses.begin();
		advance(it2, idx);

		
		(*it2)->setCode(new_code);

	}
	else {
		pGUI->PrintMsg("ERROR. Couldn't find course code");
	}
	return true;
}

ActionChngCourseCode::~ActionChngCourseCode()
{
}
