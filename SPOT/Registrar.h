#pragma once
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"
#include "CrsCatalog.h"


//The maestro class for the application
class Registrar
{
	
	GUI *pGUI;	//pointer to GUI 
	Rules RegRules;	//Registration rules
	StudyPlan *pSPlan;
	CrsCatalog* Pcata;
public:
	static string user_type;
	Registrar();
	GUI* getGUI() const;
	Action* CreateRequiredAction();
	bool ExecuteAction(Action*);
	void UpdateInterface();
	StudyPlan* getStudyPlay() const;
	void getUserType()const;
	CrsCatalog* getCrsCatalog()const;
	void Run();

	~Registrar();
};

