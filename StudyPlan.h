#pragma once
#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"

//A full study plan for as student
class StudyPlan:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits=0, TotalMajorCredits=0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;
	static int numOfCourses;
	vector<AcademicYear*> plan;	//plan is a vector of academic years

	string PlanNotes;
public:
	StudyPlan();
	bool AddCourse(Course*, int year, SEMESTER);
	void virtual DrawMe(GUI*) const;
	vector<AcademicYear*> getPlan()const;
	virtual ~StudyPlan();
	void setNotes(string);
	int getCredits() const;
	string getNotes();
	int getNumOfCourses()const;
};

