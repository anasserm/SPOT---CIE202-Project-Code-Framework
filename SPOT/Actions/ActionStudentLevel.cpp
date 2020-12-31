#include "ActionStudentLevel.h"
#include "..\Registrar.h"


ActionStudentLevel::ActionStudentLevel(Registrar* r): Action(r)
{
}

bool ActionStudentLevel::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	int crd = sp->getCredits();

	if (crd>=0 && crd<25)
		pGUI->PrintMsg("you are a Freshman student");
	else if (crd >= 25 && crd < 56)
		pGUI->PrintMsg("you are a Sophomore  student");
	else if (crd >= 56 && crd <90)
		pGUI->PrintMsg("you are a Junior  student");
	else if (crd >= 90)
		pGUI->PrintMsg("you are a Senior  student");


	return true;
}

ActionStudentLevel::~ActionStudentLevel()
{
}
