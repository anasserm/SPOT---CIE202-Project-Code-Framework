#include "ActionAddCourse.h"
#include "../CrsCatalog.h"
#include "../Courses/Course.h"
#include <iostream>
#include <string>
ActionAddCourse::ActionAddCourse(Registrar* p) :Action(p)
{
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();
	CrsCatalog* pCC = pReg->getCrsCatalog();
	pGUI->PrintMsg("Add Course to plan: Enter course Code (e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();

	
	vector<Course*> Crss = pCC->Courses;
	int jj = 0; int crd; string Title;
	//TODO: add input validation .compare("Sci") != 0
	do
	{
		int j = 0;
		for (auto i = Crss.begin() ; i != Crss.end(); i++, j++)
		{
			if (!code.compare(Crss[j]->getCode()))
			{
				jj++;
				break;
			}
		}
		if (jj == 0)
		{
			pGUI->PrintMsg("Error: wrong course code, please try again:");
			 code = pGUI->GetSrting();
		}
		else
		{
			 crd = Crss[j]->getCredits();
			 Title = Crss[j]->getTitle();
		}



	} while (!jj);
	

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
				
		Course* pC = new Course(code, Title, crd);
		pC->setGfxInfo(gInfo);

		//TODO: Ask registrar to add course to the year selected by the user
		//TODO: add the course to the correct year obtained from registrar

		//For the seke of demo, we will add the course to the 1st year, 1st semester
		StudyPlan* pS = pReg->getStudyPlay();

		double MyPair = year;
		if (sem == FALL) MyPair += 0.1;
		else if (sem == SPRING) MyPair += 0.2;
		else MyPair += 0.3;

		vector <pair <Course_Code, double> > Myvector;
		Myvector.push_back(make_pair(code, MyPair));

		//bool Check_for_pre = pS->checkPre(pC, sem, year, Myvector);
		/*bool Check_for_co = pS->checkCo(pC, sem, year);*/

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
