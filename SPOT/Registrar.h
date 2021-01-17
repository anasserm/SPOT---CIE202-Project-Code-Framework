#pragma once
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"
#include "CrsCatalog.h"
#include "ProgReq.h" 
#include "CrsOffering.h"


//The maestro class for the application
class Registrar
{
	
	GUI *pGUI;	//pointer to GUI 
	StudyPlan *pSPlan;
	CrsCatalog* Pcata;
	ProgReq* pr;
	CrsOffering* pCO;

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
	ProgReq* getProgReq()const;
	CrsOffering* getCrsOffering()const;
	void Run();

	~Registrar();
};

