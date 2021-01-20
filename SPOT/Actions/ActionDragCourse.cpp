#include "ActionDragCourse.h"
#include <iostream>

ActionDragCourse::ActionDragCourse(Registrar*p) :Action(p)
{
}

bool ActionDragCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();

	pGUI->PrintMsg("Enter Course Code: ");
	Course_Code code = pGUI->GetSrting();


	while (!searchCourse(code).found)
	{
		pGUI->PrintMsg("ERROR! Re Enter the course code: ");
		code = pGUI->GetSrting();

	}

	isFound found = searchCourse(code);
	int year = found.year;
	SEMESTER sem = found.sem;
	int index = found.index;
	years[year]->delCourse(index, sem);
	ActionData actData = pGUI->GetUserAction("Select a year to add coures to: ");

	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		year = actData.year;
		sem = actData.sem;
		int count = getnCourses(year, sem);
		int x = semToX(count, sem);
		int y = yearToY(year, count);


		graphicsInfo gInfo{ x, y };

		//TODO: given course code, get course title, crd hours from registrar
		CrsCatalog* cat = pReg->getCrsCatalog();
		vector<Course*> Crss = cat->getCrsCatalog();
		int crd = Crss[index]->getCredits();
		string Title = Crss[index]->getTitle();

		Course* pC = new Course(code, Title, crd);
		pC->setType(Crss[index]->getType());
		pC->setGfxInfo(gInfo);
		sp->AddCourse(pC, year, sem);


	}
	return true;
}

int ActionDragCourse::getnCourses(int year, SEMESTER sem) const
{
	StudyPlan* pS = pReg->getStudyPlay();
	int countCourses = pS->getYearCourses(year, sem);


	return countCourses;
}

int ActionDragCourse::semToX(int count, SEMESTER sem) const
{
	GUI* pGUI = pReg->getGUI();
	int cellWidth = pGUI->getCellWidth();
	return ((int)sem + 1) * cellWidth + ((count % 4) * 75);
}

int ActionDragCourse::yearToY(int year, int count) const
{
	GUI* pGUI = pReg->getGUI();
	int cellHeight = pGUI->getCellHeight();
	int menuBarHight = pGUI->getMenuBarHgight();

	return ((year)*cellHeight + menuBarHight) + (count / 4) * 50;
}




isFound ActionDragCourse::searchCourse(Course_Code code)
{
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();
	int flag = 0;
	int idx = 0, year_idx = 0, sem_idx = 0;

	for (int year = 0; year < years.size(); year++) // loop over years
	{
		sem_idx = 0;
		for (int sem = FALL; sem < SEM_CNT; sem++) // loop over semesters
		{
			idx = 0;
			list<Course*> listCourses = years[year]->getYearCourses((SEMESTER)sem);
			for (list<Course*>::iterator it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				if (code == (*it)->getCode())
				{
					return { true, (SEMESTER)sem_idx, year, idx };
				}
				idx++;
			}
			sem_idx++;
		}
		year_idx++;
	}


	return { false, FALL, -1, -1 };
}

ActionDragCourse::~ActionDragCourse()
{
}
