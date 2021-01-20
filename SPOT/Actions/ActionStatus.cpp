#include "ActionStatus.h"
#include "..\Registrar.h"


ActionStatus::ActionStatus(Registrar* r) : Action(r)
{
}

bool ActionStatus::Execute()
{

	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();

	for (int yr = 0; yr < years.size(); yr++)
	{

		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			list<Course*> listCourses = years[yr]->getYearCourses((SEMESTER)sem);
			list<Course*>::iterator it;

			for (it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				string msg = "Enter status for this course " + (*it)->getCode();
				pGUI->PrintMsg(msg);
				(*it)->setStatus(pGUI->GetSrting());


			}
		}
	}


	return true;
}

ActionStatus::~ActionStatus()
{
}

