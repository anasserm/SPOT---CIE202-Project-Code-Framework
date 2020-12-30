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
	double credit;
	double caltimes = 0;
	double totalcal = 0;
	double totalcredit = 0;
	double finalgpa = 0;

	for (int yr = 0; yr < years.size(); yr++)
	{

		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			list<Course*> listCourses = years[yr]->getYearCourses((SEMESTER)sem);
			list<Course*>::iterator it;

			for (it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				pGUI->PrintMsg((*it)->getCode());
				pGUI->PrintMsg("Enter Your grade for this course: ");
				(*it)->setGrade(pGUI->GetSrting());
				int credit = (*it)->getCredits();

				if (lettergrade == "a" || lettergrade == "A")
				{
					caltimes = credit * A;
				}
				else if (lettergrade == "a-" || lettergrade == "A-")
				{
					caltimes = credit * A_MINUS;
				}
				else if (lettergrade == "b+" || lettergrade == "B+")
				{
					caltimes = credit * B_PLUS;
				}
				else if (lettergrade == "b" || lettergrade == "B")
				{
					caltimes = credit * B;
				}
				else if (lettergrade == "b-" || lettergrade == "B-")
				{
					caltimes = credit * B_MINUS;
				}
				else if (lettergrade == "c+" || lettergrade == "C+")
				{
					caltimes = credit * C_PLUS;
				}
				else if (lettergrade == "c" || lettergrade == "C")
				{
					caltimes = credit * C;
				}
				else if (lettergrade == "c-" || lettergrade == "C-")
				{
					caltimes = credit * C_MINUS;
				}
				else if (lettergrade == "d" || lettergrade == "D")
				{
					caltimes = credit * D;
				}
				else if (lettergrade == "f" || lettergrade == "F")
				{
					caltimes = credit * F;
				}
				else
				{
					pGUI->PrintMsg("Invaild Input...");
				}


				totalcredit += credit;
				totalcal += caltimes;


			}
		}
	}

	finalgpa = totalcal / totalcredit;
	pGUI->PrintMsg("your GPA is : ");
	pGUI->PrintMsg(to_string(finalgpa));

	return true;

}

ActionGPA::~ActionGPA()

{
}
