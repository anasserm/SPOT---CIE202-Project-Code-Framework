#include "ActionAddNote.h"

#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
#include <string>

ActionAddNote::ActionAddNote(Registrar* p) :Action(p)
{
}

bool ActionAddNote::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* pStdy = pReg->getStudyPlay();



	pGUI->PrintMsg("Enter Your Notes: ");
	pStdy->setNotes(pGUI->GetSrting());
	pGUI->PrintMsg("Done. ");

	return true;

}

ActionAddNote::~ActionAddNote()
{
}
