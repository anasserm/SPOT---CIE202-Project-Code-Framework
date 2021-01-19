#include "ActionAddCourse.h"


#include <iostream>
#include <string>
ActionAddCourse::ActionAddCourse(Registrar* p):Action(p)
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

	}


	ActionData actData = pGUI->GetUserAction("Select a year to add coures to: ");
	//TODO: add input validation

	int x, y, year;
	SEMESTER sem;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		int x = actData.x;
		int y = actData.y;
		year = actData.year;
		sem = actData.sem;
		int count = getnCourses(year, sem);
		x = semToX(count, sem);
		y = yearToY(year, count);
		
		graphicsInfo gInfo{ x, y };

		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		string Title = "Test101";
		Course* pC = new Course(code, Title, crd);
		pC->setGfxInfo(gInfo);

		//TODO: Ask registrar to add course to the year selected by the user
		//TODO: add the course to the correct year obtained from registrar

		//For the seke of demo, we will add the course to the 1st year, 1st semester
		StudyPlan* pS = pReg->getStudyPlay();
		pS->AddCourse(pC, year, sem);
		
	}

	
	//TODO:
	

	return true;
}

int ActionAddCourse::getnCourses(int year, SEMESTER sem) const {
	StudyPlan* pS = pReg->getStudyPlay();
	int countCourses = pS->getYearCourses(year, sem);
	

	return countCourses;
}

int ActionAddCourse::semToX(int count, SEMESTER sem) const
{
	GUI* pGUI = pReg->getGUI();
	int cellWidth = pGUI->getCellWidth();
	return ((int)sem + 1) * cellWidth + ((count % 4) * 75);
}

int ActionAddCourse::yearToY(int year, int count) const
{
	GUI* pGUI = pReg->getGUI();
	int cellHeight = pGUI->getCellHeight();
	int menuBarHight = pGUI->getMenuBarHgight();

	return ((year) * cellHeight + menuBarHight) + (count / 4) * 50;
}


ActionAddCourse::~ActionAddCourse()
{
	
}
