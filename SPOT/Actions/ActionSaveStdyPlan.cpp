#include "ActionSaveStdyPlan.h"

ActionSaveStdyPlan::ActionSaveStdyPlan(Registrar*p) :Action(p)
{
}

bool ActionSaveStdyPlan::Execute()
{
	StudyPlan* sp = pReg->getStudyPlay();
	ofstream outfile, outNotes;
	outfile.open("SAVED_PLAN.txt");
	vector<AcademicYear*> years = sp->getPlan();
	for (int year = 0; year < years.size(); year++)
	{

		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			outfile << "Year " << year + 1 << ",";
			outfile << "Semester " << sem + 1 << ",";

			list<Course*> listCourses = years[year]->getYearCourses((SEMESTER)sem);
			list<Course*>::iterator it;

			for (it = listCourses.begin(); it != listCourses.end(); ++it)
			{
				outfile << (*it)->getCode() << "," ;
			}

			outfile << endl;
		}

	}

	outNotes.open("SAVED_NOTES.txt");
	outNotes << sp->getNotes();

	return true;
}

ActionSaveStdyPlan::~ActionSaveStdyPlan()
{
}
