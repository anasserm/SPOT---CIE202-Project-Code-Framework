#include "ActionPetition.h"
#include "..\Registrar.h"
#include <iostream>
ActionPetition::ActionPetition(Registrar* r): Action (r)
{
}

bool ActionPetition::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();

	pGUI->PrintMsg("Enter the year you want to check: ");
	int yr = stoi(pGUI->GetSrting());
	yr--;

	pGUI->PrintMsg("Enter the semester you want to check: 1=Fall, 2=Spring, 3=Summer ");
	int sem = stoi(pGUI->GetSrting());
	sem--;

	int credit = 0;
	list<Course*> listCourses = years[yr]->getYearCourses((SEMESTER)sem);
	for (list<Course*>::iterator it = listCourses.begin(); it != listCourses.end(); ++it)
	{
		credit += (*it)->getCredits();
		
	}
	
	if (credit>18)
	{
		pGUI->PrintMsg("You need an overload petition ");
		Sleep(2000);
				
	}
	else if (credit <12)
	{
		pGUI->PrintMsg("You need an underload petition ");
		Sleep(2000);
				
	}
	else
	{
		pGUI->PrintMsg("You do not need a petition ");
		Sleep(2000);
	}
	

	return true;
}

ActionPetition::~ActionPetition()
{
}
