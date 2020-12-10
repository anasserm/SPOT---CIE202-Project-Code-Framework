#include "Registrar.h"
#include "Actions/ActionAddCourse.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionDelCourse.h"
#include "Actions/ActionChngCourseCode.h"
#include "Actions/ActionAddNote.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionLoadCrsCatalog.h"
#include "Actions/ActionLoadPrgReq.h"
#include "Actions/ActionLoadStdyPlan.h"
#include "Actions/ActionSaveStdyPlan.h"
#include "Actions/ActionRedo.h"
#include "Actions/ActionUndo.h"
#include "Actions/ActionSaveStdyPlan.h"

#include <iostream>

string Registrar::user_type = " ";

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

//returns the study plan
StudyPlan* Registrar::getStudyPlay() const
{
	return pSPlan;
}

Action* Registrar::CreateRequiredAction() 
{	
	ActionData actData = pGUI->GetUserAction("Pick and action...");
	cout << actData.actType << endl;
	Action* RequiredAction = nullptr;

	switch (actData.actType)
	{
	case ADD_CRS:	//add_course action
		RequiredAction = new ActionAddCourse(this);
		break;

	//TODO: Add case for each action
	
	case EXIT:
		cout << "Exit Button Presses" << endl;
		RequiredAction = new ActionExit(this);
		break;

	case DEL_CRS:
		RequiredAction = new ActionDelCourse(this);
		break;

	case CHNGE_CRS_CODE:
		RequiredAction = new ActionChngCourseCode(this);
		break;

	case ADD_NOTES:
		RequiredAction = new ActionAddNote(this);
		break;

	case LOAD_CRS_CATALOG:
		RequiredAction = new ActionLoadCrsCatalog(this);
		break;

	case LOAD_PRG_REQ:
		RequiredAction = new ActionLoadPrgReq(this);
		break;

	case SAVE_plan: // study plan
		RequiredAction = new ActionSaveStdyPlan(this);
		break;

	case LOAD_plan:   //study plan
		RequiredAction = new ActionLoadStdyPlan(this);
		break;

	case UNDO:
		RequiredAction = new ActionUndo(this);
		break;


	case REDO:
		RequiredAction = new ActionRedo(this);
		break;
		
	}
	return RequiredAction;
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::getUserType()const
{
	pGUI->PrintMsg("Are you Eng or Sci.? Enter: ");
	string user_t = pGUI->GetSrting();

	while ( user_t.compare("Sci") != 0 && user_t.compare("Eng") != 0)
	{
		pGUI->PrintMsg("Error! Enter Eng or Sci: ");
		user_t = pGUI->GetSrting();
	}
	Registrar::user_type = user_t;
}

CrsCatalog* Registrar::getCrsCatalog() const
{
	return this->Pcata;
}

void Registrar::Run()
{

	ActionLoadCrsCatalog* p = new ActionLoadCrsCatalog(this);
	bool ahmed = p->Execute();

	//vector<Course*> v1 = Pcata->getCrsCatalog();

	/*for (unsigned int i = 0; i < v1.size(); i++) {
		cout << v1[i]->getCode() << " ";
		cout << v1[i]->getCredits() << " ";
		cout << v1[i]->getTitle() << " ";
		
	}*/
	getUserType();
	while (true)
	{
		//update interface here as CMU Lib doesn't refresh itself
		//when window is minimized then restored
		UpdateInterface();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
				UpdateInterface();
			else
				break;
		}
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
}

Registrar::~Registrar()
{
	delete pGUI;
}
