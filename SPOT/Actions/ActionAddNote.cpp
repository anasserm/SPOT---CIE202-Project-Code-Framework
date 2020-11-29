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
	pStdy->getNotes() = pGUI->GetSrting();


	return true;

}

ActionAddNote::~ActionAddNote()
{
}
