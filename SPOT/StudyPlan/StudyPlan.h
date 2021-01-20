#pragma once
#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"
#include <utility>
#include <list>

//A full study plan for as student
class StudyPlan :public Drawable
{
	int TotalCredits = 0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits = 0, TotalMajorCredits = 0,
		TotalTrackCredits = 0, TotalConcentrationCredits = 0,
		TotalMinorCredits = 0;
	static int numOfCourses;
	vector<AcademicYear*> plan;	//plan is a vector of academic years

	string PlanNotes;
public:
	StudyPlan();
	bool AddCourse(Course*, int year, SEMESTER);
	bool checkPre(Course*, SEMESTER, int, vector <pair<Course_Code, double>>);
	// the 4th parameter of the function checkPre() is a vector of pairs. Each element in this vector contains the course_code and a related decimal telling info about the year and semester
	bool checkCo(Course*, SEMESTER, int);
	void virtual DrawMe(GUI*) const;
	vector<AcademicYear*> getPlan();
	int getYearCourses(int year, SEMESTER sem)const;
	virtual ~StudyPlan();
	void setNotes(string);
	int getCredits() const;
	string getNotes();
	int getNumOfCourses()const;
};

