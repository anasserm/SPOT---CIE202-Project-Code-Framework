#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
#include <string>
ActionAddCourse::ActionAddCourse(Registrar* p) :Action(p)
{
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();
	pGUI->PrintMsg("Add Course to plan: Enter credits (between 2 and 6):");

	int crd = stoi(pGUI->GetSrting());
	//TODO: add input validation

	while (crd < 2 || crd > 6)
	{
		pGUI->PrintMsg("Error: Enter credits (between 2 and 6):");
		crd = stoi(pGUI->GetSrting());
		cout << crd << endl;
	}

	ActionData actData = pGUI->GetUserAction("Select a year to add coures to: ");
	//TODO: add input validation

	int x, y, year;
	SEMESTER sem;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;
		year = actData.year;
		sem = actData.sem;

		graphicsInfo gInfo{ x, y };

		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		string Title = "Test101";
		Course* pC = new Course(code, Title, crd);
		pC->setGfxInfo(gInfo);

		//TODO: Ask registrar to add course to the year selected by the user
		//TODO: add the course to the correct year obtained from registrar


		double MyPair = year;
		if (sem == FALL) MyPair += 0.1;
		else if (sem == SPRING) MyPair += 0.2;
		else MyPair += 0.3;

		vector <pair <Course_Code, double> > Myvector;
		Myvector.push_back(make_pair(code, MyPair));

		//For the seke of demo, we will add the course to the 1st year, 1st semester
		StudyPlan* pS = pReg->getStudyPlay();
		bool Check_for_pre = pS->checkPre(pC, sem, year, Myvector);
		/*bool Check_for_co = pS->checkCo(pC, sem, year);*/

		pS->AddCourse(pC, year, sem);
	}

	//TODO:

	return true;
}


ActionAddCourse::~ActionAddCourse()
{

}
