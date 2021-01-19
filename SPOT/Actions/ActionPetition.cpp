#include "ActionPetition.h"
#include "..\Registrar.h"

ActionPetition::ActionPetition(Registrar* r): Action (r)
{
}

bool ActionPetition::Execute()
{
	GUI* pGUI = pReg->getGUI();
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

			if (credit>18)
			{
				pGUI->PrintMsg("You need an overload petition ");
				break;
			}
			else if (credit <12)
			{
				pGUI->PrintMsg("You need an underload petition ");
				break;
			}


		}
	}

	return true;
}

ActionPetition::~ActionPetition()
{
}
