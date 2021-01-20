#pragma once
#include <vector>
#include "StudyPlan/AcademicYear.h"
#include "GUI/Drawable.h"
#include <utility>
#include <list>

class Registrar; //forward class declaration

class Checks
{
	int TotalCredits = 0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits = 0, TotalMajorCredits = 0,
		TotalTrackCredits = 0, TotalConcentrationCredits = 0,
		TotalMinorCredits = 0;
	static int numOfCourses;
	Registrar* pReg;
	vector<AcademicYear*> plan;	//plan is a vector of academic years

public:
	Checks(Registrar* p);
	vector<AcademicYear*> getPlan()const;
	bool CheckCourse(Course*, int year, SEMESTER);
	int getCredits() const;
	int getNumOfCourses()const;

	bool checkPre(Course*, SEMESTER, int, vector <pair<Course_Code, double>>);
	//// the 4th parameter of the function checkPre() is a vector of pairs. Each element in this vector contains the course_code and a related decimal telling info about the year and semester
	bool checkCo(Course*, SEMESTER, int);
	bool checkcredits();

	Checks();
	int FullCheck(bool check_Co, bool check_Pre, int check_credits, int check_ProgReq);
};

