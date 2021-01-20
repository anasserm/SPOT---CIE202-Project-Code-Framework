#include "ActionDisplay.h"


ActionDisplay::ActionDisplay(Registrar* r): Action (r)
{
}

bool ActionDisplay::Execute()
{
	GUI* pGUI = pReg->getGUI();
	CrsCatalog* cc = pReg->getCrsCatalog();
	vector<Course*> Courses = cc->getCrsCatalog();

	pGUI->PrintMsg("Enter the name of the course: ");
	string code = pGUI->GetSrting();
	string Code, title; int crd;
	bool flag=false;

	for (int i=0; i<Courses.size(); i++)
	{
		if (code == Courses[i]->getCode())
		{
			Code = Courses[i]->getCode();
			title = Courses[i]->getTitle();
			crd = Courses[i]->getCredits();
			flag = true;
			break;
		}
	}

	if (flag)
		pGUI->PrintMsg("Course code is: " + Code + " and title is: " + title + " and credits are: " + to_string(crd));	
	else
		pGUI->PrintMsg("No such course exist. ");

	Sleep(3000);
	return true;
}

ActionDisplay::~ActionDisplay()
{
}
