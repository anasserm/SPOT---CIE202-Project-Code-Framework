#include "ActionGPA.h"
#include "..\Registrar.h"

ActionGPA::ActionGPA(Registrar* r):Action(r)
{
}

bool ActionGPA::Execute()
{
	//letter grades
	const double A = 4.0;
	const double A_MINUS = 3.67;
	const double B_PLUS = 3.33;
	const double B = 3.0;
	const double B_MINUS = 2.67;
	const double C_PLUS = 2.33;
	const double C = 2.0;
	const double C_MINUS = 1.67;
	const double D = 1.00;
	const double F = 0.0;

	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	vector<AcademicYear*> years = sp->getPlan();
	int NumOfCrs = sp->getNumOfCourses();
	string lettergrade;
	double credit=0;
	double points = 0;
	double totalPoints = 0;
	double totalcredit = 0;
	double gpa = 0;

	for (int yr = 0; yr < years.size(); yr++)
	{

		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			list<Course*> listCourses = years[yr]->getYearCourses((SEMESTER)sem);
			list<Course*>::iterator it;

			for (it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				lettergrade = (*it)->getGrade();
				if (lettergrade.empty())
				{
					pGUI->PrintMsg((*it)->getCode());
						pGUI->PrintMsg("Enter Your grade for this course: ");
						(*it)->setGrade(pGUI->GetSrting());
				}
				 credit = (*it)->getCredits();

				if (lettergrade == "a" || lettergrade == "A")
				{
					points = credit * A;
				}
				else if (lettergrade == "a-" || lettergrade == "A-")
				{
					points = credit * A_MINUS;
				}
				else if (lettergrade == "b+" || lettergrade == "B+")
				{
					points = credit * B_PLUS;
				}
				else if (lettergrade == "b" || lettergrade == "B")
				{
					points = credit * B;
				}
				else if (lettergrade == "b-" || lettergrade == "B-")
				{
					points = credit * B_MINUS;
				}
				else if (lettergrade == "c+" || lettergrade == "C+")
				{
					points = credit * C_PLUS;
				}
				else if (lettergrade == "c" || lettergrade == "C")
				{
					points = credit * C;
				}
				else if (lettergrade == "c-" || lettergrade == "C-")
				{
					points = credit * C_MINUS;
				}
				else if (lettergrade == "d" || lettergrade == "D")
				{
					points = credit * D;
				}
				else if (lettergrade == "f" || lettergrade == "F")
				{
					points = credit * F;
				}
				
				totalPoints += points;


			}
		}
	}

	gpa = totalPoints / sp->getCredits();
	pGUI->PrintMsg("your GPA is : ");
	pGUI->PrintMsg(to_string(gpa));

	return true;

}

ActionGPA::~ActionGPA()

{
}
