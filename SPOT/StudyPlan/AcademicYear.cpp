#include "AcademicYear.h"
#include "../GUI/GUI.h"
#include <iostream>

AcademicYear::AcademicYear()
{
	//TODO: make all necessary initializations

}


AcademicYear::~AcademicYear()
{
}

//Adds a course to this year in the spesified semester
bool AcademicYear::AddCourse(Course* pC, SEMESTER sem)
{
	//TODO:
	//This function still needs many checks to be compelete
	YearCourses[sem].push_back(pC);
	TotalCredits += pC->getCredits();

	//TODO: acording to course type incremenet corrsponding toatl hours for that year


	return true;
}

list<Course*> AcademicYear::getYearCourses(SEMESTER sem) 
{
	return YearCourses[sem];
}


void AcademicYear::DrawMe(GUI* pGUI) const
{
	pGUI->DrawAcademicYear(this);
	//Draw all semesters inside this year by iterating on each semester list
	//to get courses and draw each course
	
	for (int sem = FALL; sem < SEM_CNT; sem++)
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			(*it)->DrawMe(pGUI);	//call DrawMe for each course in this semester
		}
}

void AcademicYear::delCourse(int index, SEMESTER sem)
{
	list<Course*>::iterator it = YearCourses[sem].begin();
	advance(it, index);
	YearCourses[sem].erase(it);
}
