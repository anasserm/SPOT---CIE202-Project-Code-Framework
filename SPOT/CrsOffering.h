#pragma once
#include <string>
#include <vector>
using namespace std;

class CrsOffering
{

	string AcademicYear;
	string Semester;
	vector<string> Crss;

public:

	string getYear();
	string getSem();
	vector<string> getCourses();






};

