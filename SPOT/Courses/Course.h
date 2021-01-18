#pragma once
#include <string>
#include <vector>
using namespace std;
#include "..\DEFs.h"

#include "../GUI/Drawable.h"

//Base class for all types of courses
class Course : public Drawable
{
	 Course_Code code;	//course code: e.g. "CIE202". This is the course ID
	 string Title;		//course title: e.g. "Fundamentals of Computer Programming"
	int credits;	//no. of course credits
	string type;	//Univ, track, or major.....etc.
	bool Done;		//Done or not yet?
	string grade;
	vector<Course_Code> PreReq;	//vector of prerequisites
	vector<Course_Code> CoReq;	//vector of corequisites
	
	string status;
public:
	Course(Course_Code r_code,string r_title, int crd);
	string getTitle() const;
	string getCode() const;
	int getCredits() const;
	vector <string> getPreReq();
	vector <string> getCoReq();
	void setCode(Course_Code crs_code);
	string getGrade()const;
	void setStatus(string s) ;
	void setGrade(string grad);
	void DrawMe(GUI*) const;
	virtual ~Course();
	
	
};
