#include "ActionExit.h"
#include "../Registrar.h"


ActionExit::ActionExit(Registrar* p) :Action(p)
{

}


bool ActionExit::Execute()
{
	GUI* pGUI = pReg->getGUI();
	pGUI->close();
	return false;
	
}


ActionExit::~ActionExit()
{
}
